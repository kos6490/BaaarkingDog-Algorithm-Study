#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> point[100001];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> point[i].first >> point[i].second;

    sort(point, point + N, cmp);

    for (int i = 0; i < N; i++)
        cout << point[i].first << ' ' << point[i].second << '\n';
}