#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(){
    int n;
    cin >> n;
    vector<int> v;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int l = 0,r = v.size();
    for(int i=0;i<n;i+=2){
        a[i] = v[--r];
    }
    for(int i=1;i<n;i+=2){
        a[i] = v[l++];
    }
    for(auto x : a){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}