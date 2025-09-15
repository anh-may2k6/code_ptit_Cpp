#include <iostream>
#include <cmath>

using namespace std;

bool prime(int n){
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

void test_case(){
    int n;
    cin >> n;
    cout << "1" << " ";
    for(int i=2;i<=n;i++){
        if(prime(i)){
            cout << i << " ";
        }
        else{
            for(int j=2;j<=sqrt(i);j++){
                if(i%j==0){
                    cout << j << " ";
                    break;
                }
            }
        }
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}