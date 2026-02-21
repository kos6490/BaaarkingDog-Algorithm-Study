#include <bits/stdc++.h>

using namespace std;

int N, M, r, c, d, ans;
int board[51][51];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool check()
{
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = r + dx[dir];
        int ny = c + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;

        if (board[nx][ny] == 0)
            return true;
    }

    return false;
}

void solve()
{
    while (1)
    {
        if (board[r][c] == 0)
            board[r][c] = 2, ans++;

        if (check())
        {
            d = (d + 3) % 4;
            int nx = r + dx[d];
            int ny = c + dy[d];

            if (board[nx][ny] == 0)
                r = nx, c = ny;
        }
        else
        {
            int dir = (d + 2) % 4;
            int nx = r + dx[dir];
            int ny = c + dy[dir];

            if (board[nx][ny] != 1)
                r = nx, c = ny;
            else
                return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> r >> c >> d;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    solve();

    cout << ans;
}