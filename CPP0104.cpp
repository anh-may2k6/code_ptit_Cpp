#include <iostream>

using namespace std;
using ll = long long;

ll factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1); // dùng đệ quy để tính giai thừa
}

ll sum(int n){
    ll sum = 0;
    for(int i=1;i<=n;i++){
        sum+=factorial(i);
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << sum(n) << endl;
    return 0;
}