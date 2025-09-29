#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> v;
    string s;
    string damn = "aeiouy";
    cin >> s;
    for(auto &x : s){
        x = tolower(x);
    }
    for(auto x : s){
        bool check = false;
        for(auto y : damn){
            if(y==x){
                check = true;
                break;
            }
        }
        if(!check){
            v.push_back(x);
        }
    }
    for(int i=0;i<v.size();i++){
        cout << "." << v[i];
    }
    return 0;
}