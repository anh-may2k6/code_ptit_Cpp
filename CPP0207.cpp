#include <iostream>

using namespace std;

#define Max 1000000

int a[Max+1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,d;
    cin >> t;
    while(t--){
        cin >> n >> d;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=n;i<=Max;i++){
            a[i] = a[i%n];
        }
        for(int i=0;i<n;i++){
            cout << a[i+d] << " ";
        }
        cout << endl;
    }
    return 0;
}