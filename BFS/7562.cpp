#include <bits/stdc++.h>

using namespace std;

int board[301][301];
int dx[] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int dy[] = { -2, -2, -1, -1, 1, 1, 2, 2 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;

    cin >> T;

    while (T--)
    {
        int I;
        pair<int, int> start, end;
        queue<pair<int, int>> q;

        cin >> I;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;

        for (int i = 0; i < I; i++)
        {
            for (int j = 0; j < I; j++)
            {
                board[i][j] = -1;
            }
        }

        q.push(start);

        board[start.first][start.second] = 0;

        while (!q.empty())
        {
            auto cur = q.front();

            q.pop();

            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= I || ny < 0 || ny >= I)
                {
                    continue;
                }

                if (board[nx][ny] != -1)
                {
                    continue;
                }

                q.push({ nx, ny });

                board[nx][ny] = board[cur.first][cur.second] + 1;
            }
        }

        cout << board[end.first][end.second] << '\n';
    }
}