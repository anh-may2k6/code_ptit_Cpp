#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void test_case(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        if(i == 0){
            b[i] = a[i] * a[i+1];
        }
        else if(i==n-1){
            b[i] = a[i] * a[i-1];
        }
        else{
            b[i] = a[i+1] * a[i-1];
        }
        cout << b[i] << " ";
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