#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define Max 10000000

bool primes[Max+1];
vector<int> a;

void sang(){
    fill(primes , primes + Max + 1 , true);
    primes[0] = primes[1] = false;
    for(int i=2;i*i<=Max;i++){
        if(primes[i]){
            for(int j=i*i;j<=Max;j+=i){
                primes[j] = false;
            }
        }
    }
    for(int i=2;i<=Max;i++){
        if(primes[i]) a.push_back(i);
    }
}

void test_case(){
    ll n; cin >> n;
    for(int x : a){
        if(1LL * x * x > n) break;
        int cnt = 0;
        while(n % x == 0){
            cnt++;
            n /= x;
        }
        if(cnt) cout << x << " " << cnt << "\n";
    }
    if(n > 1) cout << n << " 1\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sang();
    int t; cin >> t;
    while(t--){
        test_case();
        if(t) cout << "\n"; // xuống dòng giữa các test
    }
    return 0;
}
