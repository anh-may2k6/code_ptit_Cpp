#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;

inline void nhap(vector<vector<int>> &a,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
}

void test_case(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int> (m+1));
    nhap(a,n,m);
    ll res = LLONG_MIN;
    for(int top=0;top<n;top++){
        vector<ll> colSum(m);
        for(int i=top;i<n;i++){ // cửa sổ trượt xuống dưới
            for(int j=0;j<m;j++){
                colSum[j] += a[i][j];
            }
            ll cur = colSum[0] , best = colSum[0];
            for(int j=1;j<m;j++){//cửa sổ trượt sang phải
                cur = max(colSum[j] , cur + colSum[j]);//đây đẫ bao gồm xét 1 phần tử 
                best = max(best , cur);
            }
            res = max(res , best);
        }
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}