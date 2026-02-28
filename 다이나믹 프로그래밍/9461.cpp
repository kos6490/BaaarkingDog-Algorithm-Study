#include <bits/stdc++.h>

using namespace std;

int T, N;
long long int P[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };

void solve()
{
    for (int i = 11; i <= 100; i++)
        P[i] = P[i - 5] + P[i - 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    cin >> T;

    while (T--)
    {
        cin >> N;
        cout << P[N] << '\n';
    }
}