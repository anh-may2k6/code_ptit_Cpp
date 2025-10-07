#include <iostream>
#include <vector>

using namespace std;

void test_case(){
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    int ans = 0;
    //duyệt từ ma trận có chiều dài lớn nhất
    for(int len = n ; len >= 1 ; len--){
        bool check = false;
        // duyệt từ trên cùng góc bên trái
        for(int i = 0 ; i + len - 1 < n && !check ; i++){
            for(int j = 0 ; j + len - 1 < n && !check ; j++){
                bool ok = true;
                for(int x = j ; x < j+len && ok ; x++){
                    if(a[i][x] != 'X' || a[i+len-1][x] != 'X') ok = false;
                }
                for(int y = i ; y < i+len && ok ; y++){
                    if(a[y][j] != 'X' || a[y][j+len-1] != 'X') ok = false;
                }
                if(ok){
                    ans = len;
                    check = true;
                }
            }
        }
        if(check){
            break;
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) test_case();
    return 0;
}
