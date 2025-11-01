#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nhap(vector<vector<int>> &a, int n){
    int num = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = num++;
        }
    }
}

void test_case(){
    int n;
    cin >> n;
    n*=4;
    vector<vector<int>> a((n+1), vector<int>(n+1));
    nhap(a, n);

    vector<int> spiral_1, spiral_2;

    // Duyệt từ ngoài vào (ngược chiều cuộn 1)
    int h1 = 0, h2 = n+1 , c1 = 1 , c2 = n;

    while(h1 < h2 && c1 < c2){
        //trên -> dưới ở cột trái
        h1++;
        h2--;
        for(int j = h1; j <= h2; j++){
            spiral_2.push_back(a[j][c1]);
        }
        c1++;
        c2--;
        //trái -> phải ở hàng cuối cùng
        for(int j = c1; j <= c2; j++){
            spiral_2.push_back(a[h2][j]);
        }
        //dưới -> trên ở cột phải
        h2--;
        h1++;
        for(int j = h2; j >= h1; j--){
            spiral_2.push_back(a[j][c2]);
        }
        c2--;
        c1++;
        for(int j = c2; j>= c1; j--){
            spiral_2.push_back(a[h1][j]);
        }
    }

    // Duyệt theo chiều ngược của cuộn 2
    h1 = 0 , h2 = n+1 , c1 = 1 , c2 = n;
    while(h1 < h2 && c1 < c2){
        // Cuộn 2 duyệt ngược lại
        h2--;
        h1++;
        for(int j = h2; j >= h1; j--){
            spiral_1.push_back(a[j][c2]);
        }
        c2--;
        c1++;
        for(int j = c2; j >= c1; j--){
            spiral_1.push_back(a[h1][j]);
        }
        h1++;
        h2--;
        for(int j = h1;j <= h2; j++){
            spiral_1.push_back(a[j][c1]);
        }
        c1++;
        c2--;
        for(int j = c1;j <= c2; j++){
            spiral_1.push_back(a[h2][j]);
        }
    }

    // Vì mình duyệt ngược chiều -> đảo lại để ra hướng đúng đề
    reverse(spiral_1.begin(), spiral_1.end());
    reverse(spiral_2.begin(), spiral_2.end());

    // In theo thứ tự yêu cầu: spiral_1 trước, rồi spiral_2
    for(int x : spiral_1) cout << x << " ";
    cout << "\n";
    for(int x : spiral_2) cout << x << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
