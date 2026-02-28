#include <bits/stdc++.h>

using namespace std;

int n;
int seq[100001];
int D[100001];

void solve()
{
    D[0] = seq[0];

    for (int i = 1; i <= n; i++)
        D[i] = max(D[i - 1] + seq[i], seq[i]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> seq[i];

    solve();

    cout << *max_element(D, D + n);
}