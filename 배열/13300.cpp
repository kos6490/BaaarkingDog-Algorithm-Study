#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, S, Y;
    int student[2][7] = {};
    int count = 0;

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> S >> Y;

        student[S][Y]++;
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            count += student[i][j] / K;

            if (student[i][j] % K != 0)
            {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}