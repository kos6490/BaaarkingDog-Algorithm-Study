#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int height[9];
    int result[7];
    int sum;

    for (int i = 0; i < 9; i++)
    {
        cin >> height[i];
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            sum = 0;

            for (int k = 0, l = 0; k < 9; k++)
            {
                if (k != i && k != j)
                {
                    sum += height[k];

                    result[l++] = height[k];
                }
            }

            if (sum == 100)
            {
                sort(result, result + 7);

                for (int m = 0; m < 7; m++)
                {
                    cout << result[m] << "\n";
                }

                return 0;
            }
        }
    }
}