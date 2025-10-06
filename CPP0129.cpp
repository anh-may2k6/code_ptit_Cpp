#include <iostream>

using namespace std;
using ll = long long;


//dùng công thức legendre ep(n!) = [n/p^1] + [n/p^2] +...
void test_case(){
    ll n,p;
    cin >> n >> p;
    ll cnt = 0;
    for(ll pow = p ; pow <= n ; pow *= p){
        cnt += n/pow;
    }
    cout << cnt << endl;
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