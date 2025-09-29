#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(){
    string s;
    getline(cin , s);
    vector<string> v;
    stringstream ss(s);
    string temp;
    while(ss >> temp){
        v.push_back(temp);
    }
    reverse(v.begin(),v.end());
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        test_case();
    }
    return 0;
}