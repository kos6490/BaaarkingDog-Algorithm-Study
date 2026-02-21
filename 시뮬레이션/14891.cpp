#include <bits/stdc++.h>

using namespace std;

string gear[5];
int K, ans;

void rotate(int num, int dir)
{
    int temp;

    if (dir == 1)
    {
        temp = gear[num][7];

        for (int i = 6; i >= 0; i--)
            gear[num][i + 1] = gear[num][i];

        gear[num][0] = temp;
    }
    else
    {
        temp = gear[num][0];

        for (int i = 1; i < 8; i++)
            gear[num][i - 1] = gear[num][i];

        gear[num][7] = temp;
    }
}

void solve(int num, int dir)
{
    int state[3][5] = {};
    int idx1 = num - 1;
    int idx2 = dir;

    state[0][idx1] = true;
    state[1][idx1] = idx2;

    while (idx1 > 0)
    {
        if (gear[idx1][6] == gear[idx1 - 1][2])
            break;

        state[0][idx1 - 1] = true;
        state[1][idx1 - 1] = idx2 * -1;
        idx2 *= -1;
        idx1--;
    }

    idx1 = num - 1;
    idx2 = dir;

    while (idx1 < 3)
    {
        if (gear[idx1][2] == gear[idx1 + 1][6])
            break;

        state[0][idx1 + 1] = true;
        state[1][idx1 + 1] = idx2 * -1;
        idx2 *= -1;
        idx1++;
    }

    for (int i = 0; i < 4; i++)
    {
        if (state[0][i])
            rotate(i, state[1][i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, dir;

    for (int i = 0; i < 4; i++)
        cin >> gear[i];

    cin >> K;

    while (K--)
    {
        cin >> num >> dir;

        solve(num, dir);
    }

    for (int i = 0; i < 4; i++)
        if (gear[i][0] == '1')
            ans += (1 << i);

    cout << ans;
}