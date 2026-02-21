#include <bits/stdc++.h>

using namespace std;

int board[101][101];
int N, K, L, x, y, dir, idx, ans;
int X[101];
char C[101];
deque<pair<int, int>> D;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void solve()
{
    board[x][y] = 1;
    D.push_back({ x, y });

    while (1)
    {
        ans++;

        x += dx[dir];
        y += dy[dir];

        if (x < 0 || x >= N || y < 0 || y >= N || board[x][y] == 1)
            break;

        if (board[x][y] != 2)
        {
            int tail_x, tail_y;
            tie(tail_x, tail_y) = D.front();
            D.pop_front();
            board[tail_x][tail_y] = 0;
        }

        board[x][y] = 1;
        D.push_back({ x, y });

        if (idx < L && X[idx] <= ans)
        {
            if (C[idx] == 'L')
                dir = (dir + 3) % 4;
            else if (C[idx] == 'D')
                dir = (dir + 1) % 4;
            idx++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < K; i++)
    {
        int r, c;
        cin >> r >> c;
        board[r - 1][c - 1] = 2;
    }

    cin >> L;

    for (int i = 0; i < L; i++)
        cin >> X[i] >> C[i];

    solve();

    cout << ans;
}