#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void test_case(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    //ý tưởng của bài này là lấy xâu con có tổng lớn nhất luôn
    //đối với 2 số đầu thì ta phải lấy num_1 là số lớn nhất để có thể tạo 1 dãy con max_sum
    ll num_2 = a[0] , num_1 = max(a[0],a[1]);
    ll ans = num_1;
    for(int i=2;i<n;i++){
        ll tmp = max(num_1 , num_2 + a[i]);
        ans = tmp;
        num_2 = num_1; // num_1 với num_2 sẽ đổi chỗ qua lại với nhau nên ko lo 2 số liền kề + lại với nhau đâu 
        num_1 = tmp;
    }
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