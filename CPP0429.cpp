#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k,b;
    cin >> n >> k >> b;
    //giả sử n đèn ban đầu đều sáng
    vector<int> v(n+1,0);

    for(int i=0;i<b;i++){
        int x;
        cin >> x;
        //đèn nào hỏng thì đánh dấu và gán value
        v[x] = 1;
    }
    //dùng kĩ thuật 2 con trỏ đề giải quyết
    int left = 1, right = 1;
    // cho cả 2 = 0 cũng đc ko sao cả
    int dem_MIN = INT_MAX;
    int dem = 0;
    while(right <= n){
        //đếm số cột đèn bị hỏng trong khoảng từ left cho đến right
        dem += v[right];
        if(right - left + 1 == k){
            dem_MIN = min(dem_MIN,dem);
            //mỗi khi sang 1 miền khác thì nếu cột đèn tại v[left] mà hỏng thì ta trừ đi
            dem -= v[left];
            ++left;
        }
        ++right;
    }
    cout << dem_MIN << endl;
    return 0;
}