#include <bits/stdc++.h>

using namespace std;

string maze[1001];
int dist1[1001][1001];
int dist2[1001][1001];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R, C;
    queue<pair<int, int>> q1, q2;

    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        cin >> maze[i];
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            dist1[i][j] = -1;
            dist2[i][j] = -1;
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (maze[i][j] == 'J')
            {
                q1.push({ i, j });

                dist1[i][j] = 0;
            }

            if (maze[i][j] == 'F')
            {
                q2.push({ i, j });

                dist2[i][j] = 0;
            }
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

            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            {
                continue;
            }

            if (dist2[nx][ny] != -1 || maze[nx][ny] == '#')
            {
                continue;
            }

            q2.push({ nx, ny });

            dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
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

            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            {
                cout << dist1[cur.first][cur.second] + 1;

                return 0;
            }

            if (dist1[nx][ny] != -1 || maze[nx][ny] != '.')
            {
                continue;
            }

            if (dist2[nx][ny] != -1 && dist2[nx][ny] <= dist1[cur.first][cur.second] + 1)
            {
                continue;
            }

            q1.push({ nx, ny });

            dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
        }
    }

    cout << "IMPOSSIBLE";
}