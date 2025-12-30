#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int A, B;

    cin >> A >> B;

    if (B < A)
    {
        swap(A, B);
    }
    else if (A == B)
    {
        cout << 0;

        return 0;
    }

    cout << B - A - 1 << '\n';

    for (long long int i = A + 1; i < B; i++)
    {
        cout << i << ' ';
    }

    return 0;
}