#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, count = 0;
    int num[10] = {};

    cin >> N;

    while (N > 0)
    {
        num[N % 10]++;

        N /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        if (i != 6 && i != 9)
        {
            count = max(count, num[i]);
        }
    }

    if (ceil((num[6] + num[9]) / 2.0) > count)
    {
        count = ceil((num[6] + num[9]) / 2.0);
    }

    cout << count;

    return 0;
}