#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for(int i=2;i<=sqrt(n);i++){
        int dem = 0;
        while(n%i==0){
            dem++;
            n/=i;
        }
        if(dem > 0){
            cout << i << " " << dem << endl;
        }
    }
    if(n>1){
        cout << n << " " << "1" << endl;
    }
    return 0;
}