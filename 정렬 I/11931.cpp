#include <bits/stdc++.h>

using namespace std;

int N, num;
int plus[1000001];
int minus[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num;

        if (num >= 0)
            ::plus[num]++;
        else
        {
            num *= -1;
            ::minus[num]++;
        }
    }

    for (int i = 1000000; i >= 0; i--)
        if (::plus[i])
            while (::plus[i]--)
                cout << i << '\n';

    for (int i = 1; i < 1000001; i++)
        if (::minus[i])
            while (::minus[i]--)
                cout << '-' << i << '\n';
}