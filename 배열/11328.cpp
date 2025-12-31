#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, flag;
    string A, B;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;

        int alphabet[26] = {};
        flag = 0;

        for (auto c : A)
        {
            alphabet[c - 'a']++;
        }

        if (A.size() != B.size())
        {
            cout << "Impossible" << "\n";

            continue;
        }
        else
        {
            for (int j = 0; j < B.size(); j++)
            {
                if (alphabet[B[j] - 'a'] > 0)
                {
                    alphabet[B[j] - 'a']--;
                }
                else
                {
                    cout << "Impossible" << "\n";

                    flag = 1;

                    break;
                }
            }
        }

        if (flag == 0)
        {
            cout << "Possible" << "\n";
        }
    }

    return 0;
}