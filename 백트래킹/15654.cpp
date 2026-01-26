#include <bits/stdc++.h>

using namespace std;

int N, M;
int seq[10];
int ans[10];
bool used[10001];

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

    for (int i = 0; i < N; i++)
    {
        if (!used[seq[i]])
        {
            ans[cur] = seq[i];
            used[seq[i]] = true;

            backtrack(cur + 1);

            used[seq[i]] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> seq[i];
    }

    sort(seq, seq + N);

    backtrack(0);
}