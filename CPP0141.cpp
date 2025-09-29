#include <iostream>

using namespace std;
using ll = long long;

bool so_fibo(ll n){
    if(n==0) return true;
    ll a = 1,b = 1,c;
    while(b < n){
        c = a + b;
        a = b;
        b = c;
    }
    return (b == n);
}

void test_case(){
    ll n;
    cin >> n;
    if(so_fibo(n)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    cout << endl;
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