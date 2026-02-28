#include <bits/stdc++.h>

using namespace std;

int N;
int D[1000001];

void solve()
{
    for (int i = 2; i <= N; i++)
    {
        if (i % 3 == 0)
            D[i] = !D[i] ? D[i / 3] + 1 : min(D[i], D[i / 3] + 1);

        if (i % 2 == 0)
            D[i] = !D[i] ? D[i / 2] + 1 : min(D[i], D[i / 2] + 1);

        D[i] = !D[i] ? D[i - 1] + 1 : min(D[i], D[i - 1] + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    solve();

    cout << D[N];
}