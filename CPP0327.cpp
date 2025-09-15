#include <iostream>

using namespace std;

bool check(const string &s){
    int sum = 0;
    for(auto x : s){
        sum = (2*sum +(x-'0'))%5; // chia lấy dư rồi cộng dư
    }
    return sum == 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(check(s)){
            cout << "Yes";
        }
        else{
            cout << "No";
        }
        cout << endl;
    }
    return 0;
}