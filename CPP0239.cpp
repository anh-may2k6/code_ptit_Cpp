#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

int rank_matrix(vector<vector<double>> a) {
    int n = a.size();
    int m = a[0].size();
    int rank = 0;

    for (int col = 0; col < m; col++) {
        // Tìm hàng có phần tử khác 0 lớn nhất (pivot)
        int pivot = rank;
        for (int i = rank; i < n; i++) {
            if (fabs(a[i][col]) > fabs(a[pivot][col]))
                pivot = i;
        }

        // Nếu cột này toàn 0 → bỏ qua
        if (fabs(a[pivot][col]) < EPS) continue;

        // Đưa hàng pivot lên vị trí "rank"
        swap(a[pivot], a[rank]);

        // Chuẩn hóa pivot hàng rank
        double div = a[rank][col];
        for (int j = col; j < m; j++) a[rank][j] /= div;

        // Khử các hàng dưới
        for (int i = 0; i < n; i++) {
            if (i != rank && fabs(a[i][col]) > EPS) {
                double factor = a[i][col];
                for (int j = col; j < m; j++)
                    a[i][j] -= factor * a[rank][j];
            }
        }
        rank++;
    }
    return rank;
}

void test_case(){
    int n, m;
    cin >> n >> m;
    vector<vector<double>> a(n, vector<double>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    cout << rank_matrix(a) << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
