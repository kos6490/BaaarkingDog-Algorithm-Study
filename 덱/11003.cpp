#include <bits/stdc++.h>

using namespace std;

int A[5000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, L;
    deque<int> d;

    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];

        while (!d.empty() && A[d.back()] > A[i])
        {
            d.pop_back();
        }

        d.push_back(i);

        if (!d.empty() && d.front() < i - L + 1)
        {
            d.pop_front();
        }

        cout << A[d.front()] << ' ';
    }
}