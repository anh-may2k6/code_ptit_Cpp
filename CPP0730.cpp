#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void test_case(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll ans = -1e9 , max_ans = -1e9;
    for(int i=0;i<n;i++){
        ll tmp = max(ans + a[i] , a[i]);
        ans = tmp;
        max_ans = max(max_ans , ans);
    }
    cout << max_ans << endl;
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