#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
using ll = long long;

const int Max = 1000000;
char prime[Max+1];

void sang(){
    memset(prime,1,sizeof(prime));
    prime[0] = 0;prime[1] = 0;
    for(int i=2;i<=sqrt(Max);i++){
        if(prime[i]){
            for(int j=i*i;j<=Max;j+=i){
                prime[j] = 0;
            }
        }
    }    
}

void test_case(){
    int dem = 0;
    ll n;
    cin >> n;
    for(int i=2;i<=(int)sqrt(n);i++){
        if(prime[i]){
            dem++;
        }
    }
    cout << dem << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sang();

    int t;
    cin >> t;
    while(t--){
        test_case();
    }

    return 0;
}