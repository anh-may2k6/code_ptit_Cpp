#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll modul = 1e9+7;

//hàm tìm ước số chunng lớn nhất
ll GCD(ll a,ll b){
    while(b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}
// đây là cách biến đổi nhị phân để tích a^b 
ll power(ll a, ll b){
    ll res = 1;
    while(b > 0){
        //nếu b lẻ thì ta lấy số trả về * cơ số
        if(b & 1) res = res * a % modul;
        // ta sẽ đưa về dạng bình phương cơ số a^2 * a^4 ...
        a = a * a % modul;
        //nó giống như việc chia đôi b giả sử b là 10 thì sau phép tình này thì chỉ còn 5
        b >>= 1;
    }
    return res;
}

void test_case(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll USCLN = a[0];
    for(int i=1;i<n;i++){
        USCLN = GCD(USCLN , a[i]);
    }
    ll sum = 1;
    for(int i=0;i<n;i++){
        sum = sum * a[i] % modul;
    }
    ll ans = power(sum , USCLN);
    cout << ans << endl;
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