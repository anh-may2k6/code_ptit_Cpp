#include <iostream>

using namespace std;
using ll = long long;

ll sum(int n){
    ll sum = (ll)n*(n+1)/2; // dùng công thức toán học sẽ nhanh hơn rất nhiều 
    return sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << sum(n) << endl;
    }
    return 0;
}