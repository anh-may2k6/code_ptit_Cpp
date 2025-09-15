#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


void test_case(){
    int dem = 0;
    int n;
    cin >> n;
    if(n%2 != 0){
        cout << dem << endl;
        return;
    }
    vector<int> v;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            v.push_back(i);
            if(i!= (n/i)){
                v.push_back(n/i);
            }
        }
    }
    for(auto x : v){
        if(x % 2 == 0){
            dem++;
        }
    }
    cout << dem << endl;
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