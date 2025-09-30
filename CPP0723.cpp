// với bài này thì ko nên chạy từ 1 cho đến y vì rất chậm và nếu y 10^18 thì có thể bị TLE
// nên dùng lũy thừa nhị phân để giải quyết

#include <iostream>

using namespace std;
using ll = long long;

ll luy_thua(ll x,ll y,ll p){
    ll res = 1;
    x%=p; // nếu x lớn hơn p thì lấy dư luôn
    while(y > 0){
        if(y & 1){ // nếu y lẻ thì phải cộng thêm phần dư lẻ ra 
            res = (res * x) % p;
        }
        x = (x * x) % p; // mỗi vòng lặp *x cho đến khi y = 0
        y >>= 1; // mỗi vòng lặp giảm y đi 1 nửa thì độ phức tạp chỉ còn là o(logy) nhanh hơn rất nhiều so với o(y)
    }
    return res;
}

void test_case(){
    ll x,y,p;
    cin >> x >> y >> p;
    cout << luy_thua(x,y,p) << endl;
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