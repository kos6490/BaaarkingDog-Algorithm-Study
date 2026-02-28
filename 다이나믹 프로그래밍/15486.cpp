#include <bits/stdc++.h>

using namespace std;

int N;
long long int T[1500001], P[1500001], D[1500001];

void solve()
{
    for (int i = N; i >= 1; i--)
        if (i + T[i] - 1 > N)
            D[i] = D[i + 1];
        else
            D[i] = max(D[i + 1], P[i] + D[i + T[i]]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> T[i] >> P[i];

    solve();

    cout << D[1];
}