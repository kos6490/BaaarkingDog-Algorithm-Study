#include <bits/stdc++.h>

using namespace std;

string board[11];
int N, M, ans = -1;
pair<int, int> red, blue, dest;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void tilt(int dir)
{
    int cnt1 = 0, cnt2 = 0;
    int rx = red.first, ry = red.second, bx = blue.first, by = blue.second;

    while (board[rx + dx[dir]][ry + dy[dir]] != '#')
    {
        rx += dx[dir];
        ry += dy[dir];
        cnt1++;

        if (board[rx][ry] == 'O')
            break;
    }

    while (board[bx + dx[dir]][by + dy[dir]] != '#')
    {
        bx += dx[dir];
        by += dy[dir];
        cnt2++;

        if (board[bx][by] == 'O')
            break;
    }

    red = { rx, ry };
    blue = { bx, by };

    if (red == blue && red != dest)
        if (cnt1 > cnt2)
            red.first -= dx[dir], red.second -= dy[dir];
        else
            blue.first -= dx[dir], blue.second -= dy[dir];
}

void solve(int cur)
{
    if (cur > 10 || (ans != -1 && cur >= ans))
        return;

    if (blue == dest)
        return;

    if (red == dest)
    {
        if (ans == -1 || cur < ans)
            ans = cur;

        return;
    }

    pair<int, int> backup_red = red, backup_blue = blue;

    for (int dir = 0; dir < 4; dir++)
    {
        tilt(dir);

        if (red != backup_red || blue != backup_blue)
            solve(cur + 1);

        red = backup_red, blue = backup_blue;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> board[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j] == 'R')
                red = { i, j }, board[i][j] = '.';
            else if (board[i][j] == 'B')
                blue = { i, j }, board[i][j] = '.';
            else if (board[i][j] == 'O')
                dest = { i, j };

    solve(0);

    cout << ans;
}