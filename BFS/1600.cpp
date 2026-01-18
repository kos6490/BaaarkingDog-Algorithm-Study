#include <bits/stdc++.h>

using namespace std;

bool area[201][201];
int vis[201][201][31];
int dx[] = { -1, 1, 0, 0, -1, 1, -2, 2, -2, 2, -1, 1 };
int dy[] = { 0, 0, -1, 1, -2, -2, -1, -1, 1, 1, 2, 2 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(vis, -1, sizeof(vis));

    int K, W, H;
    queue<tuple<int, int, int>> Q;

    cin >> K >> W >> H;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> area[i][j];
        }
    }

    Q.push({ 0, 0, K });
    vis[0][0][K] = 0;

    while (Q.size())
    {
        int x, y, jump;

        tie(x, y, jump) = Q.front();
        Q.pop();

        if (x == H - 1 && y == W - 1)
        {
            cout << vis[x][y][jump];

            return 0;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
            {
                continue;
            }

            if (area[nx][ny] == 1 || vis[nx][ny][jump] != -1)
            {
                continue;
            }

            Q.push({ nx, ny, jump });
            vis[nx][ny][jump] = vis[x][y][jump] + 1;
        }

        if (jump > 0)
        {
            for (int dir = 4; dir < 12; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                {
                    continue;
                }

                if (area[nx][ny] == 1 || vis[nx][ny][jump - 1] != -1)
                {
                    continue;
                }

                Q.push({ nx, ny, jump - 1 });
                vis[nx][ny][jump - 1] = vis[x][y][jump] + 1;
            }
        }
    }

    cout << -1;
}