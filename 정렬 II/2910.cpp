#include <bits/stdc++.h>

using namespace std;

struct Info
{
    int num;
    int cnt;
    int order;
};

int N, C, num, idx;
int cnt[1001];
vector<pair<int, int>> seq;
vector<Info> ans;

void count()
{
    ans.push_back({ seq[0].first, 1, seq[0].second });

    for (int i = 1; i < N; i++)
        if (seq[i].first != ans[idx].num)
            ans.push_back({ seq[i].first, 1, seq[i].second }), idx++;
        else
            ans[idx].cnt++;
}

bool cmp(Info a, Info b)
{
    if (a.cnt == b.cnt)
        return a.order < b.order;
    else
        return b.cnt < a.cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;

    for (int i = 0; i < N; i++)
    {
        cin >> num;

        seq.push_back({ num, i });
    }

    stable_sort(seq.begin(), seq.end());
    count();
    stable_sort(ans.begin(), ans.end(), cmp);

    for (Info num : ans)
        while (num.cnt--)
            cout << num.num << ' ';
}