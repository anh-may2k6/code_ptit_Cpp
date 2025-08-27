#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n/2;i++){
            cout << a[n-i-1] << " " << a[i] << " "; 
        }
        if(n%2 != 0){
            cout << a[n/2];
        }
        cout << endl;
    }
    return 0;
}