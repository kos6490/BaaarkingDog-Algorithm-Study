#include <bits/stdc++.h>

using namespace std;

int N, ans = 10000;
int ability[21][21];
bool used[21];

void check()
{
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (used[i] && used[j])
                sum1 += ability[i][j];
            else if (!used[i] && !used[j])
                sum2 += ability[i][j];

    ans = min(ans, abs(sum1 - sum2));
}

void solve(int cur, int start)
{
    if (cur >= N / 2)
    {
        check();
        return;
    }

    for (int i = start; i < N; i++)
        if (!used[i])
        {
            used[i] = true;
            solve(cur + 1, i + 1);
            used[i] = false;
        }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> ability[i][j];

    solve(0, 0);

    cout << ans;
}