#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[501][501];
int visit[501][501];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int count = 0, max_size = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ::board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (::visit[i][j] == 1 || ::board[i][j] == 0)
            {
                continue;
            }

            queue<pair<int, int>> q;
            int size = 0;

            count++;

            ::visit[i][j] = 1;

            q.push({ i, j });

            while (!q.empty())
            {
                pair<int, int> cur = q.front();

                q.pop();

                size++;

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    {
                        continue;
                    }

                    if (::visit[nx][ny] == 1 || ::board[nx][ny] == 0)
                    {
                        continue;
                    }

                    ::visit[nx][ny] = 1;

                    q.push({ nx, ny });
                }
            }
            max_size = max(max_size, size);
        }
    }

    cout << count << '\n'
         << max_size;
}