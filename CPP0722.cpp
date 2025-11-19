#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using bint = string;

bint operator * (bint a , int b){
    if(a == "0" || b == 0) return "0";
    int n = a.length();

    bint c(n,'0');
    int carry = 0;
    for(int i=n-1;i>=0;i--){
        carry += (a[i] - '0') * b;
        c[i] = carry % 10 + '0';
        carry /= 10;
    }
    if(carry > 0){
        c = to_string(carry) + c;
    }
    return c;
}

bint CATALAN(short n){
    vector<int> tu;
    for(int i=n+2;i<=2*n;i++){
        tu.push_back(i);
    }
    
    for(int i=2;i<=n;i++){
        int x = i;
        for(int j=0;j<tu.size() && x > 1;j++){
            int d = __gcd(tu[j] , x);
            tu[j] /= d;
            x /= d;
        }
    }
    bint res = "1";
    for(int x : tu){
        res = res * x;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    short n;
    cin >> n;
    cout << CATALAN(n+1) << "\n";
    return 0;
}