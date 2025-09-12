//muốn chia dư lũy thừa mà b<10^12 thì ta phải dùng O(log b) để tránh TLE
//ta sẽ dùng chia số nhị phân để tính ra số dư cuối cùng

#include <iostream>

using namespace std;
using ll = long long;

ll modpow(ll x,ll y, ll z){
    ll ans = 1;
    x %= z;
    while(y>0){
        // giống với y%2!=0
        if(y&1) ans = (ans * x) % z;
        //khi mũ chẵn thì ta chỉ việc nhân lại và chia dư là xong
        x = (x * x) % z;
        //dịch chuyển y sang phải 1 đơn vị (vd: 1101 -> 101)
        //giống với y/=2 
        y >>= 1;
    }
    return ans;
}

void test_case(){
    string a;
    cin >> a;
    ll b,m;
    cin >> b >> m;
    int l = a.size();
    ll du = 0;
    for(int i=0;i<l;i++){
        ll num = (a[i] - '0');
        du = (du*10 + num) % m;
    }
    cout << modpow(du,b,m) << endl;
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