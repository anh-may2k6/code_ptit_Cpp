#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream in("DATA.in");
    map<int,int> mp;
    int a;
    while(in >> a){
        mp[a]++;
    }
    for(auto x : mp){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}