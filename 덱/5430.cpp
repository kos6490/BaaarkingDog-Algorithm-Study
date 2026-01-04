#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    string p;
    int n;

    cin >> T;

    while (T--)
    {
        deque<int> d;
        bool is_reversed = false;
        bool is_error = false;
        char trash;
        int num;

        cin >> p >> n;

        cin >> trash;

        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                cin >> num;
                cin >> trash;

                d.push_back(num);
            }
        }
        else
        {
            cin >> trash;
        }

        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == 'R')
            {
                is_reversed = !is_reversed;
            }
            else
            {
                if (!d.empty())
                {
                    if (is_reversed)
                    {
                        d.pop_back();
                    }
                    else
                    {
                        d.pop_front();
                    }
                }
                else
                {
                    cout << "error" << '\n';

                    is_error = true;

                    break;
                }
            }
        }

        if (!is_error)
        {
            if (is_reversed)
            {
                cout << '[';

                while (!d.empty())
                {
                    cout << d.back();

                    d.pop_back();

                    if (!d.empty())
                    {
                        cout << ',';
                    }
                }

                cout << ']' << '\n';
            }
            else
            {
                cout << '[';

                while (!d.empty())
                {
                    cout << d.front();

                    d.pop_front();

                    if (!d.empty())
                    {
                        cout << ',';
                    }
                }

                cout << ']' << '\n';
            }
        }
    }
}