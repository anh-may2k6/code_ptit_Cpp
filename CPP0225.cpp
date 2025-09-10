#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(){
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int> (n));
    vector<int> rowSum(n) , colSum(n);
    // tính tổng tất cả các phần tử trong ma trận
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            rowSum[i] += a[i][j];
            colSum[j] += a[i][j];
            ans += a[i][j];
        }
    }
    // tìm xem hàng hay cột nào max rồi nhân n lên là ra tất cả các hàng or cột = nhau rồi - tổng phần tử ban đầu
    int dem = max(*max_element(rowSum.begin(),rowSum.end()),*max_element(colSum.begin(),colSum.end()));
    cout << n*dem - ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}