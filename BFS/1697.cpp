#include <bits/stdc++.h>

using namespace std;

int dist[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    queue<int> q;

    cin >> N >> K;

    for (int i = 0; i < 100001; i++)
    {
        dist[i] = -1;
    }

    q.push(N);

    dist[N] = 0;

    while (dist[K] == -1)
    {
        int cur = q.front();

        q.pop();

        for (int idx : { cur - 1, cur + 1, cur * 2 })
        {
            if (idx < 0 || idx > 100000)
            {
                continue;
            }

            if (dist[idx] != -1)
            {
                continue;
            }

            q.push(idx);

            dist[idx] = dist[cur] + 1;
        }
    }

    cout << dist[K];
}