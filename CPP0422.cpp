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
        int dem = 0;
        vector<ll> v;
        for(int i=0;i<n;i++){
            if(a[i] == 0){
                dem++; 
            }
            else{
                v.push_back(a[i]);
            }
        }
        for(auto x : v){
            cout << x << " ";
        }
        for(int i=0;i<dem;i++){
            cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}