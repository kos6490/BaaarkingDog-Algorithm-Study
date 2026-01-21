#include <bits/stdc++.h>

using namespace std;

string video[70];

void compress(int N, int x, int y)
{
    int base = N / 2;
    int first = video[x][y];
    bool flag = false;

    for (int i = x; i < x + N; i++)
    {
        for (int j = y; j < y + N; j++)
        {
            if (first != video[i][j])
            {
                flag = true;
            }
        }
    }

    if (flag)
    {
        cout << '(';

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                compress(base, x + (base * i), y + (base * j));
            }
        }

        cout << ')';
    }
    else
    {
        cout << video[x][y];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> video[i];
    }

    compress(N, 0, 0);
}