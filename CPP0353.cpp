#include <iostream>

using namespace std;

// đưa bảng chữ cái trên đt cục gạch về cùng 1 dãy sắp xếp
string keypad = "22233344455566677778889999";

bool check(string &s){
    int n = s.size();
    for(int i=0;i<n/2;i++){
        if(s[i] != s[n-i-1]) return false;
    }
    return true;
}

void test_case(){
    string s;
    cin >> s;
    string ans = "";
    for(auto &x : s){
        x = toupper(x);
    }
    for(auto x : s){
        ans += keypad[x - 'A'];
    }
    if(check(ans)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}