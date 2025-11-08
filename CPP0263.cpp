#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;

void test_case(){
    int n;
    cin >> n;
    vector<vector<ll>> a(n+1,vector<ll> (n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    //tính prefix cho đường chéo chính và đường chép phụ

    vector<vector<ll>> prefix_main(n+2,vector<ll> (n+2));
    vector<vector<ll>> prefix_anti(n+2,vector<ll> (n+2));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //vì i tăng và j tăng nên prefix i-1 j-1
            prefix_main[i][j] = a[i][j] + prefix_main[i-1][j-1];
            //vì i tăng và j giảm nên prefix là i-1 j+1
            prefix_anti[i][j] = a[i][j] + prefix_anti[i-1][j+1]; 
        }
    }

    ll max_value = LLONG_MIN;
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            for(int j=k;j<=n;j++){
                //với mỗi k ta sẽ có mỗi ma trận con có tổng đường chéo chính và đường chéo phụ
                ll sum_main = prefix_main[i][j] - prefix_main[i-k][j-k];

                ll sum_anti = prefix_anti[i][j-k+1] - prefix_anti[i-k][j+1];

                max_value = max(max_value , sum_main - sum_anti);
            }
        }
    }
    cout << max_value << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    test_case();
    return 0;
}