#include <bits/stdc++.h>

using namespace std;

bool area[101][101];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int ans[10000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N, K, idx = 0;

    cin >> M >> N >> K;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            area[i][j] = false;
        }
    }

    while (K--)
    {
        int left_x, left_y, right_x, right_y;

        cin >> left_x >> left_y >> right_x >> right_y;

        for (int i = M - right_y; i < M - right_y + (right_y - left_y); i++)
        {
            for (int j = left_x; j < left_x + (right_x - left_x); j++)
            {
                area[i][j] = true;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            queue<pair<int, int>> q;

            if (area[i][j] == false)
            {
                q.push({ i, j });

                area[i][j] = true;

                ans[idx]++;

                while (!q.empty())
                {
                    auto cur = q.front();

                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                        {
                            continue;
                        }

                        if (area[nx][ny] != false)
                        {
                            continue;
                        }

                        q.push({ nx, ny });

                        area[nx][ny] = true;

                        ans[idx]++;
                    }
                }

                idx++;
            }
        }
    }

    sort(ans, ans + idx);

    cout << idx << '\n';

    for (int i = 0; i < idx; i++)
    {
        cout << ans[i] << ' ';
    }
}