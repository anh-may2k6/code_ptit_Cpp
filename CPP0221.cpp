// bài này xoay theo từng lớp cũng ok

#include <iostream>
#include <vector>

using namespace std;
// dùng đệ quy để xoay từng lớp
void xoay(vector<vector<int>> &a,int n,int m,int idx){
    // khởi tạo lớp ngoài cùng
    int c1 = idx , c2 = m-1-idx,h1 = idx,h2 = n-1-idx;
    int tmp = a[h1][c1];
    if(c1 >= c2 || h1 >= h2) return;
    for(int i=h1;i<h2;i++){
        a[i][c1] = a[i+1][c1];
    }
    for(int i=c1;i<c2;i++){
        a[h2][i] = a[h2][i+1];
    }
    for(int i=h2;i>h1;i--){
        a[i][c2] = a[i-1][c2];
    }
    for(int i=c2;i>c1;i--){
        a[h1][i] = a[h1][i-1];
    }
    a[h1][c1+1] = tmp;
    xoay(a,n,m,idx+1); // lớp ma trận tiếp theo
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
    xoay(a,n,m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[i][j] << " ";
        }
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
