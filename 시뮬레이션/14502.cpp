#include <bits/stdc++.h>

using namespace std;

int board[10][10];
int N, M, ans;
vector<pair<int, int>> virus;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int check()
{
    int cnt = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j] == 0)
                cnt++;

    return cnt;
}

void bfs()
{
    for (int i = 0; i < virus.size(); i++)
    {
        queue<pair<int, int>> Q;
        Q.push(virus[i]);

        while (Q.size())
        {
            auto cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue;

                if (board[nx][ny] != 0)
                    continue;

                board[nx][ny] = 2;
                Q.push({ nx, ny });
            }
        }
    }
}

void solve(int cur)
{
    if (cur >= 3)
    {
        bfs();
        ans = max(ans, check());
        return;
    }

    int backup[10][10];
    memcpy(backup, board, sizeof(board));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] != 0)
                continue;

            board[i][j] = 1;
            solve(cur + 1);
            memcpy(board, backup, sizeof(backup));
        }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 2)
                virus.push_back({ i, j });
        }

    solve(0);

    cout << ans;
}