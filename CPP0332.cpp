#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin , s);
    for(auto &x : s){
        x = tolower(x);
    }
    vector<string> v;
    stringstream ss(s);
    string temp;
    while(ss >> temp){
        v.push_back(temp);
    }
    int l = v.size();
    string a = v[l-1];
    for(int i=0;i<l-1;i++){
        a+=v[i][0];
    }
    a+="@ptit.edu.vn";
    cout << a << endl;
    return 0;
}