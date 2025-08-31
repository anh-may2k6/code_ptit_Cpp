#include <iostream>

using namespace std;

int tong(int n){
    int sum = 0;
    while(n > 0){
        sum+=n%10;
        n/=10;
    }
    if(sum < 10){
        return sum;
    }
    return tong(sum);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << tong(n) << endl;
    }
    return 0;
}