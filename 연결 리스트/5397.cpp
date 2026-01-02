#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int n;

    cin >> n;

    while (n--)
    {
        cin >> str;

        list<char> L;
        auto cursor = L.begin();

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '<')
            {
                if (cursor != L.begin())
                {
                    cursor--;
                }
            }
            else if (str[i] == '>')
            {
                if (cursor != L.end())
                {
                    cursor++;
                }
            }
            else if (str[i] == '-')
            {
                if (cursor != L.begin())
                {
                    cursor--;

                    cursor = L.erase(cursor);
                }
            }
            else if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z') || ('0' <= str[i] && str[i] <= '9'))
            {
                L.insert(cursor, str[i]);
            }
        }

        for (auto i : L)
        {
            cout << i;
        }

        cout << '\n';
    }

    return 0;
}