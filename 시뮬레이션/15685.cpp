#include <bits/stdc++.h>

using namespace std;

bool board[101][101];
int N, x, y, d, g, ans;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

bool check(int x, int y)
{
    return board[y][x] && board[y + 1][x] && board[y][x + 1] && board[y + 1][x + 1];
}

void solve()
{
    for (int y = 0; y < 100; y++)
        for (int x = 0; x < 100; x++)
            if (check(y, x))
                ans++;
}

void dragonCurve()
{
    vector<int> dir;
    dir.push_back(d);

    for (int i = 0; i < g; i++)
        for (int k = dir.size() - 1; k >= 0; k--)
            dir.push_back((dir[k] + 1) % 4);

    board[y][x] = true;

    for (int idx : dir)
    {
        x += dx[idx];
        y += dy[idx];
        board[y][x] = true;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--)
    {
        cin >> x >> y >> d >> g;

        dragonCurve();
    }

    solve();

    cout << ans;
}