#include <bits/stdc++.h>

using namespace std;

int k;
int S[50];
int ans[10];

void backtrack(int cur)
{
    if (cur == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << S[ans[i]] << ' ';
        }

        cout << '\n';

        return;
    }

    int start = 0;

    if (cur != 0)
    {
        start = ans[cur - 1] + 1;
    }

    for (int i = start; i < k; i++)
    {
        ans[cur] = i;

        backtrack(cur + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> k;

        if (k == 0)
        {
            return 0;
        }

        for (int i = 0; i < k; i++)
        {
            cin >> S[i];
        }

        backtrack(0);

        cout << '\n';
    }
}