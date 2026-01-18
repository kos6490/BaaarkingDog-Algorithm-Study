#include <bits/stdc++.h>

using namespace std;

char area[1001][1001];
int vis1[1001][1001];
int vis2[1001][1001];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;

    cin >> T;

    while (T--)
    {
        int w, h;
        bool flag = false;
        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;

        memset(vis1, -1, sizeof(vis1));
        memset(vis2, -1, sizeof(vis2));

        cin >> w >> h;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> area[i][j];

                if (area[i][j] == '*')
                {
                    q1.push({ i, j });

                    vis1[i][j] = 0;
                }

                if (area[i][j] == '@')
                {
                    q2.push({ i, j });

                    vis2[i][j] = 0;
                }
            }
        }

        while (!q1.empty())
        {
            auto cur = q1.front();

            q1.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                {
                    continue;
                }

                if (vis1[nx][ny] != -1 || area[nx][ny] == '#' || area[nx][ny] == '*')
                {
                    continue;
                }

                q1.push({ nx, ny });

                vis1[nx][ny] = vis1[cur.first][cur.second] + 1;
            }
        }

        while (!q2.empty())
        {
            auto cur = q2.front();

            q2.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                {
                    cout << vis2[cur.first][cur.second] + 1 << '\n';

                    flag = true;

                    break;
                }

                if (vis2[nx][ny] != -1 || area[nx][ny] != '.')
                {
                    continue;
                }

                if (vis1[nx][ny] != -1 && vis1[nx][ny] <= vis2[cur.first][cur.second] + 1)
                {
                    continue;
                }

                q2.push({ nx, ny });

                vis2[nx][ny] = vis2[cur.first][cur.second] + 1;
            }

            if (flag)
            {
                break;
            }
        }

        if (!flag)
        {
            cout << "IMPOSSIBLE\n";
        }
    }
}