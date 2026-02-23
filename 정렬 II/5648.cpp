#include <bits/stdc++.h>

using namespace std;

int n;
string num[100001];
long long int ans[100001];

long long int pow(int len)
{
    long long int ten = 1;

    for (int i = 0; i < len - 1; i++)
        ten *= 10;

    return ten;
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        long long int tmp = pow(num[i].length());
        long long int cnt = 0;

        for (int j = num[i].length() - 1; j >= 0; j--)
            cnt += (num[i][j] - '0') * tmp, tmp /= 10;

        ans[i] = cnt;
    }

    sort(ans, ans + n);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> num[i];

    solve();

    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';
}