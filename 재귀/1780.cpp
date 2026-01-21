#include <bits/stdc++.h>

using namespace std;

int paper[2200][2200];
int ans[3];

void cut(int N, int x, int y)
{
    int base = N / 3;
    int first = paper[x][y];
    bool flag = true;

    for (int i = x; i < x + N; i++)
    {
        for (int j = y; j < y + N; j++)
        {
            if (first != paper[i][j])
            {
                flag = false;
                break;
            }
        }
    }

    if (flag)
    {
        ans[paper[x][y] + 1]++;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cut(base, x + (base * i), y + (base * j));
            }
        }
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
        for (int j = 0; j < N; j++)
        {
            cin >> paper[i][j];
        }
    }

    cut(N, 0, 0);

    for (int i = 0; i < 3; i++)
    {
        cout << ans[i] << '\n';
    }
}