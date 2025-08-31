#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nhap(vector<int> &a,int n){
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
}

void xuat(vector<int> &a){
    for(auto x : a){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> a;
        vector<int> b;
        nhap(a,n);
        nhap(b,m);
        vector<int> hop,giao;
        set_union(a.begin(),a.end(),b.begin(),b.end(),back_inserter(hop));
        set_intersection(a.begin(),a.end(),b.begin(),b.end(),back_inserter(giao));
        xuat(hop);
        xuat(giao);
    }
    return 0;
}