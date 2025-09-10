#include <bits/stdc++.h>
using namespace std;

void test_case() {
    int n;
    cin >> n;
    vector<int> A1(n), A2(n);
    for (int i = 0; i < n; i++) cin >> A1[i];
    for (int i = 0; i < n; i++) cin >> A2[i];

    unordered_map<int, int> firstPos;
    int diff = 0, ans = 0;

    firstPos[0] = -1; // để xét đoạn bắt đầu từ 0
    for (int i = 0; i < n; i++) {
        diff += A1[i] - A2[i];

        if (firstPos.find(diff) != firstPos.end()) {
            ans = max(ans, i - firstPos[diff]);
        } else {
            firstPos[diff] = i;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
    return 0;
}
