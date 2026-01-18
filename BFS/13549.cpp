#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int vis[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    deque<int> D;

    cin >> N >> K;

    fill(vis, vis + MAX, -1);

    D.push_back(N);

    vis[N] = 0;

    while (D.size())
    {
        int cur = D.front();

        D.pop_front();

        if (cur == K)
        {
            cout << vis[cur];

            return 0;
        }

        int next1 = cur * 2;

        if (next1 < MAX && vis[next1] == -1)
        {
            D.push_front(next1);

            vis[next1] = vis[cur];
        }

        for (int next2 : { cur - 1, cur + 1 })
        {
            if (next2 < 0 || next2 >= MAX || vis[next2] != -1)
            {
                continue;
            }

            D.push_back(next2);

            vis[next2] = vis[cur] + 1;
        }
    }
}