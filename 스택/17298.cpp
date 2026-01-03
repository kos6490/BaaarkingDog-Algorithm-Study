#include <bits/stdc++.h>

using namespace std;

int ans[1000001];
int A[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    stack<int> s;

    cin >> N;

    fill_n(ans, N, -1);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];

        while (!s.empty() && A[s.top()] < A[i])
        {
            ans[s.top()] = A[i];

            s.pop();
        }

        s.push(i);
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << ' ';
    }
}