#include <bits/stdc++.h>

using namespace std;

string maze[101];
int distance[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> maze[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            ::distance[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;

    q.push({ 0, 0 });

    ::distance[0][0] = 1;

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

            if (::distance[nx][ny] != -1 || ::maze[nx][ny] != '1')
            {
                continue;
            }

            q.push({ nx, ny });

            ::distance[nx][ny] = ::distance[cur.first][cur.second] + 1;
        }
    }

    cout << ::distance[N - 1][M - 1];
}