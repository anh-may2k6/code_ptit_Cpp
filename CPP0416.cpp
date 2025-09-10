#include <iostream>

using namespace std;

int dem(int a[],int n,int k){
    int count = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i] + a[j] == k){
                count++;
            }
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        cout << dem(a,n,k) << endl;
    }
    return 0;
}