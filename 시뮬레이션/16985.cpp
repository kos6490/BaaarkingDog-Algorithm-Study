#include <bits/stdc++.h>

using namespace std;

int board[5][5][5];
int maze[5][5][5];
int vis[5][5][5];
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };
vector<int> seq = { 0, 1, 2, 3, 4 };
int ans = -1;

void rotate(int z, int n)
{
    int temp[5][5];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                temp[k][4 - j] = maze[z][j][k];
            }
        }

        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                maze[z][j][k] = temp[j][k];
            }
        }
    }
}

void bfs()
{
    queue<tuple<int, int, int>> Q;
    memset(vis, -1, sizeof(vis));

    Q.push({ 0, 0, 0 });
    vis[0][0][0] = 0;

    while (Q.size())
    {
        int x, y, z;
        tie(z, x, y) = Q.front();
        Q.pop();

        if (x == 4 && y == 4 && z == 4)
        {
            if (ans == -1)
                ans = vis[z][x][y];
            else
                ans = min(ans, vis[z][x][y]);

            break;
        }

        for (int dir = 0; dir < 6; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5)
                continue;

            if (vis[nz][nx][ny] != -1 || maze[nz][nx][ny] == 0)
                continue;

            Q.push({ nz, nx, ny });
            vis[nz][nx][ny] = vis[z][x][y] + 1;
        }
    }
}

void setRotation(int cur)
{
    if (cur == 5)
    {
        if (maze[0][0][0])
            bfs();

        return;
    }

    int backup[5][5][5];
    memcpy(backup, maze, sizeof(maze));

    for (int i = 0; i < 4; i++)
    {
        rotate(cur, i);
        setRotation(cur + 1);
        memcpy(maze, backup, sizeof(backup));
    }
}

void copyMaze()
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                maze[i][j][k] = board[seq[i]][j][k];
}

void solve()
{
    do
    {
        copyMaze();
        setRotation(0);
    } while (next_permutation(seq.begin(), seq.end()));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                cin >> board[i][j][k];

    solve();

    cout << ans;
}