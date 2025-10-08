#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void nhap(vector<int> &a , int n){
   for(int i=0;i<n;i++){
        cin >> a[i];
   }
}

void sap_dat(vector<int> &a , vector<int> &b , vector<int> &res){
    unordered_map<int,int> mp;
    for(auto x : a){
        mp[x]++;
    }
    for(auto x : b){
        if(mp.count(x)){
            res.insert(res.end() , mp[x] , x);
            mp.erase(x);
        }
    }
    vector<int> tmp;
    for(auto x : mp){
        tmp.push_back(x.first);
    }
    sort(tmp.begin(),tmp.end());
    for(auto x : tmp){
        res.insert(res.end() , mp[x] , x);
    }
}

void test_case(){
    int n,m;
    cin >> n >> m;
    vector<int> a1(n);
    vector<int> a2(m);
    nhap(a1,n);
    nhap(a2,m);

    vector<int> res;
    sap_dat(a1,a2,res);
    for(auto x : res){
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