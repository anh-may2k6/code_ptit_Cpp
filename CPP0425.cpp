#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(){
    int n,idx = 0;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i+=2){
        b[i] = a[idx++];
    }
    for(int i=1;i<n;i+=2){
        b[i] = a[idx++];
    }
    for(int i=0;i<n;i++){
        cout << b[i];
        if(i == n-1) break;
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