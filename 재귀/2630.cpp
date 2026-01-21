#include <bits/stdc++.h>

using namespace std;

int paper[260][260];
int ans[2];

void cut(int N, int x, int y)
{
    int base = N / 2;
    int first = paper[x][y];
    bool flag = false;

    for (int i = x; i < x + N; i++)
    {
        for (int j = y; j < y + N; j++)
        {
            if (first != paper[i][j])
            {
                flag = true;
            }
        }
    }

    if (flag)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cut(base, x + (base * i), y + (base * j));
            }
        }
    }
    else
    {
        ans[paper[x][y]]++;
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

    cout << ans[0] << '\n'
         << ans[1];
}