#include <bits/stdc++.h>

using namespace std;

int box[1001][1001];
int distance[1001][1001];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N, ans = 0;
    queue<pair<int, int>> q;

    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> ::box[i][j];

            if (::box[i][j] == 1)
            {
                q.push({ i, j });
            }

            if (::box[i][j] == 0)
            {
                ::distance[i][j] = -1;
            }
        }
    }

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

            if (::distance[nx][ny] != -1)
            {
                continue;
            }

            q.push({ nx, ny });

            ::distance[nx][ny] = ::distance[cur.first][cur.second] + 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (::distance[i][j] == -1)
            {
                cout << -1;

                return 0;
            }

            ans = max(ans, ::distance[i][j]);
        }
    }

    cout << ans;
}