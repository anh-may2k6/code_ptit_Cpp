#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(){
    int n,m;
    cin >> n >> m;
    vector<int> v;
    for(int i=0;i<n+m;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
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
    while(t--){
        test_case();
    }
    return 0;
}