#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, count = 0;

    cin >> N;

    while (N--)
    {
        string word;
        stack<char> s;

        cin >> word;

        for (auto i : word)
        {
            if (!s.empty() && s.top() == i)
            {
                s.pop();
            }
            else
            {
                s.push(i);
            }
        }

        if (s.empty())
        {
            count++;
        }
    }

    cout << count;
}