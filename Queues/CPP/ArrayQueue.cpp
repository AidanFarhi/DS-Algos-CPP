#include <iostream>
using namespace std;

class ArrayQ
{
    public:
    int capacity;
    int head;
    int tail;
    int *Q;
    ArrayQ(int size)
    {
        capacity = size;
        head = tail = 0;
        Q = new int[size];
    }
    void enqueue(int item);
    int dequeue();
    void display();
    bool full();
    bool empty();
    ~ArrayQ() { delete []Q; }
};

void ArrayQ::enqueue(int item)
{
    if (!full())
    {
        // This enables the queue to be circular
        tail = (tail + 1) % capacity;
        Q[tail] = item;
    }
    else
        cout << "Queue is full." << endl;
}

int ArrayQ::dequeue()
{
    int data = -1;
    if (!empty())
    {
        // This enables the queue to be circular
        head = (head + 1) % capacity;
        data = Q[head];
    }
    else
        cout << "Queue is empty." << endl;
    return data;
}

bool ArrayQ::empty()
{
    return head == tail ? true : false;
}

bool ArrayQ::full()
{
    return tail == capacity - 1 ? true : false;
}

void ArrayQ::display()
{
    for (int i = head+1; i <= tail; i++)
        cout << Q[i] << " ";
    cout << endl;
}

int main()
{
    int buffer;
    cout << "Enter size of Queue: ";
    cin >> buffer;
    ArrayQ *queue = new ArrayQ(buffer);
    printf("Enter number of elements to enqueue: ");
    cin >> buffer;
    int item;
    for (int i = 0; i < buffer; i++)
    {
        cout << "Enter item: ";
        cin >> item;
        queue->enqueue(item);
    }
    cout << "Queue: ";
    queue->display();
    cout << "Enter number of items to dequeue: ";
    cin >> buffer;
    for (int i = 0; i < buffer; i++)
    {
        cout << "Item: " << queue-> dequeue() << endl;
    }
    cout << "After removal: ";
    queue->display();
    queue->~ArrayQ();
}