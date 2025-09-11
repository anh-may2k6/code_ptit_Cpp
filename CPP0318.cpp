#include <iostream>

using namespace std;

bool so_tc(string &a,int l){
    for(int i=0;i<l-1;i++){
        if(a[i] >= a[i+1]) return false;
    }
    return true;
}

bool so_bang(string &a,int l){
    for(int i=0;i<l-1;i++){
        if(a[i] != a[i+1]) return false;
    }
    return true;
}

bool so_lp(string &a,int l){
    for(int i=0;i<l;i++){
        if(a[i] != '6' && a[i] != '8') return false;
    }
    return true;
}

bool so(string &a,int l){
    for(int i=0;i<l-3;i++){
        if(a[i] != a[i+1]) return false;
    }
    for(int i=3;i<l-1;i++){
        if(a[i] != a[i+1]) return false;
    }
    return true;
}

void test_case(){
    string s;
    cin >> s;
    cin.ignore();
    
    string a = "";
    int l = s.size();
    for(int i=5;i<l;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            a += s[i];
        }
    }
    int len = a.size();
    if(so_tc(a,len) || so_lp(a,len) || so(a,len) || so_bang(a,len)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        test_case();
    }
    return 0;
}