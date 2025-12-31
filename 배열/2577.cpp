#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C, sum, n;
    int num[10] = {};

    cin >> A >> B >> C;

    sum = A * B * C;

    while (sum > 0)
    {
        n = sum % 10;

        num[n]++;

        sum /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << num[i] << '\n';
    }

    return 0;
}