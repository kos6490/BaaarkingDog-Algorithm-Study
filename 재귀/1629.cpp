#include <bits/stdc++.h>

using namespace std;

long long int ans(long long int A, long long int B, long long int C)
{
    if (B == 1)
    {
        return A % C;
    }

    long long int mod = ans(A, B / 2, C);

    mod = mod * mod % C;

    if (B % 2 == 1)
    {
        return mod * A % C;
    }
    else
    {
        return mod;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long int A, B, C;

    cin >> A >> B >> C;

    cout << ans(A, B, C);
}