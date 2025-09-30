#include <iostream>

using namespace std;
using ll = long long;

//khi a*b đưa về a*(b0 + 2b1 + 4b2 ... )
ll mulmod(ll a,ll b, ll c){
    ll ans = 0;
    while(b > 0){
        if(b & 1) ans = (ans + a) % c;
        a = (a + a) % c;
        b >>= 1;
    }
    return ans;
}

void test_case(){
    ll a,b,c;
    cin >> a >> b >> c;
    ll num_1 = a%c;
    ll num_2 = b%c;
    cout << mulmod(num_1,num_2,c) << endl; 
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