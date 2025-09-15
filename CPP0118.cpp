#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool check(int n){
    vector<int> v;
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            v.push_back(i);
            n/=i;
        }
    }
    if(n>1){
        v.push_back(n);
    }
    int l = v.size();
    if(l != 3) return false;
    for(int i=0;i<l-1;i++){
        if(v[i] == v[i+1]){
            return false;
        }
    }
    return true;
}

void test_case(){
    int n;
    cin >> n;
    if(check(n)){
        cout << "1";
    }
    else{
        cout << "0";
    }
    cout << endl;
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