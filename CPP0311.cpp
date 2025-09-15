#include <iostream>
#include <map>

using namespace std;

void test_case(){
    string s;
    cin >> s;
    int l = s.size();

    map<char,int> a;

    for(auto x : s){
        a[x]++;
    }
    int maxWord = 0;
    for(auto x : a){
        maxWord = max(maxWord , x.second);
    }
    if(maxWord > (l+1) / 2) cout << "0";
    else cout << "1";
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