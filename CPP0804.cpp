#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream in("VANBAN.in");
    string s;
    map<string,int> mp;
    while(in >> s){
        for(char &c : s){
            c = tolower(c);
        }
        mp[s]++;
    }
    for(auto &x : mp){
        cout << x.first << endl;
    }
    return 0;
}