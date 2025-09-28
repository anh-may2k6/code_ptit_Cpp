#include <iostream>
#include <map>

using namespace std;

void test_case(){
    string s;
    cin >> s;
    if(s[0] == '0'){
        cout << "INVALID" << endl;
        return;
    }
    map<char,int> a;

    for(auto x : s){
        a[x]++;
    }
    int l = 0;
    for(auto x : a){
        if(x.first < '0' || x.first > '9'){
            cout << "INVALID" << endl;
            return;
        }
        l++;
    }
    if(l == 10){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" <<endl;
    }
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