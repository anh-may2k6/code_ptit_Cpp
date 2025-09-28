#include <iostream>

using namespace std;
using ll = long long;

bool tong(int n,ll k){
    ll sum = 0;
    for(int i=1;i<=n;i++){
        sum+=(i%k);
    }
    return sum==k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    ll k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(tong(n,k)){
            cout << "1" << endl;
        }
        else{
            cout << "0" << endl;
        }
    }
    return 0;
}