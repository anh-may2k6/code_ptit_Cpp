#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        ll a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        vector<ll> b(n,-1);
        for(int i=0;i<n;i++){
            if(a[i] >= 0 && a[i] < n){
                b[a[i]] = a[i];
            }
        }
        for(auto x : b){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}