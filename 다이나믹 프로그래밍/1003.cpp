#include <bits/stdc++.h>

using namespace std;

int T, N;
int zero[41], one[41];

void solve()
{
    zero[0] = 1, one[0] = 0;
    zero[1] = 0, one[1] = 1;

    for (int i = 2; i <= 40; i++)
    {
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    solve();

    while (T--)
    {
        cin >> N;
        cout << zero[N] << ' ' << one[N] << '\n';
    }
}