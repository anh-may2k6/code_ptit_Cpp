#include <iostream>

using namespace std;
using ll = long long;

int GCD(int a,int b){
    if(b==0) return a;
    return GCD(b,a%b);
}

ll LCM(int a,int b){
    return (ll)(a/GCD(a,b))*b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << LCM(a,b) << " " << GCD(a,b) << endl;
    }
    return 0;
}