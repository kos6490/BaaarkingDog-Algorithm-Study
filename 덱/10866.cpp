#include <bits/stdc++.h>

using namespace std;

#define MAX 5001

int deque[MAX * 2];
int front = MAX, rear = MAX;

int size()
{
    return rear - front;
}

int empty()
{
    return front == rear;
}

void push_front(int data)
{
    ::deque[--front] = data;
}

void push_back(int data)
{
    ::deque[rear++] = data;
}

int pop_front()
{
    if (empty())
    {
        return -1;
    }
    else
    {
        return ::deque[front++];
    }
}

int pop_back()
{
    if (empty())
    {
        return -1;
    }
    else
    {
        return ::deque[--rear];
    }
}

int peek_front()
{
    if (empty())
    {
        return -1;
    }
    else
    {
        return ::deque[front];
    }
}

int peek_back()
{
    if (empty())
    {
        return -1;
    }
    else
    {
        return ::deque[rear - 1];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, num;
    string cmd;

    cin >> N;

    while (N--)
    {
        cin >> cmd;

        if (cmd == "push_front")
        {
            cin >> num;

            push_front(num);
        }
        else if (cmd == "push_back")
        {
            cin >> num;

            push_back(num);
        }
        else if (cmd == "pop_front")
        {
            cout << pop_front() << '\n';
        }
        else if (cmd == "pop_back")
        {
            cout << pop_back() << '\n';
        }
        else if (cmd == "size")
        {
            cout << size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << empty() << '\n';
        }
        else if (cmd == "front")
        {
            cout << peek_front() << '\n';
        }
        else if (cmd == "back")
        {
            cout << peek_back() << '\n';
        }
    }
}