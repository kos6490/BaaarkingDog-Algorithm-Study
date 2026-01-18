#include <bits/stdc++.h>

using namespace std;

int area[301][301];
int temp[301][301];
bool vis[301][301];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int N, M;

bool check_bfs()
{
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (vis[i][j] == 0)
            {
                continue;
            }

            cnt++;

            if (cnt >= 2)
            {
                return true;
            }

            queue<pair<int, int>> q;

            q.push({ i, j });

            vis[i][j] = 0;

            while (q.size())
            {
                auto cur = q.front();

                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (vis[nx][ny] == 0)
                    {
                        continue;
                    }

                    q.push({ nx, ny });

                    vis[nx][ny] = 0;
                }
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> area[i][j];
        }
    }

    while (1)
    {
        ans++;

        bool flag = false;

        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (area[i][j] == 0)
                {
                    continue;
                }

                flag = true;

                int cnt = 0;

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if (area[nx][ny] == 0)
                    {
                        cnt++;
                    }
                }

                temp[i][j] = cnt;
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (area[i][j] - temp[i][j] > 0)
                {
                    area[i][j] -= temp[i][j];

                    vis[i][j] = 1;
                }
                else
                {
                    area[i][j] = 0;
                }
            }
        }

        if (check_bfs())
        {
            cout << ans;

            return 0;
        }

        if (!flag)
        {
            cout << 0;

            return 0;
        }
    }
}
