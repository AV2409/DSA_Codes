#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;

    MinHeapNode(char d, int f)
    {
        data = d;
        freq = f;
        left = right = nullptr;
    }
};
struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};
void generateCodes(MinHeapNode *root, string code, unordered_map<char, string> &huffmanCodes)
{
    if (!root)
        return;
    if (root->data != '#')
        huffmanCodes[root->data] = code;
    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

MinHeapNode *buildHuffmanTree(string text, unordered_map<char, string> &huffmanCodes)
{
    unordered_map<char, int> freqMap;

    for (char c : text)
        freqMap[c]++;

    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

    for (auto pair : freqMap)
    {
        minHeap.push(new MinHeapNode(pair.first, pair.second));
    }

    while (minHeap.size() > 1)
    {
        MinHeapNode *left = minHeap.top();
        minHeap.pop();
        MinHeapNode *right = minHeap.top();
        minHeap.pop();

        MinHeapNode *newNode = new MinHeapNode('#', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        minHeap.push(newNode);
    }

    MinHeapNode *root = minHeap.top();
    generateCodes(root, "", huffmanCodes);
    return root;
}
string encode(string text, unordered_map<char, string> &huffmanCodes)
{
    string encodedStr = "";
    for (char c : text)
    {
        encodedStr += huffmanCodes[c];
    }
    return encodedStr;
}
string decode(MinHeapNode *root, string encodedStr)
{
    string decodedStr = "";
    MinHeapNode *curr = root;

    for (char bit : encodedStr)
    {
        if (bit == '0')
            curr = curr->left;
        else
            curr = curr->right;

        if (!curr->left && !curr->right)
        {
            decodedStr += curr->data;
            curr = root;
        }
    }

    return decodedStr;
}
int main()
{
    string text;
    cout << "Enter the string to encode: ";
    getline(cin, text);

    unordered_map<char, string> huffmanCodes;
    MinHeapNode *root = buildHuffmanTree(text, huffmanCodes);

    cout << "\nHuffman Codes:\n";
    for (auto pair : huffmanCodes)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    string encodedStr = encode(text, huffmanCodes);
    cout << "\nEncoded String: " << encodedStr << endl;

    string decodedStr = decode(root, encodedStr);
    cout << "Decoded String: " << decodedStr << endl;

    return 0;
}
