#include <bits/stdc++.h>

using namespace std;

int N, L, ans;
int board[101][101];
bool ramp[101][101];

void solve()
{
    for (int i = 0; i < N; i++)
    {
        bool flag = true;

        for (int j = 0; j < N - 1; j++)
        {
            if (!flag)
                break;

            if (board[i][j] == board[i][j + 1])
                continue;

            if (abs(board[i][j] - board[i][j + 1]) > 1)
            {
                flag = false;
                break;
            }

            if (board[i][j] - board[i][j + 1] > 0)
            {
                int temp = board[i][j + 1];

                for (int k = j + 1; k < j + L + 1; k++)
                {
                    if (k >= N || ramp[i][k] || board[i][k] != temp)
                    {
                        flag = false;
                        break;
                    }

                    ramp[i][k] = true;
                }

                if (flag)
                    j += (L - 1);
            }

            if (board[i][j] - board[i][j + 1] < 0)
            {
                int temp = board[i][j];

                for (int k = j; k > j - L; k--)
                {
                    if (k < 0 || ramp[i][k] || board[i][k] != temp)
                    {
                        flag = false;
                        break;
                    }

                    ramp[i][k] = true;
                }
            }
        }

        if (flag)
            ans++;
    }

    memset(ramp, false, sizeof(ramp));

    for (int i = 0; i < N; i++)
    {
        bool flag = true;

        for (int j = 0; j < N - 1; j++)
        {
            if (!flag)
                break;

            if (board[j][i] == board[j + 1][i])
                continue;

            if (abs(board[j][i] - board[j + 1][i]) > 1)
            {
                flag = false;
                break;
            }

            if (board[j][i] - board[j + 1][i] > 0)
            {
                int temp = board[j + 1][i];

                for (int k = j + 1; k < j + L + 1; k++)
                {
                    if (k >= N || ramp[k][i] || board[k][i] != temp)
                    {
                        flag = false;
                        break;
                    }

                    ramp[k][i] = true;
                }

                if (flag)
                    j += (L - 1);
            }

            if (board[j][i] - board[j + 1][i] < 0)
            {
                int temp = board[j][i];

                for (int k = j; k > j - L; k--)
                {
                    if (k < 0 || ramp[k][i] || board[k][i] != temp)
                    {
                        flag = false;
                        break;
                    }

                    ramp[k][i] = true;
                }
            }
        }

        if (flag)
            ans++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    solve();

    cout << ans;
}