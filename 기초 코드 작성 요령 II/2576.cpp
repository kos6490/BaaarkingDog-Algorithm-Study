#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, min = 100, sum = 0;

    for (int i = 0; i < 7; i++)
    {
        cin >> num;

        if (num % 2 == 1)
        {
            sum += num;

            if (num < min)
            {
                min = num;
            }
        }
    }

    if (sum == 0 && min == 100)
    {
        cout << -1;
    }
    else
    {
        cout << sum << '\n'
             << min;
    }

    return 0;
}