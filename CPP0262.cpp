#include <iostream>

using namespace std;
using ll = long long;

ll GCD(ll a , ll b){
    if(b==0) return a;
    return GCD(b,a%b);
}

void test_case(){
    ll n,m;
    cin >> n >> m;
    //tính tổng từ 1->n
    ll sum = n * (n + 1) / 2;
    // khi ta lấy tổng tập rồi thì ta thêm m vào rồi chia thành 2 tập
    ll a = (sum + m) / 2;
    ll b = sum - a;
    if(a - m == b && GCD(a,b) == 1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
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