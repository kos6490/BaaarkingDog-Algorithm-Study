#include <bits/stdc++.h>

using namespace std;

int N, S;
int seq[25];
int ans = 0;

void sum(int cur, int total)
{
    if (cur == N)
    {
        if (S == total)
        {
            ans++;
        }

        return;
    }

    sum(cur + 1, total);
    sum(cur + 1, total + seq[cur]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        cin >> seq[i];
    }

    sum(0, 0);

    if (S == 0)
    {
        ans--;
    }

    cout << ans;
}