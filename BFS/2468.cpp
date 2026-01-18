#include <bits/stdc++.h>

using namespace std;

int area[101][101];
bool vis[101][101];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, ans = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> area[i][j];
        }
    }

    for (int i = 0; i <= 100; i++)
    {
        int count = 0;

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                vis[j][k] = true;

                if (area[j][k] <= i)
                {
                    vis[j][k] = false;
                }
            }
        }

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (vis[j][k] == true)
                {
                    queue<pair<int, int>> q;

                    q.push({ j, k });

                    vis[j][k] = false;

                    count++;

                    while (q.size())
                    {
                        auto cur = q.front();

                        q.pop();

                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];

                            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                            {
                                continue;
                            }

                            if (vis[nx][ny] == false)
                            {
                                continue;
                            }

                            q.push({ nx, ny });

                            vis[nx][ny] = false;
                        }
                    }
                }
            }
        }

        ans = max(ans, count);
    }

    cout << ans;
}