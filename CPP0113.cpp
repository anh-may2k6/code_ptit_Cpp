#include <iostream>

using namespace std;

bool check(int n){
    int a = n%100;
    if(a != 86) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    cin >> t;
    while(t--){
        cin  >> n;
        if(check(n)){
            cout << "1" << endl;
        }
        else{
            cout << "0" << endl;
        }
    }
    return 0;
}