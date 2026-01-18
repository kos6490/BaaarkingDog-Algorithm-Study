#include <bits/stdc++.h>

using namespace std;

int dist[100001];
int track[100001];
int path[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, parent, idx = 0;
    queue<int> Q;

    cin >> N >> K;

    fill(dist, dist + 100001, -1);

    Q.push(N);
    dist[N] = 0;

    while (dist[K] == -1)
    {
        int cur = Q.front();
        Q.pop();

        for (int next : { cur - 1, cur + 1, cur * 2 })
        {
            if (next < 0 || next > 100000)
            {
                continue;
            }

            if (dist[next] != -1)
            {
                continue;
            }

            Q.push(next);
            dist[next] = dist[cur] + 1;
            track[next] = cur;
        }
    }

    parent = K;

    path[idx++] = K;

    while (parent != N)
    {
        path[idx++] = track[parent];

        parent = track[parent];
    }

    cout << dist[K] << '\n';

    while (idx--)
    {
        cout << path[idx] << ' ';
    }
}