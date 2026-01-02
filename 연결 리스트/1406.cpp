#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> L;
    list<char>::iterator t = L.begin();

    string str;
    int M;

    cin >> str;

    for (auto i : str)
    {
        L.push_back(i);
    }

    auto cursor = L.end();

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        char command;

        cin >> command;

        if (command == 'P')
        {
            cin >> command;

            L.insert(cursor, command);
        }
        else if (command == 'L')
        {
            if (cursor != L.begin())
            {
                cursor--;
            }
        }
        else if (command == 'D')
        {
            if (cursor != L.end())
            {
                cursor++;
            }
        }
        else if (command == 'B')
        {
            if (cursor != L.begin())
            {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }

    for (auto i : L)
    {
        cout << i;
    }

    return 0;
}