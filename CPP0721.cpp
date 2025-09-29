// C1: O(n^2) : QHD
#include <iostream>
#include <vector>

using namespace std;

void test_case(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int max_len = 1;
    vector<int> dp(n+1,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){ // ta xét những số đằng trước a[i] có số nào nhỏ hơn thì có thể ghép lại thành 1 xâu con
            if(a[j] < a[i]){ // loại bỏ trùng nhau 
                dp[i] = max(dp[i],dp[j]+1); // tìm được thì tăng xâu con lên 1 đơn vị
            }
        }
        max_len = max(max_len , dp[i]);
    }
    cout << max_len << endl;
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

//C2: O(nlogn) QHD + Binary_search
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void test_case(){
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++){
//         cin >> a[i];
//     }
//     vector<int> dp; // tạo ra 1 mảng mới chỉ để lưu xâu con dài nhất
//     for(int x : a){
//         auto it = lower_bound(dp.begin(),dp.end(),x); // tìm vị trí mà phần tử đầu tiên >= x
//         if(it == dp.end()) dp.push_back(x); // nếu không có thì thêm vào xâu dài nhất
//         else *it = x; // thay đổi tại vị trí it gán bằng x 
//         // vd: 2 4 10 6 
//         // 2 4 10 -> 2 4 6 
//     }
//     cout << dp.size() << endl;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while(t--){
//         test_case();
//     }
//     return 0;
// }
