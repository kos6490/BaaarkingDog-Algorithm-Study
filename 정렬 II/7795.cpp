#include <bits/stdc++.h>

using namespace std;

int T, N, M;
int A[20001], B[20001];

bool cmp(int a, int b)
{
    return b < a;
}

void solve()
{
    int cnt = 0;

    sort(A, A + N, cmp);
    sort(B, B + M);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (A[i] <= B[j])
                break;
            else
                cnt++;

    cout << cnt << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> N >> M;

        for (int i = 0; i < N; i++)
            cin >> A[i];

        for (int i = 0; i < M; i++)
            cin >> B[i];

        solve();
    }
}