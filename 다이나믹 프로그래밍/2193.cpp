#include <bits/stdc++.h>

using namespace std;

int N;
long long int D[100];

void solve()
{
    D[1] = 1;
    D[2] = 1;

    for (int i = 3; i <= N; i++)
        D[i] = D[i - 2] + D[i - 1];

    cout << D[N];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    solve();
}