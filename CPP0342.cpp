#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(vector<int> &a){
    int tong = 0;
    for(auto x : a){
        tong += x;
    }
    return tong;
}

void test_case(){
    string s;
    cin >> s;
    int n = s.size();

    vector<char> word;
    vector<int> num;
    
    for(int i=0;i<n;i++){
        if(isalpha(s[i])){
            word.push_back(s[i]);
        }
        if(isdigit(s[i])){
            int so = (int)(s[i] - '0');
            num.push_back(so);
        }
    }
    sort(word.begin(),word.end());
    for(auto x : word){
        cout << x;
    }
    cout << sum(num) << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}