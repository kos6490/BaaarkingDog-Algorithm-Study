#include <bits/stdc++.h>

using namespace std;

int team[100001];
int ans[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n;

    cin >> T;

    while (T--)
    {
        int cnt = 0;

        fill(ans, ans + 100001, 0);

        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> team[i];
        }

        for (int i = 1; i <= n; i++)
        {
            if (ans[i] != 0)
            {
                continue;
            }

            bool iscycle = false;
            int cur = team[i];

            test[i] = 1;

            for (int j = 0; j < n; j++)
            {
                if (cur == i)
                {
                    iscycle = true;

                    break;
                }

                test[cur] = 1;

                cur = team[cur];
            }

            if (iscycle)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (test[j] == 1)
                    {
                        ans[j] = 1;
                    }
                }
            }
        }

        cout << cnt << '\n';
    }
}