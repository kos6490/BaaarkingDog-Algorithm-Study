#include <bits/stdc++.h>

using namespace std;

int N, M, x, y, K, dir;
int board[21][21];
int dice[6];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void rotate()
{
    if (dir == 1)
    {
        swap(dice[3], dice[4]);
        swap(dice[3], dice[5]);
        swap(dice[1], dice[5]);
    }
    else if (dir == 2)
    {
        swap(dice[3], dice[5]);
        swap(dice[3], dice[4]);
        swap(dice[1], dice[4]);
    }
    else if (dir == 3)
    {
        swap(dice[0], dice[1]);
        swap(dice[1], dice[2]);
        swap(dice[2], dice[3]);
    }
    else if (dir == 4)
    {
        swap(dice[0], dice[3]);
        swap(dice[1], dice[3]);
        swap(dice[2], dice[3]);
    }
}

bool solve()
{
    int nx = x + dx[dir - 1];
    int ny = y + dy[dir - 1];

    if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        return false;

    rotate();

    if (board[nx][ny] == 0)
    {
        board[nx][ny] = dice[3];
    }
    else
    {
        dice[3] = board[nx][ny];
        board[nx][ny] = 0;
    }

    x = nx;
    y = ny;

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    while (K--)
    {
        cin >> dir;

        if (solve())
            cout << dice[1] << '\n';
    }
}