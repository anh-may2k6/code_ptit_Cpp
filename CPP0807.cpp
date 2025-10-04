#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

ifstream in("DATA.in");

void nhap(set<int> &a , int n){
    for(int i=0;i<n;i++){
        int x;
        in >> x;
        a.insert(x);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    in >> n >> m;

    set<int> a;
    set<int> b;
    vector<int> giao;

    nhap(a,n);
    nhap(b,m);
    set_intersection(a.begin() , a.end() , b.begin() , b.end() , back_inserter(giao));
    
    for(auto &x : giao){
        cout << x << " ";
    }
    return 0;
}