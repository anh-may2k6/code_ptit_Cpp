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
    sort(v.begin(),v.end()); // sắp xếp tăng dần
    v.erase(unique(v.begin(),v.end()),v.end()); // loại bỏ trùng nhau
    int l = v.size();
    if(l==1){
        cout << "-1" << endl;
    }
    else{
        cout << v[0] << " " << v[1] << endl;
    }
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