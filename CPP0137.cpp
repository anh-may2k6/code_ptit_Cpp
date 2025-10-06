#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define Max 1000000

vector<bool> prime(Max+1, true);

void sang(){
    prime[0] = false , prime[1] = false;
    for(int i=2;i*i<=Max;i++){
        if(prime[i]){
            for(int j=i*i;j<=Max;j+=i){
                prime[j] = false;
            }
        }
    }
}

void test_case(){
    ll cnt = 0;
    ll l,r;
    cin >> l >> r;
    for(ll i = l; i*i <= r; i++){
        if(prime[i]){
            cnt++;
        }
    }
    cout << cnt << endl;
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