#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<char> v;
        unordered_map<char,int> a;
        int count = 0;
        for(auto x : s){
            if(a[x] == 0){
                v.push_back(x);
            }
            a[x]++;
        }
        for(auto x : v){
            cout << x << a[x];
        }
        cout << endl;
    }
    return 0;
}