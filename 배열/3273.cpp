#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, x, count = 0;
    int sequence[100001];

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> sequence[i];
    }

    cin >> x;

    sort(sequence, sequence + N);

    int left = 0, right = N - 1;
    int sum;

    while (left < right)
    {
        sum = sequence[left] + sequence[right];

        if (sum == x)
        {
            count++;
            left++;
            right--;
        }
        else
        {
            if (sum < x)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    cout << count;

    return 0;
}