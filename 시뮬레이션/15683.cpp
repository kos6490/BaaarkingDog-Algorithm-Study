#include <bits/stdc++.h>

using namespace std;

int N, M, ans = 100;
int office[10][10];
vector<tuple<int, int, int>> cctv;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
vector<vector<int>> cctv_dir[] = {
    {},
    { { 0 }, { 1 }, { 2 }, { 3 } },
    { { 0, 1 }, { 2, 3 } },
    { { 0, 3 }, { 1, 3 }, { 1, 2 }, { 0, 2 } },
    { { 0, 2, 3 }, { 0, 1, 3 }, { 1, 2, 3 }, { 0, 1, 2 } },
    { { 0, 1, 2, 3 } }
};

void check()
{
    int cnt = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (office[i][j] == 0)
                cnt++;

    ans = min(ans, cnt);
}

void backtrack(int cur)
{
    if (cur == cctv.size())
    {
        check();

        return;
    }

    int x, y, type;
    tie(x, y, type) = cctv[cur];

    int backup[10][10];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            backup[i][j] = office[i][j];

    for (int i = 0; i < cctv_dir[type].size(); i++)
    {
        for (int dir : cctv_dir[type][i])
        {
            int nx = x;
            int ny = y;

            while (1)
            {
                nx += dx[dir];
                ny += dy[dir];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M || office[nx][ny] == 6)
                    break;

                if (1 <= office[nx][ny] && office[nx][ny] <= 5)
                    continue;

                office[nx][ny] = 7;
            }
        }

        backtrack(cur + 1);

        for (int r = 0; r < N; r++)
            for (int c = 0; c < M; c++)
                office[r][c] = backup[r][c];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> office[i][j];

            if (1 <= office[i][j] && office[i][j] <= 5)
            {
                cctv.push_back({ i, j, office[i][j] });
            }
        }
    }

    backtrack(0);

    cout << ans;
}