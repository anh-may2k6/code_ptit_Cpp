#include <iostream>

using namespace std;

int a[100],n;
bool ok = true;

void ktao(){ // khởi tạo số ban đầu là n số 0
    for(int i=0;i<n;i++){ // n == 3
        a[i] = 0; // 000
    }
}

void sinh(){
    int i = n-1; // i == 2
    while(i>=0 && a[i] == 1){
        a[i] = 0;
        --i;
    }
    if(i<0){
        ok = false; // hết cấu hình thì sẽ ngừng
    }
    else{
        a[i] = 1; // thêm 1 đơn vị ở cuối
    }
}

void test_case(){
    cin >> n;
    ktao();
    while(ok){
        for(int i=0;i<n;i++){
            cout << a[i]; // in ra từ ô đầu cho đến ô thứ 3 000 001 ...
        }
        cout << " ";
        sinh();
    }
    cout << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        ok = true; // reset lại ok để tránh bị lỗi khi muốn sinh 
        test_case();
    }
    return 0;
}