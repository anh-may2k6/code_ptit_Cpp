#include <iostream>
#include <climits>

using namespace std;
using ll = long long;

void nhap(int a[],int n){
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

int MIN(int a[],int n){
    int min = INT_MAX;
    for(int i=0;i<n;i++){
        if(a[i] < min) min = a[i];
    }
    return min;
}

int MAX(int b[],int m){
    int max = INT_MIN;
    for(int i=0;i<m;i++){
        if(b[i] > max) max = b[i];
    }
    return max;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        int a[n],b[m];
        nhap(a,n);
        nhap(b,m);
        ll tich;
        tich = (ll)MAX(a,n)*MIN(b,m);
        cout << tich << endl;
    }
    return 0;
}