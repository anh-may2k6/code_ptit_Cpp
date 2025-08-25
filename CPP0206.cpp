#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const int& a,const int& b){
    return a>b;
}

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
        sort(a,a+n,cmp);
        cout << a[0] << endl;
    }
    return 0;
}