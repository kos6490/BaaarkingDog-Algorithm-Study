#include <bits/stdc++.h>

using namespace std;

char building[31][31][31];
int vis[31][31][31];
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L, R, C;

    while (1)
    {
        cin >> L >> R >> C;

        if (L == 0 && R == 0 && C == 0)
        {
            return 0;
        }

        char input;
        tuple<int, int, int> E;
        queue<tuple<int, int, int>> q;

        memset(vis, -1, sizeof(vis));

        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                for (int k = 0; k < C; k++)
                {
                    cin >> input;

                    building[i][j][k] = input;

                    vis[i][j][k] = -1;

                    if (input == 'S')
                    {
                        q.push({ i, j, k });

                        vis[i][j][k] = 0;
                    }

                    if (input == 'E')
                    {
                        E = { i, j, k };
                    }
                }
            }
        }

        while (q.size())
        {
            auto cur = q.front();

            q.pop();

            for (int dir = 0; dir < 6; dir++)
            {
                int nx = get<1>(cur) + dx[dir];
                int ny = get<2>(cur) + dy[dir];
                int nz = get<0>(cur) + dz[dir];

                if (nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L)
                {
                    continue;
                }

                if (building[nz][nx][ny] == '#' || vis[nz][nx][ny] != -1)
                {
                    continue;
                }

                q.push({ nz, nx, ny });

                vis[nz][nx][ny] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            }
        }

        if (vis[get<0>(E)][get<1>(E)][get<2>(E)] == -1)
        {
            cout << "Trapped!\n";
        }
        else
        {
            cout << "Escaped in " << vis[get<0>(E)][get<1>(E)][get<2>(E)] << " minute(s).\n";
        }
    }
}