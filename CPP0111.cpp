#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool check(const string& s){
    int l = s.size();
    for(int i=0;i<l-1;i++){
        int a = s[i]-'0';
        int b = s[i+1] - '0';
        if(abs(a-b) != 1) return false;
    }
    return true;    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();

    string s;
    while(t--){
        cin >> s;
        if(check(s)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}