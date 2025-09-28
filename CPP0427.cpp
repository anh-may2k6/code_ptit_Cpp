#include <iostream>
#include <vector>

using namespace std;

void test_case(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n-1;i++){
        if(a[i] == 0) continue;
        if(a[i] == a[i+1]){
            a[i] *= 2;
            a[i+1] = 0;
        }
    }
    int d = 0;
    for(auto x : a){
        if(x != 0){
            d++;
            cout << x << " ";
        }
    }
    while(d < n){
        cout << "0 ";
        d++;
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