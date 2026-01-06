#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ex;
    int count = 0;
    stack<char> s;

    cin >> ex;

    for (int i = 0; i < ex.size(); i++)
    {
        if (ex[i] == '(')
        {
            if (ex[i + 1] == ')')
            {
                count += s.size();

                i++;
            }
            else
            {
                count++;

                s.push(ex[i]);
            }
        }
        else
        {
            s.pop();
        }
    }

    cout << count;
}