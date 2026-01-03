#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, H;
    long long int count = 0;
    stack<int> s;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> H;

        while (!s.empty() && s.top() <= H)
        {
            s.pop();
        }

        count += s.size();

        s.push(H);
    }

    cout << count;
}