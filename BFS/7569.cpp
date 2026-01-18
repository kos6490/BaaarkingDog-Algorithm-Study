#include <bits/stdc++.h>

using namespace std;

int box[101][101][101];
int vis[101][101][101];
int dx[] = { 0, 0, 0, 0, -1, 1 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 1, -1, 0, 0, 0, 0 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N, H, ans = 0;
    queue<pair<int, pair<int, int>>> q;

    cin >> M >> N >> H;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                vis[i][j][k] = -1;
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> box[i][j][k];

                if (box[i][j][k] == 1)
                {
                    q.push({ i, { j, k } });

                    vis[i][j][k] = 0;
                }
            }
        }
    }

    while (!q.empty())
    {
        auto cur = q.front();

        q.pop();

        for (int dir = 0; dir < 6; dir++)
        {
            int nx = cur.second.first + dx[dir];
            int ny = cur.second.second + dy[dir];
            int nz = cur.first + dz[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
            {
                continue;
            }

            if (vis[nz][nx][ny] != -1 || box[nz][nx][ny] != 0)
            {
                continue;
            }

            q.push({ nz, { nx, ny } });

            vis[nz][nx][ny] = vis[cur.first][cur.second.first][cur.second.second] + 1;
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (vis[i][j][k] == -1 && box[i][j][k] != -1)
                {
                    cout << -1;

                    return 0;
                }

                ans = max(ans, vis[i][j][k]);
            }
        }
    }

    cout << ans;
}