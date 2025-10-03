#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream in("DATA.in");
    string s;
    ll sum = 0;
    while(in >> s){
        if(s.size() > 9) continue;
        ll num = 0;

        bool check = false;

        for(char c : s){
            if(!isdigit(c)){
                check = true;
                break;
            }
        }
        if(!check){
            num = stoll(s);
        }
        sum += num;
    }
    cout << sum << endl;
    in.close();
    return 0;
}