#include <iostream>

#define MAX_SIZE 5

int circularArr[MAX_SIZE];
int c_front = -1, c_rear = -1, c_count = 0;

int c_is_empty()
{
    return c_count == 0;
}

int c_is_full()
{
    return c_count == MAX_SIZE;
}

void c_enqueue(int item)
{
    if (c_is_full())
    {
        std::cout << "Queue is full. Cannot enqueue." << std::endl;
        return;
    }
    if (c_is_empty())
    {
        c_front = 0;
    }
    c_rear = (c_rear + 1) % MAX_SIZE;
    circularArr[c_rear] = item;
    c_count++;
}

int c_dequeue()
{
    if (c_is_empty())
    {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        return -1;
    }
    int item = circularArr[c_front];
    c_front = (c_front + 1) % MAX_SIZE;
    c_count--;
    if (c_count == 0)
    {
        c_front = -1;
        c_rear = -1;
    }
    return item;
}

int c_get_front()
{
    if (c_is_empty())
    {
        std::cout << "Queue is empty. No front element." << std::endl;
        return -1;
    }
    return circularArr[c_front];
}

int c_get_rear()
{
    if (c_is_empty())
    {
        std::cout << "Queue is empty. No rear element." << std::endl;
        return -1;
    }
    return circularArr[c_rear];
}

int c_get_size()
{
    return c_count;
}

void c_display_queue()
{
    if (c_is_empty())
    {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    std::cout << "Queue elements: ";
    int i = c_front;
    for (int j = 0; j < c_count; j++)
    {
        std::cout << circularArr[i] << " ";
        i = (i + 1) % MAX_SIZE;
    }
    std::cout << std::endl;
}

int main()
{
    c_enqueue(5);
    c_enqueue(10);
    c_enqueue(15);
    c_display_queue();
    std::cout << "Dequeued element: " << c_dequeue() << std::endl;
    c_enqueue(20);
    c_display_queue();
    return 0;
}
