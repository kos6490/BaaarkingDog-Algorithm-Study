#include <bits/stdc++.h>

using namespace std;

string area[1001];
int vis[1001][1001][11];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    queue<tuple<int, int, int>> Q;

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> area[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k <= K; k++)
            {
                vis[i][j][k] = 1000000;
            }
        }
    }

    Q.push({ 0, 0, 0 });
    vis[0][0][0] = 1;

    while (Q.size())
    {
        int x, y, broken;

        tie(x, y, broken) = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            {
                continue;
            }

            if (area[nx][ny] == '0')
            {
                if (vis[nx][ny][broken] > vis[x][y][broken] + 1)
                {
                    Q.push({ nx, ny, broken });
                    vis[nx][ny][broken] = vis[x][y][broken] + 1;
                }
            }

            if (broken < K && area[nx][ny] == '1')
            {
                if (vis[x][y][broken] % 2 == 1 && vis[nx][ny][broken + 1] > vis[x][y][broken] + 1)
                {
                    Q.push({ nx, ny, broken + 1 });
                    vis[nx][ny][broken + 1] = vis[x][y][broken] + 1;
                }

                if (vis[x][y][broken] % 2 == 0 && vis[nx][ny][broken + 1] > vis[x][y][broken] + 2)
                {
                    Q.push({ nx, ny, broken + 1 });
                    vis[nx][ny][broken + 1] = vis[x][y][broken] + 2;
                }
            }
        }
    }

    int ans = 1000000;

    for (int i = 0; i <= K; i++)
    {
        ans = min(ans, vis[N - 1][M - 1][i]);
    }

    if (ans == 1000000)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}