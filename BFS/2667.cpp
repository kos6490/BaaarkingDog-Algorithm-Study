#include <bits/stdc++.h>

using namespace std;

string area[30];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int ans[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, idx = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> area[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            queue<pair<int, int>> q;

            if (area[i][j] == '1')
            {
                area[i][j] = '0';

                q.push({ i, j });

                ans[idx]++;

                while (!q.empty())
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

                        if (area[nx][ny] != '1')
                        {
                            continue;
                        }

                        area[nx][ny] = '0';

                        q.push({ nx, ny });

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
        cout << ans[i] << '\n';
    }
}