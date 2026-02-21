#include <bits/stdc++.h>

using namespace std;

int N, num;
int cnt[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        cnt[num]++;
    }

    for (int i = 1; i < 10001; i++)
        if (cnt[i])
            while (cnt[i]--)
                cout << i << '\n';
}