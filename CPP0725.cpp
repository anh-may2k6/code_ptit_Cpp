#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int MOD = 1e9+7;

// cta ko chia giai thừa luôn mà chuyển nó về từ a/b = a x b^-1;
ll powmod(ll a, ll b){ // tính theo nhị phân 
    ll res = 1;
    while(b>0){
        // nếu b lẻ thì ta chỉ cần * 1 a 
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void test_case(){
    int n,r;
    cin >> n >> r;
    vector<ll> gt(n+1);
    gt[0] = 1;
    for(int i=1;i<=n;i++){
        gt[i] =gt[i-1] *(ll)i % MOD;
    }
    ll tu = gt[n];
    ll mau = gt[r] * gt[n-r] % MOD;
    ll ans = tu * powmod(mau , MOD-2) % MOD;
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}