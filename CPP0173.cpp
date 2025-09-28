#include <iostream>

using namespace std;
using ll = long long;

ll GCD(ll a,ll b){ // Ước chung lớn nhất
    if(b==0) return a;
    return GCD(b,a%b);
}

ll LCM(ll a,ll b){ // Bội chung nhỏ nhất
    return (a/GCD(a,b))*b;
}

void test_case(){
    ll x,y,z,n;
    cin >> x >> y >> z >> n;
    ll l = LCM(x,LCM(y,z));
    ll low = 1;
    for(int i=1;i<n;i++){
        low *= 10; // khởi tạo low là số có n chữ số bé nhất
    }
    ll Max = low*10 - 1;
    ll k = (low + l - 1)/l;
    ll ans = k*l; // làm tròn để lấy phần tử gần low nhất
    if(ans <= Max){
        cout << ans << endl;
    }
    else{
        cout << "-1" << endl;
    }
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