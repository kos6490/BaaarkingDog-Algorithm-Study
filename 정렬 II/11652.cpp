#include <bits/stdc++.h>

using namespace std;

int N, cnt1, cnt2;
long long int num, ans;
long long int card[100001];

void solve()
{
    num = card[0];
    cnt1++;

    for (int i = 1; i < N; i++)
        if (card[i] == num)
            cnt1++;
        else if (cnt2 < cnt1)
            ans = num, cnt2 = cnt1, cnt1 = 1, num = card[i];
        else
            cnt1 = 1, num = card[i];

    if (cnt2 < cnt1)
        ans = card[N - 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> card[i];

    sort(card, card + N);

    solve();

    cout << ans;
}