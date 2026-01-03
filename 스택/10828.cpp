#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    int N, data;
    string command;

    cin >> N;

    while (N--)
    {
        cin >> command;

        if (command == "push")
        {
            cin >> data;

            s.push(data);
        }
        else if (command == "pop")
        {
            if (s.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << s.top() << '\n';

                s.pop();
            }
        }
        else if (command == "size")
        {
            cout << s.size() << '\n';
        }
        else if (command == "empty")
        {
            cout << s.empty() << '\n';
        }
        else if (command == "top")
        {
            if (s.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << s.top() << '\n';
            }
        }
    }

    return 0;
}