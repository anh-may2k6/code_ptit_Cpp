#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const int &a,const int &b){
    return a<b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin >> n;
    map<int,int> a;
    for(int i=0;i<n;i++){
        cin >> x;
        a[x]++;
    }
    for(auto y : a){
        cout << y.first << " ";
    }
    cout << endl;
    return 0;
}