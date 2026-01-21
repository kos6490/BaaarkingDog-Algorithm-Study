#include <bits/stdc++.h>

using namespace std;

void Hanoi(int A, int B, int N)
{
    if (N == 1)
    {
        cout << A << ' ' << B << '\n';

        return;
    }

    Hanoi(A, 6 - A - B, N - 1);
    cout << A << ' ' << B << '\n';
    Hanoi(6 - A - B, B, N - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;

    cout << (1 << N) - 1 << '\n';
    Hanoi(1, 3, N);
}