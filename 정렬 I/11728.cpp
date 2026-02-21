#include <bits/stdc++.h>

using namespace std;

int N, M, aidx, bidx;
int A[1000001], B[1000001], C[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < M; i++)
        cin >> B[i];

    for (int i = 0; i < N + M; i++)
        if (bidx >= M || (aidx < N && A[aidx] <= B[bidx]))
            C[i] = A[aidx++];
        else if (aidx >= N || (bidx < M && A[aidx] > B[bidx]))
            C[i] = B[bidx++];

    for (int i = 0; i < N + M; i++)
        cout << C[i] << ' ';
}