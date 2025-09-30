#include <iostream>

using namespace std;
using ll = long long;

ll fibo[93];

void so_fibo(){
    fibo[0] = 1; fibo[1] = 1;
    for(int i=2;i<93;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
}

void test_case(){
    so_fibo();
    int a,b;
    cin >> a >> b;
    for(int i=a;i<=b;i++){
        cout << fibo[i-1] << " ";
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