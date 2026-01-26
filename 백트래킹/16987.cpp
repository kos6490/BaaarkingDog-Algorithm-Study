#include <bits/stdc++.h>

using namespace std;

int N, ans = 0, cnt = 0;
int egg[10][2];

void backtrack(int cur)
{
    if (cur == N)
    {
        ans = max(ans, cnt);

        return;
    }

    if (egg[cur][0] <= 0 || cnt == N - 1)
    {
        backtrack(cur + 1);

        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (cur == i || egg[i][0] <= 0)
        {
            continue;
        }

        egg[cur][0] -= egg[i][1];
        egg[i][0] -= egg[cur][1];

        if (egg[cur][0] <= 0)
        {
            cnt++;
        }

        if (egg[i][0] <= 0)
        {
            cnt++;
        }

        backtrack(cur + 1);

        if (egg[cur][0] <= 0)
        {
            cnt--;
        }

        if (egg[i][0] <= 0)
        {
            cnt--;
        }

        egg[cur][0] += egg[i][1];
        egg[i][0] += egg[cur][1];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> egg[i][0] >> egg[i][1];
    }

    backtrack(0);

    cout << ans;
}