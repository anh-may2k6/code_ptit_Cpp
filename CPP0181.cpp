#include <iostream>

using namespace std;
using ll = long long;

ll GCD(ll a,ll b){
    if(b==0) return a;
    return GCD(b,a%b);
}

void test_case(){
    ll a,x,y;
    cin >> a >> x >> y;
    ll UCLN = GCD(x,y);
    for(int i=1;i<=UCLN;i++){
        cout << a;
    }
    cout << endl;
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