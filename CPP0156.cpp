#include <iostream>

using namespace std;
using ll = long long;

ll test(int n , int p){
    ll a = 0;
    for(ll x = 1 ; x < p ; x++){
        if((x * x) % p == 1){
            ll y = x + p * (n / p);
            if(y > n){
                y -= p;
            }
            a += ((y - x) / p + 1);
        }
    }
    return a;
}

void test_case(){
    int b,p;
    cin >> b >> p;
    cout << test(b,p) << "\n";
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