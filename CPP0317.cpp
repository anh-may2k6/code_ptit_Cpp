#include <iostream>

using namespace std;

bool so_dep(const string &s){
    int l = s.size();
    for(int i=0;i<l/2;i++){
        if(s[i] % 2 != 0 || s[l-i-1] % 2 != 0) return false;
        if(s[i] != s[l-i-1]) return false;
    }
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        cin >> s;
        if(so_dep(s)){
            cout << "YES" << endl;
        }
        else{
            cout << " NO" << endl;
        }
    }
    return 0;
}