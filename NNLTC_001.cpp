#include <iostream>
using namespace std;

const int MAXLIST = 10000;

typedef struct list {
    int n;
    int nodes[MAXLIST];
} list;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list ds;
    ds.n = 0;

    int x;
    while (cin >> x) {        // đọc cho đến hết input
        ds.nodes[ds.n++] = x;
    }

    bool used[MAXLIST] = {false};
    for (int i = 0; i < ds.n; i++) {
        if (used[i]) continue;
        int cnt = 0;
        for (int j = i; j < ds.n; j++) {
            if (ds.nodes[i] == ds.nodes[j]) {
                cnt++;
                used[j] = true;
            }
        }
        cout << ds.nodes[i] << " " << cnt << "\n";
    }

    return 0;
}
