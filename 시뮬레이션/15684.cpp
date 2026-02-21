#include <bits/stdc++.h>

using namespace std;

int N, M, H, a, b, ans = 10000;
int board[31][11];

bool check()
{
    int x, y;

    for (int i = 1; i <= N; i++)
    {
        x = 1, y = i;

        while (x != H + 1 && (1 <= y && y <= N))
        {
            if (y > 1 && board[x][y - 1] == 1)
                y--;
            else if (board[x][y] == 1)
                y++;
            x++;
        }

        if (y != i)
            return false;
    }

    return true;
}

void solve(int cur, int start)
{
    if (cur >= ans)
        return;

    if (check())
    {
        ans = cur;
        return;
    }

    if (cur == 3)
        return;

    for (int i = start; i <= H; i++)
        for (int j = 1; j < N; j++)
        {
            if (board[i][j] == 1)
                continue;

            if ((j > 1 && board[i][j - 1] == 1) || board[i][j + 1] == 1)
                continue;

            board[i][j] = 1;
            solve(cur + 1, i);
            board[i][j] = 0;
        }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;

        board[a][b] = 1;
    }

    solve(0, 1);

    if (ans == 10000)
        cout << -1;
    else
        cout << ans;
}