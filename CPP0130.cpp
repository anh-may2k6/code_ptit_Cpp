#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    ll n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n<2) continue;
        for(int i=2;i<=sqrt(n);i++){
            while(n%i==0){
                cout << i << " ";
                n/=i;
            }
        }
        if(n>1){
            cout << n << endl;
        }
        else{
            cout << endl;
        }
    }
    return 0;
}