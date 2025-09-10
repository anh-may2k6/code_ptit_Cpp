#include <iostream>

using namespace std;

bool check(int n){
    while(n>0){
        int a = n%10;
        if(!(a == 0 || a==6 || a==8)){
            return false;
        }
        n/=10;
    }
    return true;
}


int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        if(check(n)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}