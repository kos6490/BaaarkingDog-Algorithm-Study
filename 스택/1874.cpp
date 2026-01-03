#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, prev = 0, next, idx = 0;
    bool used[100001] = {
        false,
    };
    char result[100000];
    stack<int> s;

    cin >> N;

    while (N--)
    {
        cin >> next;

        if (prev < next)
        {
            for (int i = 1; i <= next; i++)
            {
                if (used[i] == false)
                {
                    s.push(i);
                    used[i] = true;
                    result[idx++] = '+';
                }
            }

            if (s.top() == next)
            {
                s.pop();
                result[idx++] = '-';
            }
            else
            {
                cout << "NO";

                return 0;
            }

            prev = next;
        }
        else
        {
            if (s.top() == next)
            {
                s.pop();
                result[idx++] = '-';
            }
            else
            {
                cout << "NO";

                return 0;
            }
        }
    }

    for (int i = 0; i < idx; i++)
    {
        cout << result[i] << '\n';
    }
}

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int N, cnt = 1;
//     stack<int> s;
//     string ans;

//     cin >> N;

//     while (N--)
//     {
//         int target;

//         cin >> target;

//         while (cnt <= target)
//         {
//             s.push(cnt++);
//             ans += "+\n";
//         }

//         if (s.top() == target)
//         {
//             s.pop();
//             ans += "-\n";
//         }
//         else
//         {
//             cout << "NO";

//             return 0;
//         }
//     }

//     cout << ans;
// }