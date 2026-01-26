#include <bits/stdc++.h>

using namespace std;

int N, M;
int ans[10];

void backtrack(int cur)
{
    if (cur == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << ans[i] << ' ';
        }

        cout << '\n';

        return;
    }

    int start = 1;

    if (cur != 0)
    {
        start = ans[cur - 1];
    }

    for (int i = start; i <= N; i++)
    {
        ans[cur] = i;

        backtrack(cur + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    backtrack(0);
}