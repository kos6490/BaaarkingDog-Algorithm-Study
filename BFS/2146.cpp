#include <bits/stdc++.h>

using namespace std;

int area[101][101];
int vis[101][101];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int N;

void set_area()
{
    int cnt = 2;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (area[i][j] != 1)
            {
                continue;
            }

            queue<pair<int, int>> q2;

            q2.push({ i, j });

            area[i][j] = cnt;

            vis[i][j] = 0;

            while (q2.size())
            {
                auto cur = q2.front();

                q2.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                    {
                        continue;
                    }

                    if (area[nx][ny] != 1)
                    {
                        continue;
                    }

                    q2.push({ nx, ny });

                    area[nx][ny] = cnt;

                    vis[nx][ny] = 0;
                }
            }

            cnt++;
        }
    }
}

int search_bridge()
{
    int ans = 10000;
    queue<tuple<int, int, int>> q1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (area[i][j] != 0)
            {
                q1.push({ i, j, area[i][j] });
            }
        }
    }

    while (q1.size())
    {
        int x, y, num;
        tie(x, y, num) = q1.front();

        q1.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            {
                continue;
            }

            if (area[nx][ny] != 0)
            {
                if (area[nx][ny] != num)
                {
                    ans = min(ans, vis[x][y] + vis[nx][ny]);
                }
            }
            else
            {
                q1.push({ nx, ny, num });

                area[nx][ny] = num;

                vis[nx][ny] = vis[x][y] + 1;
            }
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> area[i][j];
        }
    }

    memset(vis, -1, sizeof(vis));

    set_area();

    cout << search_bridge();
}