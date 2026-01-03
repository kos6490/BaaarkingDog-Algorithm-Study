#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int tower[500001];
    stack<int> s;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> tower[i];

        while (!s.empty() && tower[s.top()] < tower[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            cout << "0 ";
        }
        else
        {
            cout << s.top() << ' ';
        }

        s.push(i);
    }
}