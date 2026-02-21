#include <bits/stdc++.h>

using namespace std;

int N, M, info, ans = 10000;
int dist[101];
vector<pair<int, int>> house, chicken;

void check()
{
    int sum = 0;

    for (int i = 0; i < house.size(); i++)
    {
        sum += dist[i];
    }

    ans = min(ans, sum);
}

void cal(int idx)
{
    for (int i = 0; i < house.size(); i++)
    {
        int temp = abs(house[i].first - chicken[idx].first) + abs(house[i].second - chicken[idx].second);

        if (temp < dist[i])
        {
            dist[i] = temp;
        }
    }
}

void backtrack(int cur, int start)
{
    if (cur == M)
    {
        return;
    }

    int backup[101];
    memcpy(backup, dist, sizeof(dist));

    for (int i = start; i < chicken.size(); i++)
    {
        cal(i);
        check();
        backtrack(cur + 1, i + 1);
        memcpy(dist, backup, sizeof(backup));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> info;

            if (info == 1)
                house.push_back({ i, j });
            else if (info == 2)
                chicken.push_back({ i, j });
        }
    }

    fill(dist, dist + house.size(), 10000);

    backtrack(0, 0);

    cout << ans;
}