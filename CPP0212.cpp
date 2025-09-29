#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

void test_case(){
    int n,x;
    cin >> n >> x;
    vector<ll> v;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    ll ans = 1;
    ll p = 0;
    for(int i=0;i<n;i++){
        p = (p + ans*v[n-i-1]) % MOD;
        ans = (ans*(ll)x) % MOD;
    }
    cout << p << endl;
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