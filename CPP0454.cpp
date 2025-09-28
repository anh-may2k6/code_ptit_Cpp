#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void binh_phuong(vector<ll> &a , int n){
    for(int i=0;i<n;i++){
        a[i] *= a[i];
    }
}

void test_case(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    binh_phuong(a,n);

    for(int i=n-1;i>=2;i--){
        int left = 0 , right = i-1;
        while(left < right){
            if(a[left] + a[right] == a[i]){
                cout << "YES" << endl;
                return;
            }
            else if(a[left] + a[right] < a[i]){
                left++;
            }
            else{
                right--;
            }
        }
    }
    cout << "NO" << endl;
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