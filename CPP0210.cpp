#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(){
    vector<int> v;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int mn = v[0];
    int ans = -1;
    for(int i=1;i<n;i++){
        ans = max(ans,v[i] - mn);
        mn = min(mn,v[i]);
    }
    cout << ans << endl;
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