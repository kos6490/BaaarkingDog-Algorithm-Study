#include <bits/stdc++.h>

using namespace std;

int area[51][51];
int vis[51][51];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, M, N, K;
    int x, y;

    cin >> T;

    while (T--)
    {
        int count = 0;
        queue<pair<int, int>> q;
        memset(area, 0, sizeof(area));
        memset(vis, 0, sizeof(vis));

        cin >> M >> N >> K;

        for (int i = 0; i < K; i++)
        {
            cin >> x >> y;

            area[y][x] = 1;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (vis[i][j] == 1 || area[i][j] == 0)
                {
                    continue;
                }

                q.push({ i, j });

                vis[i][j] = 1;

                count++;

                while (!q.empty())
                {
                    auto cur = q.front();

                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                        {
                            continue;
                        }

                        if (vis[nx][ny] == 1 || area[nx][ny] == 0)
                        {
                            continue;
                        }

                        q.push({ nx, ny });

                        vis[nx][ny] = 1;
                    }
                }
            }
        }

        cout << count << '\n';
    }
}