#include <bits/stdc++.h>

using namespace std;

int N, M;
int ans[10];

void backtrack(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << ans[i] << ' ';
        }

        cout << '\n';

        return;
    }

    int start = 1;

    if (k != 0)
    {
        start = ans[k - 1] + 1;
    }

    for (int i = start; i <= N; i++)
    {
        ans[k] = i;

        backtrack(k + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    backtrack(0);
}