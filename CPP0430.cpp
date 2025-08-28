#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void test_case(){
    int n;
    cin >> n;

    vector<int> v;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);        
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end()); // loại bỏ trùng nhau
    int len = v.size();
    int l = v[0] , r = v[len-1];
    int dem = r-l+1-len;
    cout << dem << endl;
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