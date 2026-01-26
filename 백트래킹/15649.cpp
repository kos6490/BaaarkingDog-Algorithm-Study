#include <bits/stdc++.h>

using namespace std;

int N, M;
int ans[10];
bool used[10];

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

    for (int i = 1; i <= N; i++)
    {
        if (!used[i])
        {
            ans[k] = i;
            used[i] = true;

            backtrack(k + 1);

            used[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    backtrack(0);
}