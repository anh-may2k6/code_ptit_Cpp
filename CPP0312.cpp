#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        cin >> s;
        if(s.size() < 26){
            cout << "0" << endl;
            continue;
        }
        int k;
        cin >> k;
        cin.ignore();
        map<char,int> a;
        for(auto x : s){
            a[x]++;
        }
        int l = a.size();
        if(26-l <= k){
            cout << "1";
        }
        else{
            cout << "0";
        }
        cout << endl;
    }
    return 0;
}