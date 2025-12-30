#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, time, Y = 0, M = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> time;

        Y += 10 * ((time / 30) + 1);
        M += 15 * ((time / 60) + 1);
    }

    if (Y < M)
    {
        cout << "Y " << Y;
    }
    else if (Y > M)
    {
        cout << "M " << M;
    }
    else
    {
        cout << "Y M " << Y;
    }

    return 0;
}