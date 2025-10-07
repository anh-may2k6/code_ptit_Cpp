#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    vector<int> res;
    // có tổng số đường chéo là n+m-1
    for(int s = 0 ; s < n + m - 1 ; s++){
        vector<int> tmp;
        for(int i = 0; i < n; i++){
            int j = s-i;
            if(j>=0 && j < m){
                tmp.push_back(a[i][j]);
            }
        }
        if(s % 2 == 0){
            reverse(tmp.begin() , tmp.end());
        }
        for(auto x : tmp){
            res.push_back(x);
        }
    }
    for(int x : res){
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