#include <iostream>
#include <cmath>
#include <cstring>

#define Max 1000000

using namespace std;
using ll = long long;

char prime[Max+1];

void sang(){
    memset(prime,1,sizeof(prime));
    prime[0] = 0,prime[1] = 0;
    for(int i=2;i<=sqrt(Max);i++){
        if(prime[i]){
            for(int j=i*i;j<=Max;j+=i){
                prime[j] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sang();
    int t;
    ll n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n<2) continue;
        for(int i=2;i<=sqrt(n);i++){
            if(!prime[i]) continue;
            while(n%i==0){
                cout << i << " ";
                n/=i;
            }
        }
        if(n>1){
            cout << n << endl;
        }
        else{
            cout << endl;
        }
    }
    return 0;
}
