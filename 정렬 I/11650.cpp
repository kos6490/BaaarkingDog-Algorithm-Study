#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> point[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> point[i].first >> point[i].second;

    sort(point, point + N);

    for (int i = 0; i < N; i++)
        cout << point[i].first << ' ' << point[i].second << '\n';
}