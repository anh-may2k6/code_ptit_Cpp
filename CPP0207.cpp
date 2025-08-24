#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,d;
    cin >> t;
    while(t--){
        cin >> n >> d;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            cout << a[(i+d)%n] << " ";
        }
        cout << endl;
    }
    return 0;
}
