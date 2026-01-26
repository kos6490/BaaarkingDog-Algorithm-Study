#include <bits/stdc++.h>

using namespace std;

string student[5];
bool picked[25];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int ans = 0;

bool bfs()
{
    int cnt = 1;
    bool vis[5][5] = {
        0,
    };
    queue<pair<int, int>> Q;

    for (int i = 0; i < 25; i++)
    {
        if (picked[i] == true)
        {
            Q.push({ i / 5, i % 5 });
            vis[i / 5][i % 5] = true;

            break;
        }
    }

    while (Q.size())
    {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
            {
                continue;
            }

            if (vis[nx][ny] != 0 || picked[nx * 5 + ny] != true)
            {
                continue;
            }

            Q.push({ nx, ny });
            vis[nx][ny] = true;
            cnt++;
        }
    }

    return cnt == 7;
}

void backtrack(int cur, int start, int cnt)
{
    if (cur == 7)
    {
        if (cnt >= 4)
        {
            if (bfs())
            {
                ans++;
            }
        }

        return;
    }

    for (int i = start; i < 25; i++)
    {
        picked[i] = true;

        int next = (student[i / 5][i % 5] == 'S') ? cnt + 1 : cnt;
        backtrack(cur + 1, i + 1, next);

        picked[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
    {
        cin >> student[i];
    }

    backtrack(0, 0, 0);

    cout << ans;
}