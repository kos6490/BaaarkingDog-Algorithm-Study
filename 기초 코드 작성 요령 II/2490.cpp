#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int info, state;

    for (int i = 0; i < 3; i++)
    {
        state = 0;

        for (int j = 0; j < 4; j++)
        {
            cin >> info;

            if (info == 0)
            {
                state++;
            }
        }

        if (state == 0)
        {
            cout << "E\n";
        }
        else if (state == 1)
        {
            cout << "A\n";
        }
        else if (state == 2)
        {
            cout << "B\n";
        }
        else if (state == 3)
        {
            cout << "C\n";
        }
        else if (state == 4)
        {
            cout << "D\n";
        }
    }

    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int info, state;
//     string result = "DCBAE";

//     for (int i = 0; i < 3; i++)
//     {
//         state = 0;

//         for (int j = 0; j < 4; j++)
//         {
//             cin >> info;

//             state += info;
//         }

//         cout << result[state] << "\n";
//     }

//     return 0;
// }