#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
inline void nhap(vector<vector<int>> &x, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x[i][j];
        }
    }
}

void test_case() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> x(n, vector<int>(m));
    nhap(x, n, m);

    vector<vector<int>> h(3, vector<int>(3));
    nhap(h, 3, 3);

    ll sum = 0;
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            ll conv = 0;
            // Duyệt kernel
            for (int u = 0; u < 3; u++) {
                for (int v = 0; v < 3; v++) {
                    //mỗi phần tử là int nên ta phải ép kiểu ll để tránh bị tràn số
                    conv += (ll)h[u][v] * x[i + u][j + v];
                }
            }
            sum += conv;
        }
    }
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
    return 0;
}