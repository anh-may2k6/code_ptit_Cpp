//sau khi nộp đi nộp lại nhiều lần mà vẫn wa thì ra là ta cin k trước rồi mới cin x
// :D
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test_case(){
    int n,x,k;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> k >> x;
    // tìm vị trí có phần từ >= x
    auto it = lower_bound(a.begin(),a.end(),x);
    int ans = it - a.begin();
    int i = ans - 1;
    int j = ans;
    // tránh lấy trùng x chỉ đc phép lấy gần x nhất
    if(a[j] == x){
        j++;
    }
    for(int q = k/2; q > 0; q--){
        cout << a[i-q] << " ";
    }
    for(int w = 0; w < k/2 ; w++){
        cout << a[j+w] << " ";
    }
    cout << endl;
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