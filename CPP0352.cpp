#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>
#include <limits>

using namespace std;

map<string,int> mp;

void test_case(){
    string s;
    getline(cin , s);

    for(auto &x : s){
        x = tolower(x);
    }
    
    stringstream ss(s);
    string tmp;
    
    vector<string> v;
    while(ss >> tmp){
        v.push_back(tmp);
    }
    
    int l = v.size();
    string base = v[l-1];
    for(int i=0;i<l-1;i++){
        base += v[i][0];
    }
    mp[base]++;

    string email = base;
    if(mp[base] > 1){
        email += to_string(mp[base]);
    }
    email += "@ptit.edu.vn";
    cout << email << endl;
}

int main(){
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ toàn bộ \n còn lại
    while(t--){
        test_case();
    }
    return 0;
}