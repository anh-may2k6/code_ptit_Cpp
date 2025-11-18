#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSwaps(vector<int> &a){
    int n = a.size();
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        v[i] = {a[i] , i};
    }

    sort(v.begin(),v.end());

    vector<bool> vis(n,false);
    int ans = 0;
    for(int i=0;i<n;i++){
        if(vis[i] || v[i].second == i) continue;

        int j = i;
        int mem = 0;
        
        while(!vis[j]){
            vis[j] = true;
            j = v[j].second;
            mem++;
        }
        ans += mem - 1;
    }
    return ans;
}

void test_case(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << minSwaps(a) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}