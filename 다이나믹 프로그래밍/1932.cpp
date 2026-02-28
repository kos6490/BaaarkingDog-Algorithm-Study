#include <bits/stdc++.h>

using namespace std;

int n;
int num[501][501], D[501][501];

void solve()
{
    D[1][1] = num[1][1];

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= n; j++)
            D[i][j] = max(D[i - 1][j - 1], D[i - 1][j]) + num[i][j];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> num[i][j];

    solve();

    cout << *max_element(D[n] + 1, D[n] + n + 1);
}