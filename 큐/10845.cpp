#include <bits/stdc++.h>

using namespace std;

int queue[10001];
int front = 0, rear = 0;

int size()
{
    return rear - front;
}

int empty()
{
    return front == rear;
}

void push(int data)
{
    ::queue[rear++] = data;
}

int pop()
{
    if (empty())
    {
        return -1;
    }
    else
    {
        return ::queue[front++];
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
        return ::queue[front];
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
        return ::queue[rear - 1];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, num;
    string command;

    cin >> N;

    while (N--)
    {
        cin >> command;

        if (command == "push")
        {
            cin >> num;

            push(num);
        }
        else if (command == "pop")
        {
            cout << pop() << '\n';
        }
        else if (command == "size")
        {
            cout << size() << '\n';
        }
        else if (command == "empty")
        {
            cout << empty() << '\n';
        }
        else if (command == "front")
        {
            cout << peek_front() << '\n';
        }
        else if (command == "back")
        {
            cout << peek_back() << '\n';
        }
    }
}