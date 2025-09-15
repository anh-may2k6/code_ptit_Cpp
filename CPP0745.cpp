#include <iostream>

using namespace std;
using ll = long long;
const ll mod = 1e9+7;

ll so_fibo(int n){
    ll a = 0 , b = 1 , c;
    if(n==0) return a;
    if(n==1) return b;
    while(n > 1){
        c = (a + b) % mod;
        a = b;
        b = c;
        --n;
    }
    return b;
}


void test_case(){
    int n;
    cin >> n;
    cout << so_fibo(n)<< endl;
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