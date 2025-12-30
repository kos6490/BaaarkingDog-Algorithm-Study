#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int card[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    int a, b, range;

    for (int i = 0; i < 10; i++)
    {
        cin >> a >> b;

        range = (b - a) / 2;

        for (int i = 0; i <= range; i++)
        {
            swap(card[a + i - 1], card[b - i - 1]);
        }
    }

    for (int i = 0; i < 20; i++)
    {
        cout << card[i] << ' ';
    }

    return 0;
}