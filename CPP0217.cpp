#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(){
    int n,k;
    cin >> n >> k;
    vector<int> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            v.push_back(x);
        }
    }
    sort(v.begin(),v.end());
    cout << v[k-1] << endl;
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