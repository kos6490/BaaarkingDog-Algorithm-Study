#include <bits/stdc++.h>

using namespace std;

char ans[6600][6600];

void star(int N, int x, int y)
{
    int base = N / 3;

    if (N == 3)
    {
        for (int i = x; i < x + 3; i++)
        {
            for (int j = y; j < y + 3; j++)
            {
                if (i == x + 1 && j == y + 1)
                {
                    ans[i][j] = ' ';

                    continue;
                }

                ans[i][j] = '*';
            }
        }
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == 1 && j == 1)
                {
                    for (int k = x + base; k < x + (base * 2); k++)
                    {
                        for (int l = y + base; l < y + (base * 2); l++)
                        {
                            ans[k][l] = ' ';
                        }
                    }

                    continue;
                }

                star(base, x + (base * i), y + (base * j));
            }
        }
    }
}

void print_star(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << ans[i][j];
        }

        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;

    star(N, 0, 0);

    print_star(N);
}