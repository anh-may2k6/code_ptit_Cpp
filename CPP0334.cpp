#include <iostream>

using namespace std;
using ll = long long;

void test_case(){
    string s;
    cin >> s;
    int l = s.size();

    ll sum = 0;
    ll num = 0;
    bool check = false;
    for(int i=0;i<l;i++){
        if(!check){
            sum+=num;
            num = 0;
        }
        if(isdigit(s[i])){
            num = (num*10 + (s[i] -'0'));
            check = true;
        }
        else{
            check = false;
        }
    }
    sum+=num;
    cout << sum << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}