#include <iostream>

using namespace std;
using ll = long long;

ll sum_arr(int a[],int n,int l,int r){
    ll sum = 0;
    for(int i=l-1;i<r;i++){
        sum+=a[i];
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,q,l,r;
    cin >> t;
    while(t--){
        cin >> n >> q;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        while(q--){
            cin >> l >> r;
            cout << sum_arr(a,n,l,r) << endl;
        }
    }
    return 0;
}