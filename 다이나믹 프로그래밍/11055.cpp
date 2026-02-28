#include <bits/stdc++.h>

using namespace std;

int N;
int A[1001];
int D[1001];

void solve()
{
    D[0] = A[0];

    for (int i = 1; i < N; i++)
    {
        D[i] = A[i];

        for (int j = 0; j < i; j++)
            if (A[j] < A[i])
                D[i] = max(D[i], D[j] + A[i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve();

    cout << *max_element(D, D + N);
}