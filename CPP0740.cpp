#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void test_case(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    ll MAX = a[0];
    for(int i=0;i<n;i++){
        ll ans = 1;
        for(int j=i;j<n;j++){
            ans *= a[j];
            MAX = max(MAX , ans);
        }
    }
    cout << MAX << endl;
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
