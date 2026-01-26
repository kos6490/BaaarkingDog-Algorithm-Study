#include <bits/stdc++.h>

using namespace std;

int N, cnt = 0;
bool used1[50];
bool used2[50];
bool used3[50];

void N_Queen(int cur)
{
    if (cur == N)
    {
        cnt++;

        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (used1[i] || used2[i + cur] || used3[cur - i + N - 1])
        {
            continue;
        }

        used1[i] = true;
        used2[i + cur] = true;
        used3[cur - i + N - 1] = true;

        N_Queen(cur + 1);

        used1[i] = false;
        used2[i + cur] = false;
        used3[cur - i + N - 1] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    N_Queen(0);

    cout << cnt;
}