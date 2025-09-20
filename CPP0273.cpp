#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void test_case(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
    }
    ll left = 0;
    for(int i=0;i<n;i++){
        ll right = sum - left - a[i];
        if(left == right){
            cout << i+1 << endl;
            return;
        }
        left += a[i];
    }
    cout << "-1" << endl;
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