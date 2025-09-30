#include <iostream>
#include <sstream>

using namespace std;

int transform(const string &s){
    int sum = 0;
    for(auto x : s){
        sum = (sum*10 +(x-'0'));
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin , s);
        stringstream ss(s);
        string temp;
        int chan = 0,le = 0;
        while(ss >> temp){
            int x = transform(temp);
            if(x%2==0) chan++;
            else le++;
        }
        int l = chan+le;
        if((l%2==0 && chan > le) || (l%2 != 0 && le > chan)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}