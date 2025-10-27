#include <iostream>
using namespace std;

int n,k;
int a[25][25];
int dem;

void back_track(int row,int col,int sum){
    if(row >= n || col >= n) return;
    sum += a[row][col];
    if(sum > k) return;
    if(row == n-1 && col == n-1){
        if(sum == k){
            dem++;
            return;
        }
    }
    back_track(row+1,col,sum);
    back_track(row,col+1,sum);
}

void test_case(){
    dem = 0;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    back_track(0,0,0);
    cout << dem << endl;
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