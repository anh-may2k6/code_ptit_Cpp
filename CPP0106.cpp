#include <iostream>
#include <string>

using namespace std;
using ll = long long;

bool check_var(ll n){
    string s = to_string(n);
    int l = s.size();
    for(int i=0;i<l;i++){
        if(s[i] != s[l-i-1]){ // kiểm tra đầu với cuối
            return false; // không đúng thì false luôn
        }
    }
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    ll n;
    cin >> t;
    cin.ignore(); // bỏ dấu xuống dòng của cin ở trên 
    while(t--){
        cin >> n;
        if(check_var(n)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}