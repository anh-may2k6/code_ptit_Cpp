#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

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
        vector<ll> v;
        cin >> n;
        if(n<2) continue;
        for(int i=2;i<=sqrt(n);i++){
            if(!prime[i]) continue;
            while(n%i==0){
                v.push_back(i);
                n/=i;
            }
        }
        if(n>1){
            v.push_back(n);
        }
        cout << v[v.size()-1] << endl;
    }
    return 0;
}