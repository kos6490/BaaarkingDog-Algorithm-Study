#include <bits/stdc++.h>

using namespace std;

struct Student
{
    string name;
    int korean;
    int english;
    int math;
};

int N;
Student student[100001];

bool cmp(Student a, Student b)
{
    if (a.korean == b.korean)
    {
        if (a.english == b.english)
        {
            if (a.math == b.math)
            {
                return a.name < b.name;
            }
            return b.math < a.math;
        }
        return a.english < b.english;
    }
    return b.korean < a.korean;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> student[i].name >> student[i].korean >> student[i].english >> student[i].math;

    stable_sort(student, student + N, cmp);

    for (int i = 0; i < N; i++)
        cout << student[i].name << '\n';
}