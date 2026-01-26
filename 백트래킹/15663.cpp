#include <bits/stdc++.h>

using namespace std;

int N, M;
int seq[10];
int ans[10];
bool used[10];

void backtrack(int cur)
{
    if (cur == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << seq[ans[i]] << ' ';
        }

        cout << '\n';

        return;
    }

    int last = -1;

    for (int i = 0; i < N; i++)
    {
        if (!used[i] && last != seq[i])
        {
            ans[cur] = i;
            used[i] = true;
            last = seq[i];

            backtrack(cur + 1);

            used[i] = false;
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