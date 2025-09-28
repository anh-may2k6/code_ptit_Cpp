#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void test_case(){
    int n , x;
    cin >> n >> x;
    // dùng pair để lưu cả giá trị và thứ tự xuất hiện
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(),a.end(),[x](pair<int,int> u,pair<int,int> v){
        int du = abs(x-u.first);
        int dv = abs(x-v.first);
        //nếu giá trị = nhau thì xếp theo thứ tự
        if(du == dv) return u.second < v.second;
        return du < dv;
    });
    for(int i=0;i<n;i++){
        cout << a[i].first;
        if(i==n-1) break;
        cout << " ";
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