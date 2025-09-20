#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();

    string s;
    while(t--){
        unordered_map<char,int> a;
        vector<char> b;
        cin >> s;
        for(auto x : s){
            a[x]++;
            if(a[x] == 1){
                b.push_back(x);
            }
        }
        for(auto y : b){
            if(a[y] == 1){
                cout << y;
            }
        }
        cout << endl;
    }
    return 0;
}