#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to check if two numbers are reverse of each other
bool isReverse(int a, int b)
{
    int reversed = 0;
    int original = b;
    while (b > 0)
    {
        reversed = reversed * 10 + (b % 10);
        b /= 10;
    }
    return a == reversed;
}

// Function to find and print all triplets in the linked list
void findTriplets(Node *head)
{
    Node *currentA = head;
    Node *currentB;
    bool found = false;

    while (currentA)
    {
        currentB = currentA->next;
        while (currentB)
        {
            // Skip same node comparison
            if (currentA != currentB && isReverse(currentA->data, currentB->data))
            {
                int c = currentB->data - currentA->data;
                cout << "(" << currentA->data << ", " << currentB->data << ", " << c << ")\n";
                found = true;
            }
            currentB = currentB->next;
        }
        currentA = currentA->next;
    }

    if (!found)
    {
        cout << "No valid triplets found.\n";
    }
}

// Utility function to clean up memory of a linked list
void freeList(Node *head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function
int main()
{
    // Test case 1: Linked list for the first example
    Node *head = new Node(12);
    head->next = new Node(21);
    head->next->next = new Node(33);
    head->next->next->next = new Node(54);
    head->next->next->next->next = new Node(99);
    head->next->next->next->next->next = new Node(45);
    head->next->next->next->next->next->next = new Node(66);
    head->next->next->next->next->next->next->next = new Node(23);
    head->next->next->next->next->next->next->next->next = new Node(32);
    head->next->next->next->next->next->next->next->next->next = new Node(100);
    head->next->next->next->next->next->next->next->next->next->next = new Node(123);
    head->next->next->next->next->next->next->next->next->next->next->next = new Node(321);
    head->next->next->next->next->next->next->next->next->next->next->next->next = new Node(50);
    head->next->next->next->next->next->next->next->next->next->next->next->next->next = new Node(55);

    cout << "Triplets for the first linked list:\n";
    findTriplets(head);

    // Clean up memory for the first list
    freeList(head);

    // Test case 2: Linked list for the second example
    Node *head2 = new Node(123);
    head2->next = new Node(321);
    head2->next->next = new Node(432);
    head2->next->next->next = new Node(234);
    head2->next->next->next->next = new Node(43);
    head2->next->next->next->next->next = new Node(34);
    head2->next->next->next->next->next->next = new Node(44);
    head2->next->next->next->next->next->next->next = new Node(55);
    head2->next->next->next->next->next->next->next->next = new Node(123);
    head2->next->next->next->next->next->next->next->next->next = new Node(321);

    cout << "\nTriplets for the second linked list:\n";
    findTriplets(head2);

    // Clean up memory for the second list
    freeList(head2);

    // Test case 3: Linked list for the third example
    Node *head3 = new Node(1);
    head3->next = new Node(10);
    head3->next->next = new Node(11);
    head3->next->next->next = new Node(110);
    head3->next->next->next->next = new Node(101);
    head3->next->next->next->next->next = new Node(1);
    head3->next->next->next->next->next->next = new Node(11);
    head3->next->next->next->next->next->next->next = new Node(101);

    cout << "\nTriplets for the third linked list:\n";
    findTriplets(head3);

    // Clean up memory for the third list
    freeList(head3);

    return 0;
}
