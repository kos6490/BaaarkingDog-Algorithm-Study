#include <bits/stdc++.h>

using namespace std;

int N;
long long int ans;
long long int D[101][10];

void solve()
{
    for (int i = 1; i <= 9; i++)
        D[1][i] = 1;

    for (int i = 2; i <= N; i++)
        for (int j = 0; j <= 9; j++)
            if (j == 0)
                D[i][0] = D[i - 1][1] % 1000000000;
            else if (j == 9)
                D[i][9] = D[i - 1][8] % 1000000000;
            else
                D[i][j] = D[i - 1][j - 1] + D[i - 1][j + 1] % 1000000000;

    for (int i = 0; i <= 9; i++)
        ans += D[N][i] % 1000000000;

    ans %= 1000000000;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    solve();

    cout << ans;
}