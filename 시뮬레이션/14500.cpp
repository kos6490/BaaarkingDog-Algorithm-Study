#include <bits/stdc++.h>

using namespace std;

bool tetromino[5][4][4] = {
    {
        { 1, 1, 1, 1 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
    },
    {
        { 1, 1, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
    },
    {
        { 1, 0, 0, 0 },
        { 1, 0, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 },
    },
    {
        { 1, 0, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 0, 0, 0 },
    },
    {
        { 1, 1, 1, 0 },
        { 0, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
    }
};
int paper[501][501];
int N, M, ans;

void shift(int n)
{
    int minRow = 4, minCol = 4;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (tetromino[n][i][j])
                minRow = min(minRow, i), minCol = min(minCol, j);

    bool temp[4][4] = {};

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (tetromino[n][i][j])
                temp[i - minRow][j - minCol] = 1;

    memcpy(tetromino + n, temp, sizeof(temp));
}

void rotate(int n)
{
    bool temp[4][4] = {};

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            temp[j][3 - i] = tetromino[n][i][j];

    memcpy(tetromino + n, temp, sizeof(temp));
}

void reverse(int n)
{
    bool temp[4][4] = {};

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            temp[i][3 - j] = tetromino[n][i][j];

    memcpy(tetromino + n, temp, sizeof(temp));
}

int check(int n, int x, int y)
{
    int sum = 0;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (tetromino[n][i][j] == 1)
                if ((x + i >= N || y + j >= M))
                    return 0;
                else
                    sum += paper[x + i][y + j];

    return sum;
}

void solve()
{
    for (int i = 0; i < 5; i++)
    {
        for (int dir = 0; dir < 4; dir++)
        {
            for (int j = 0; j < N; j++)
                for (int k = 0; k < M; k++)
                    ans = max(ans, check(i, j, k));
            rotate(i);
            shift(i);
        }

        reverse(i);
        shift(i);

        for (int dir = 0; dir < 4; dir++)
        {
            for (int j = 0; j < N; j++)
                for (int k = 0; k < M; k++)
                    ans = max(ans, check(i, j, k));
            rotate(i);
            shift(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> paper[i][j];

    solve();

    cout << ans;
}