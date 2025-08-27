#include <iostream>
#include <map>

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
        map<int,int> b;
        for(int i=0;i<n;i++){
            cin >> a[i];
            ll x = a[i];
            while(x > 0){
                b[x%10]++;
                x/=10;
            }
        }
        for(auto x : b){
            cout << x.first << " ";
        }
        cout << endl;
    }

    return 0;
}