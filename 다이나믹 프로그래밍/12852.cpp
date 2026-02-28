#include <bits/stdc++.h>

using namespace std;

int N;
int D[1000001], backtrack[1000001];

void solve()
{
    D[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        D[i] = D[i - 1] + 1;
        backtrack[i] = i - 1;

        if (i % 2 == 0 && D[i] > D[i / 2] + 1)
        {
            D[i] = D[i / 2] + 1;
            backtrack[i] = i / 2;
        }

        if (i % 3 == 0 && D[i] > D[i / 3] + 1)
        {
            D[i] = D[i / 3] + 1;
            backtrack[i] = i / 3;
        }
    }

    cout << D[N] << '\n';

    while (1)
    {
        cout << N << ' ';

        if (N == 1)
            break;

        N = backtrack[N];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    solve();
}