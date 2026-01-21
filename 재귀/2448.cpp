#include <bits/stdc++.h>

using namespace std;

char ans[3100][6200];

void init_ans(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * 2; j++)
        {
            ans[i][j] = ' ';
        }
    }
}

void draw_star(int N, int x, int y)
{
    if (N == 3)
    {
        ans[x][y] = '*';

        ans[x + 1][y - 1] = '*';
        ans[x + 1][y + 1] = '*';

        for (int i = -2; i <= 2; i++)
        {
            ans[x + 2][y + i] = '*';
        }
    }
    else
    {
        int base = N / 2;

        draw_star(base, x, y);
        draw_star(base, x + base, y - base);
        draw_star(base, x + base, y + base);
    }
}

void print_star(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < (N * 2) - 1; j++)
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

    init_ans(N);
    draw_star(N, 0, N - 1);
    print_star(N);
}