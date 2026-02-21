#include <bits/stdc++.h>

using namespace std;

string field[12];
int ans, pre;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool check()
{
    if (ans == pre)
        return false;

    pre = ans;
    return true;
}

void disappear(bool vis[][7])
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (vis[i][j])
                field[i][j] = '.';
        }
    }
}

bool puyo()
{
    bool flag = false;

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (field[i][j] == '.')
                continue;

            queue<pair<int, int>> Q;
            bool vis[13][7] = {};
            int cnt = 0;

            Q.push({ i, j });
            vis[i][j] = true;
            cnt++;

            while (Q.size())
            {
                auto cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
                        continue;

                    if (vis[nx][ny] || field[i][j] != field[nx][ny])
                        continue;

                    Q.push({ nx, ny });
                    vis[nx][ny] = true;
                    cnt++;
                }
            }

            if (cnt >= 4)
            {
                disappear(vis);
                flag = true;
            }
        }
    }

    return flag;
}

void fall()
{
    for (int i = 10; i >= 0; i--)
    {
        for (int j = 0; j < 6; j++)
        {
            if (field[i][j] != '.')
            {
                int nx = i;

                while (1)
                {
                    if (nx >= 11 || field[nx + 1][j] != '.')
                    {
                        break;
                    }

                    field[nx + 1][j] = field[nx][j];
                    field[nx][j] = '.';
                    nx++;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 12; i++)
        cin >> field[i];

    do
    {
        if (puyo())
            ans++;

        fall();
    } while (check());

    cout << ans;
}