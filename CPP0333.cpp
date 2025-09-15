#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> v;
    string s;
    getline(cin , s);
    for(auto &x : s){
        x = tolower(x);
    }
    stringstream ss(s);
    string temp;
    while(ss >> temp){
        v.push_back(temp);
    }
    int l = v.size();
    for(auto &x : v[l-1]){
        x = toupper(x);
    }
    for(auto &x : v){
        x[0] = toupper(x[0]);
    }
    string a = "";
    for(int i=0;i<l-1;i++){
        a+=v[i];
        if(i==l-2){
            a+=",";
        }
        a+=" ";
    }
    a+=v[l-1];
    cout << a << endl;
    return 0;
}