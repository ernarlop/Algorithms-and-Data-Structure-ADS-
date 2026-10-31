#include <bits/stdc++.h>
using namespace std;

struct Student {
    string last, first;
    double gpa;
};

// smaller GPA first; if GPA is equal -> by last name, then by first name
bool cmp(const Student& a, const Student& b) {
    if (a.gpa != b.gpa) return a.gpa < b.gpa;
    if (a.last != b.last) return a.last < b.last;
    return a.first < b.first;
}

int main() {
    map<string, double> point = {{"A+", 4}, {"A", 3.75}, {"B+", 3.5}, {"B", 3},
                                 {"C+", 2.5}, {"C", 2}, {"D+", 1.5}, {"D", 1}, {"F", 0}};
    int n;
    cin >> n;
    vector<Student> v(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> v[i].last >> v[i].first >> m;
        double sum = 0, credits = 0;
        for (int j = 0; j < m; j++) {
            string mark;
            int c;
            cin >> mark >> c;
            sum += point[mark] * c;
            credits += c;
        }
        v[i].gpa = sum / credits;
    }

    sort(v.begin(), v.end(), cmp);

    cout << fixed << setprecision(3);
    for (int i = 0; i < n; i++)
        cout << v[i].last << " " << v[i].first << " " << v[i].gpa << "\n";
}
