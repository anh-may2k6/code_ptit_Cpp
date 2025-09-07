#include <iostream>
#include <cmath>

using namespace std;

void phan_tich(int n){
    int s = n;
    for(int i=2;i<=sqrt(s);i++){
        int dem = 0;
        while(s%i==0){
            dem++;
            s/=i;
        }
        if(dem > 0){
            cout << i << " " << dem << " ";
        }
    }
    if(s > 1){
        cout << s << " 1";
    }
    cout << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        phan_tich(n);
    }
    return 0;
}