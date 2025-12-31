#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count = 0;
    int alphabet[26] = {};
    string A, B;

    cin >> A >> B;

    for (auto c : A)
    {
        alphabet[c - 'a']++;
    }

    for (auto c : B)
    {
        alphabet[c - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] == 0)
        {
            continue;
        }
        else
        {
            if (alphabet[i] < 0)
            {
                count += alphabet[i] * -1;
            }
            else
            {
                count += alphabet[i];
            }
        }
    }

    cout << count;

    return 0;
}