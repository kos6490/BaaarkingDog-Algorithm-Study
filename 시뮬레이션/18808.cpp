#include <bits/stdc++.h>

using namespace std;

int notebook[45][45];
int sticker[15][15];
int N, M, K, R, C, ans;

void rotate()
{
    int temp[15][15] = {
        0,
    };

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            temp[j][R - i - 1] = sticker[i][j];
        }
    }

    memset(sticker, 0, sizeof(sticker));
    memcpy(sticker, temp, sizeof(temp));

    swap(R, C);
}

bool attach(int x, int y)
{
    int temp[45][45];
    memcpy(temp, notebook, sizeof(notebook));

    for (int i = x; i < x + R; i++)
    {
        for (int j = y; j < y + C; j++)
        {
            if (sticker[i - x][j - y] == 0)
            {
                continue;
            }

            if (sticker[i - x][j - y] == 1 && temp[i][j] == 1)
            {
                return false;
            }

            temp[i][j] = sticker[i - x][j - y];
        }
    }

    memcpy(notebook, temp, sizeof(temp));

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    while (K--)
    {
        memset(sticker, 0, sizeof(sticker));

        cin >> R >> C;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> sticker[i][j];
            }
        }

        int flag = true;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j + R <= N; j++)
            {
                for (int l = 0; l + C <= M; l++)
                {
                    if (attach(j, l))
                    {
                        flag = false;
                        break;
                    }
                }

                if (!flag)
                {
                    break;
                }
            }

            if (flag)
            {
                rotate();
            }
            else
            {
                break;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (notebook[i][j] == 1)
            {
                ans++;
            }
        }
    }

    cout << ans;
}