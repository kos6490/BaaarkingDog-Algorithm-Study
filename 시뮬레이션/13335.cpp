#include <bits/stdc++.h>

using namespace std;

int n, w, L, idx, cnt;
int truck[1001];
int vis[1001];
int ans;
deque<int> D;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> L;

    for (int i = 0; i < n; i++)
        cin >> truck[i];

    while (idx < n || D.size())
    {
        int temp = 0;

        for (int i = 0; i < D.size(); i++)
        {
            if (vis[D[i]] < w)
            {
                vis[D[i]]++;
            }
            else
            {
                cnt -= truck[D[i]];
                temp++;
            }
        }

        for (int i = 0; i < temp; i++)
        {
            D.pop_front();
        }

        if (idx < n && cnt + truck[idx] <= L)
        {
            D.push_back(idx);
            vis[idx]++;
            cnt += truck[idx];
            idx++;
        }

        ans++;
    }

    cout << ans;
}