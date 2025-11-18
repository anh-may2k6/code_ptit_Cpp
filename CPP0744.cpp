#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void test_case(){
    int n , r , b , g;
    cin >> n >> r >> b >> g;
    //dùng quy hoạch động để tính giai thừa n
    vector<ll> gt(n+1);
    gt[0] = 1;
    for(int i=1;i<=n;i++){
        gt[i] = gt[i-1] * i;
    }

    int l = n - r - b - g;
    ll res = 0;
    //với mỗi trường hợp 0 - l thì ta có tổng các cách chọn để hoán vị
    for(int i=0;i<=l;i++){
        for(int j=0;j<=l-i;j++){
            int k = l - i - j;
            res += (gt[n] / (gt[i + r] * gt[j + b] * gt[k + g]));
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