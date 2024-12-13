#include <iostream>
#include <string>

using namespace std;

// Definition for a singly linked list node
struct ListNode
{
    string value;
    ListNode *next;

    ListNode(string val) : value(val), next(nullptr) {}
};

// Recursive function to find the MCS
int findMCS(ListNode *list1, ListNode *list2, ListNode *list3,
            string result[], int index)
{
    // Base case: If any list is exhausted
    if (list1 == nullptr || list2 == nullptr || list3 == nullptr)
    {
        return index;
    }

    // If the current elements of all three lists match
    if (list1->value == list2->value && list2->value == list3->value)
    {
        result[index] = list1->value; // Add to the result array
        return findMCS(list1->next, list2->next, list3->next, result, index + 1);
    }

    // Explore all three possibilities and find the longest subsequence
    string temp1[100], temp2[100], temp3[100];
    int len1 = findMCS(list1->next, list2, list3, temp1, 0);
    int len2 = findMCS(list1, list2->next, list3, temp2, 0);
    int len3 = findMCS(list1, list2, list3->next, temp3, 0);

    // Choose the longest subsequence
    if (len1 >= len2 && len1 >= len3)
    {
        for (int i = 0; i < len1; i++)
            result[index + i] = temp1[i];
        return index + len1;
    }
    else if (len2 >= len1 && len2 >= len3)
    {
        for (int i = 0; i < len2; i++)
            result[index + i] = temp2[i];
        return index + len2;
    }
    else
    {
        for (int i = 0; i < len3; i++)
            result[index + i] = temp3[i];
        return index + len3;
    }
}

// Main function
int main()
{
    // Create linked lists for the test case
    ListNode *list1 = new ListNode("apple");
    list1->next = new ListNode("banana");
    list1->next->next = new ListNode("cherry");
    list1->next->next->next = new ListNode("date");
    list1->next->next->next->next = new ListNode("elderberry");

    ListNode *list2 = new ListNode("banana");
    list2->next = new ListNode("cherry");
    list2->next->next = new ListNode("elderberry");
    list2->next->next->next = new ListNode("fig");
    list2->next->next->next->next = new ListNode("grape");

    ListNode *list3 = new ListNode("cherry");
    list3->next = new ListNode("banana");
    list3->next->next = new ListNode("elderberry");
    list3->next->next->next = new ListNode("honeydew");

    // Array to hold the MCS
    string mcs[100]; // Assuming a maximum size of 100
    int mcsIndex = 0;

    // Find the MCS
    mcsIndex = findMCS(list1, list2, list3, mcs, 0);

    // Print the MCS
    cout << "Maximum Common Subsequence: ";
    for (int i = 0; i < mcsIndex; i++)
    {
        cout << mcs[i];
        if (i < mcsIndex - 1)
        {
            cout << " → ";
        }
    }
    cout << endl;

    return 0;
}
