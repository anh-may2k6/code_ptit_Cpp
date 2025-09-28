#include <iostream>

using namespace std;
using ll = long long;

void test_case(){
    string n;
    ll m;
    cin >> n;
    cin >> m;
    int l = n.size();
    ll du = 0;
    for(int i=0;i<l;i++){
        ll num = (n[i] - '0');
        du = (du*10 + num) % m;
    }
    cout << du << endl;
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