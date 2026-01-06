#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        string str;
        stack<char> s;
        bool flag = false;

        getline(cin, str);

        if (str == ".")
        {
            return 0;
        }

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(' || str[i] == '[')
            {
                s.push(str[i]);
            }
            else if (str[i] == ')')
            {
                if (!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    flag = true;

                    break;
                }
            }
            else if (str[i] == ']')
            {
                if (!s.empty() && s.top() == '[')
                {
                    s.pop();
                }
                else
                {
                    flag = true;

                    break;
                }
            }
        }

        if (flag || !s.empty())
        {
            cout << "no\n";
        }
        else
        {
            cout << "yes\n";
        }
    }
}