#include <iostream>

using namespace std;
using ll = long long;

ll GCD(ll a,ll b){
    if(b==0) return a;
    return GCD(b,a%b);
}

ll LCM(ll a,ll b){
    return a/GCD(a,b)*b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    ll n;
    cin >> t;
    while(t--){
        cin >> n;
        ll k =1;
        for(ll i=1;i<=n;i++){
            k = LCM(i,k);
        }
        cout << k << endl;
    }
    return 0;
}