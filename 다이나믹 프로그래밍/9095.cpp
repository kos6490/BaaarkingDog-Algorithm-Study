#include <bits/stdc++.h>

using namespace std;

int T, n;
int D[12];

void solve()
{
    for (int i = 4; i <= 11; i++)
        D[i] = D[i - 1] + D[i - 2] + D[i - 3];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    D[1] = 1;
    D[2] = 2;
    D[3] = 4;

    solve();

    while (T--)
    {
        cin >> n;
        cout << D[n] << '\n';
    }
}