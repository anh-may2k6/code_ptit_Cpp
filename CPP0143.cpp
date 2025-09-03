#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define Max 93
vector<ll> v;

ll so_fibo(int n){
    int count = Max;
    ll a = 1 , b = 1 , c;
    v.push_back(a);
    v.push_back(b);
    while(count--){
        c = a + b;
        v.push_back(c);
        a = b;
        b = c;
    }
    return v[n-1];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << so_fibo(n) << endl;
    }

    return 0;
}