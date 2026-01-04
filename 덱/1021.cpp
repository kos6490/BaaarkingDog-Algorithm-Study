#include <bits/stdc++.h>

using namespace std;

deque<int> d;

int index(int target)
{
    for (int i = 0; i < d.size(); i++)
    {
        if (d[i] == target)
        {
            return i;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, target, count = 0;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        d.push_back(i);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> target;

        if (d.front() == target)
        {
            d.pop_front();
        }
        else
        {
            if (index(target) <= (d.size() / 2))
            {
                while (d.front() != target)
                {
                    d.push_back(d.front());

                    d.pop_front();

                    count++;
                }
            }
            else
            {
                while (d.front() != target)
                {
                    d.push_front(d.back());

                    d.pop_back();

                    count++;
                }
            }

            d.pop_front();
        }
    }

    cout << count;
}