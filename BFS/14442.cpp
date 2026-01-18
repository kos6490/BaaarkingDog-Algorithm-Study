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

    Q.push({ 0, 0, 0 });

    for (int i = 0; i < K; i++)
    {
        vis[0][0][0] = 1;
    }

    while (Q.size())
    {
        int x, y, broken;

        tie(x, y, broken) = Q.front();
        Q.pop();

        if (x == N - 1 && y == M - 1)
        {
            cout << vis[x][y][broken];

            return 0;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            {
                continue;
            }

            if (area[nx][ny] == '0' && vis[nx][ny][broken] == 0)
            {
                Q.push({ nx, ny, broken });
                vis[nx][ny][broken] = vis[x][y][broken] + 1;
            }

            if (broken < K && area[nx][ny] == '1' && vis[nx][ny][broken + 1] == 0)
            {
                Q.push({ nx, ny, broken + 1 });
                vis[nx][ny][broken + 1] = vis[x][y][broken] + 1;
            }
        }
    }

    cout << -1;
}