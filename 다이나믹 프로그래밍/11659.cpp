#include <bits/stdc++.h>

using namespace std;

int N, M, i, j;
int num[100001], sum[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int k = 1; k <= N; k++)
    {
        cin >> num[k];
        sum[k] = sum[k - 1] + num[k];
    }

    while (M--)
    {
        cin >> i >> j;

        cout << sum[j] - sum[i - 1] << '\n';
    }
}