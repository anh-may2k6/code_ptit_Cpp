// ý tưởng của bài này sẽ là duyệt từng hàng 1 
// mỗi hàng sẽ có max riêng và tìm xem có bao nhiêu
// tính diện tích hình chữ nhật mỗi hàng từ trên xuống
// tìm xem hình chữ nhật nào có diện tích lớn nhất

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans;

void check(vector<vector<int>> &a,int n,int m,int idx){
    if(idx == n) return;
    vector<int> h(m,0);
    for(int i=0;i<m;i++){
        int dem = 0;
        for(int j=idx;j<n;j++){
            if(a[j][i] == 1) dem++;
            else break; 
        }
        h[i] = dem;
    }
    int MAX = *max_element(h.begin(),h.end());
    vector<int> count(MAX+1,0);
    for(auto x : h){
        count[x]++;
    }
    int cnt = 0;
    for(int i=MAX;i>=1;i--){
        // nếu mà chỉ lấy mỗi count[i] thì sẽ là lấy hình chữ nhật có diện tích theo chiều cao lớn nhất mà chiều ngang lại bỏ đi 
        cnt += count[i];
        ans = max(ans,cnt*i);
    }
    check(a,n,m,idx+1);
}

void test_case(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    ans = 0;
    check(a,n,m,0);
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