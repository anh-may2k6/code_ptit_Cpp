#include <iostream>

using namespace std;
using ll = long long;

ll tong(int n,ll k){
    ll sum = 0;
    for(int i=1;i<=n;i++){
        sum+=(i%k);
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    ll k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        cout << tong(n,k) << endl;
    }
    return 0;
}