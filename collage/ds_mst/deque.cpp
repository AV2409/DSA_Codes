#include <iostream>
using namespace std;

#define MAX 5 // Maximum size of the deque

class Deque
{
private:
public:
    int arr[MAX] = {0}; // Array to store deque elements
    int front;          // Index of the front element
    int rear;           // Index of the rear element
    int size;           // Current size of the deque
    Deque()
    {
        front = -1; // Initialize front
        rear = -1;  // Initialize rear
        size = 0;   // Initialize size
    }

    // Function to check if the deque is full
    bool isFull()
    {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    // Function to check if the deque is empty
    bool isEmpty()
    {
        return front == -1;
    }

    // Function to insert an element at the front
    void insertFront(int key)
    {
        if (isFull())
        {
            cout << "Overflow! Cannot insert at front." << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0)
        { // Wrap around
            front = MAX - 1;
        }
        else
        {
            front--;
        }
        arr[front] = key; // Insert current element at front
        size++;
    }

    // Function to insert an element at the rear
    void insertRear(int key)
    {
        if (isFull())
        {
            cout << "Overflow! Cannot insert at rear." << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else if (rear == MAX - 1)
        { // Wrap around
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = key; // Insert current element at rear
        size++;
    }

    // Function to delete an element from the front
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Underflow! Cannot delete from front." << endl;
            return;
        }
        cout << "Deleted: " << arr[front] << endl;
        if (front == rear)
        { // Only one element was present
            front = -1;
            rear = -1;
        }
        else if (front == MAX - 1)
        { // Wrap around
            front = 0;
        }
        else
        {
            front++;
        }
        size--;
    }

    // Function to delete an element from the rear
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Underflow! Cannot delete from rear." << endl;
            return;
        }
        cout << "Deleted: " << arr[rear] << endl;
        if (front == rear)
        { // Only one element was present
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        { // Wrap around
            rear = MAX - 1;
        }
        else
        {
            rear--;
        }
        size--;
    }

    // Function to get the front element
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return -1; // Return an invalid value for empty deque
        }
        return arr[front];
    }

    // Function to get the rear element
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return -1; // Return an invalid value for empty deque
        }
        return arr[rear];
    }

    // Function to display the elements of the deque
    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque elements: ";

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break; // Stop when we reach the last element

            i = (i + 1) % MAX; // Wrap around using modulo operation
        }

        cout << endl;
    }
};

int main()
{
    Deque dq;

    dq.insertRear(20);
    dq.insertRear(45);
    dq.insertRear(18);

    dq.display(); // Display current elements in deque

    dq.deleteFront();
    dq.display();
    dq.insertFront(9);
    dq.insertFront(23);

    dq.deleteRear();

    dq.display();

    cout << endl
         << dq.arr[0] << " " << dq.arr[4];

    return 0;
}