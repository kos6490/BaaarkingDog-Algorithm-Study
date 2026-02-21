#include <bits/stdc++.h>

using namespace std;

struct Member
{
    int age;
    string name;
};

int N;
Member member[100001];

bool cmp(Member a, Member b)
{
    return a.age < b.age;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> member[i].age >> member[i].name;

    stable_sort(member, member + N, cmp);

    for (int i = 0; i < N; i++)
        cout << member[i].age << ' ' << member[i].name << '\n';
}