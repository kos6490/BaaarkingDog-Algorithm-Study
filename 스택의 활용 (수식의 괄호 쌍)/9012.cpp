#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;

    cin >> T;

    while (T--)
    {
        string PS;
        stack<char> s;
        bool flag = false;

        cin >> PS;

        for (auto i : PS)
        {
            if (i == '(')
            {
                s.push(i);
            }
            else if (i == ')' && !s.empty())
            {
                s.pop();
            }
            else
            {
                flag = true;

                break;
            }
        }

        if (!s.empty())
        {
            flag = true;
        }

        if (flag)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}