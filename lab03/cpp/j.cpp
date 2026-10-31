#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> need(n); // сторона квадрата, нужная для i-й овцы
    for (int &v : need) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v = max(x2, y2);
    }
    sort(need.begin(), need.end());
    cout << need[k - 1]; // k-я по величине — минимальная сторона для k овец
}
