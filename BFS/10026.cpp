#include <bits/stdc++.h>

using namespace std;

string picture[101];
int vis[101][101];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int N;

void bfs(int i, int j)
{
    queue<pair<int, int>> q;

    q.push({ i, j });

    vis[i][j] = 1;

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

            if (vis[nx][ny] == 1 || picture[i][j] != picture[nx][ny])
            {
                continue;
            }

            q.push({ nx, ny });

            vis[nx][ny] = 1;
        }
    }
}

int search()
{
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vis[i][j] == 1)
            {
                continue;
            }

            cnt++;

            bfs(i, j);
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt1, cnt2;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> picture[i];
    }

    cnt1 = search();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (picture[i][j] == 'G')
                picture[i][j] = 'R';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vis[i][j] = 0;
        }
    }

    cnt2 = search();

    cout << cnt1 << ' ' << cnt2;
}