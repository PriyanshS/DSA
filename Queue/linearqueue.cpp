#include <iostream>
using namespace std;

#define MAX_SIZE 100

int queueArr[MAX_SIZE];
int front = -1, rear = -1;

int queue_is_empty()
{
    return front == -1;
}

int is_full()
{
    return rear == MAX_SIZE - 1;
}

void enqueue(int item)
{
    if (is_full())
    {
        cout << "Queue is full. Cannot enqueue." << endl;
        return;
    }
    if (queue_is_empty())
    {
        front = 0;
    }
    rear++;
    queueArr[rear] = item;
}

int dequeue()
{
    if (queue_is_empty())
    {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return -1;
    }
    int item = queueArr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return item;
}

int get_front()
{
    if (queue_is_empty())
    {
        cout << "Queue is empty. No front element." << endl;
        return -1;
    }
    return queueArr[front];
}

int get_rear()
{
    if (queue_is_empty())
    {
        cout << "Queue is empty. No rear element." << endl;
        return -1;
    }
    return queueArr[rear];
}

int get_size()
{
    if (queue_is_empty())
    {
        return 0;
    }
    return rear - front + 1;
}

void display_queue()
{
    if (queue_is_empty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
    {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display_queue();
    cout << "Dequeued element: " << dequeue() << endl;
    display_queue();
    return 0;
}