#include <bits/stdc++.h>

using namespace std;

int N, ans;
int board[22][22];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void move(int i, int j, int dir, bool combined[][22])
{
    if (board[i][j] == 0)
        return;

    int cx = i, cy = j;

    while (1)
    {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            break;

        if (board[nx][ny] == 0)
        {
            board[nx][ny] = board[cx][cy];
            board[cx][cy] = 0;
            cx = nx;
            cy = ny;
        }
        else if (board[nx][ny] == board[cx][cy])
        {
            if (combined[nx][ny] || combined[cx][cy])
                break;

            board[nx][ny] *= 2;
            board[cx][cy] = 0;
            combined[nx][ny] = true;
            break;
        }
        else
        {
            break;
        }
    }
}

void backtrack(int cur)
{
    if (cur == 5)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                ans = max(ans, board[i][j]);

        return;
    }

    int backup[22][22], flag = 1;
    memcpy(backup, board, sizeof(board));

    for (int dir = 0; dir < 4; dir++)
    {
        bool combined[22][22] = {
            false,
        };

        if (dir == 0)
        {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    move(i, j, dir, combined);
        }
        else if (dir == 1)
        {
            for (int i = N - 1; i >= 0; i--)
                for (int j = 0; j < N; j++)
                    move(i, j, dir, combined);
        }
        else if (dir == 2)
        {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    move(i, j, dir, combined);
        }
        else if (dir == 3)
        {
            for (int i = 0; i < N; i++)
                for (int j = N - 1; j >= 0; j--)
                    move(i, j, dir, combined);
        }

        backtrack(cur + 1);

        memcpy(board, backup, sizeof(backup));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    backtrack(0);

    cout << ans;
}