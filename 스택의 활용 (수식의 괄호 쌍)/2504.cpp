#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num = 1, ans = 0;
    string str;
    stack<char> s;

    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            num *= 2;

            s.push(str[i]);
        }
        else if (str[i] == '[')
        {
            num *= 3;

            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                cout << 0;

                return 0;
            }

            if (str[i - 1] == '(')
            {
                ans += num;
            }

            num /= 2;

            s.pop();
        }
        else if (str[i] == ']')
        {
            if (s.empty() || s.top() != '[')
            {
                cout << 0;

                return 0;
            }

            if (str[i - 1] == '[')
            {
                ans += num;
            }

            num /= 3;

            s.pop();
        }
    }

    if (s.empty())
    {
        cout << ans;
    }
    else
    {
        cout << 0;
    }
}