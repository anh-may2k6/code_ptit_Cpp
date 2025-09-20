#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll doi_5_6(ll n){
    vector<int> v;
    while(n>0){
        int a = n%10;
        if(a == 5) a = 6;
        v.push_back(a);
        n/=10;
    }
    int l = v.size();
    ll sum = 0;
    for(int i=l-1;i>=0;i--){
        sum = sum*10 + v[i];
    }
    return sum;
}

ll doi_6_5(ll n){
    vector<int> v;
    while(n>0){
        int a = n%10;
        if(a == 6) a = 5;
        v.push_back(a);
        n/=10;
    }
    int l = v.size();
    ll sum = 0;
    for(int i=l-1;i>=0;i--){
        sum = sum*10 + v[i];
    }
    return sum;
}

ll MIN(ll a,ll b){
    ll x1 = doi_6_5(a) , x2 = doi_6_5(b);
    return x1+x2;
}

ll MAX(ll a,ll b){
    ll x1 = doi_5_6(a) , x2 = doi_5_6(b);
    return x1+x2;
}

void test_case(){
    ll a,b;
    cin  >> a >> b;
    cout << MIN(a,b) << " " << MAX(a,b) << endl;
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