// số nguyên tố cùng nhau là ước chung lớn nhất của chúng = 1
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int Max = 100000;
char prime[Max+1];

void sang(){
    memset(prime,1,sizeof(prime));
    prime[0] = prime[1] = 0;
    for(int i=2;i<=sqrt(Max);i++){
        if(prime[i]){
            for(int j=i*i;j<=Max;j+=i){
                prime[j] = 0;
            }
        }
    }
}

// tính phi(x) là dựa vào công thức phi(x) = n(1-(1/p1))...(1-(1/pk)) để đếm nhanh số lượng mà có UCLN == 1
int phi(int n){
    int result = n;
    for(int i=2;i<=sqrt(n);i++){
        if(n % i == 0){
            while(n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if(n > 1) result -= result / n;
    return result;
}

void test_case(){
    int x;
    cin >> x;
    int t = phi(x);
    if(prime[t]) cout << "1";
    else cout << "0";
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sang();
    int T;
    cin >> T;
    while(T--){
        test_case();
    }
    return 0;
}