//perfect number = 2^(p-1) * (2^p-1)
//trong đó 2^p-1 là số nguyên tố
//bài này tôi sẽ tạo tất cả các số hoàn hảo

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

bool so_nt(ll n){
    if(n<2) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(ll i=5;i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}

vector<ll> tao_sohh(ll n){
    vector<ll> perfectNumbers;
    for(int p=2; ;p++){
        ll num_right = (1LL << p)-1;
        ll num_perfect = (1LL << (p-1)) * num_right;
        if(num_perfect > n) break;
        if(so_nt(num_right)){
            perfectNumbers.push_back(num_perfect);
        }
    }
    return perfectNumbers;
}

bool check_perfectNumber(ll n){
    vector<ll> perfectNumber = tao_sohh(1e18);
    for(ll p:perfectNumber){
        if(n==p) return true;
    }
    return false;
}

void test_case(){
    ll n;
    cin >> n;
    if(check_perfectNumber(n)){
        cout << "1";
    }
    else{
        cout << "0";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}