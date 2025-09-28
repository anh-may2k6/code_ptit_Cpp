#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void test_case(){
    int n,k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    //sắp xếp thành các cặp từ nhỏ đến lớn
    sort(a.begin(),a.end());    
    int right = 0 , dem = 0;
    for(int left = 0 ; left < n;left++){
        while(right < n && a[right] - a[left] < k){
            right++;
        }
        //đếm các cặp từ left -> right 
        dem += (right - left - 1);
    }
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