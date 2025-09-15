#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void test_case(){
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin,s);

    for(auto &x : s){
        x = tolower(x);
    }

    stringstream ss(s);
    string tmp;

    vector<string> v;

    while(ss >> tmp){
        tmp[0] = toupper(tmp[0]);
        v.push_back(tmp);
    }

    int l = v.size();
    if(n==1){
        cout << v[l-1] << " ";
        for(int i=0;i<l-1;i++){
            cout << v[i];
            if(i == l-2) break;
            cout << " ";
        }
    }
    if(n==2){
        for(int i=1;i<l;i++){
            cout << v[i] << " ";
        }
        cout << v[0];
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        test_case();
    }
    return 0;
}