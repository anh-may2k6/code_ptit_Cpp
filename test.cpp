#include <iostream>
#include <cmath>

using namespace std;

bool can_bang(int n){
    int chan = 0 , le = 0;
    while(n>0){
        int d = n%10;
        if(d%2==0) chan++;
        else le++;
        n/=10;
    }
    return chan == le;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int start = pow(10,n-1);
    int end = pow(10,n)-1;
    int dem = 0;

    for(int i=start;i<=end;i++){
        if(can_bang(i)){
            cout << i << " ";
            dem++;
            if(dem%10 == 0){
                cout << endl;
            }
        }
    }
    return 0;
}