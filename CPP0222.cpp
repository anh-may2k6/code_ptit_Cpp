#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;

void test_case(){
    int n;
    cin >> n;
    map<int,int> m;
    for(int i=0;i<n;i++){
        unordered_set<int> p;
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            p.insert(x);
        }
        for(int x : p){
            m[x]++;
        }
    }
    int dem = 0;
    for(auto &x : m){
        if(x.second == n){
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