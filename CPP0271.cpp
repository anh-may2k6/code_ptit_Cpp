//vì là *1 nên ta chỉ cần cộng các phần tử của ma trận ban đầu

#include <iostream>
#include <vector>

using namespace std;

inline void nhap(vector<vector<int>> &a,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
}

void test_case(){
    int n,m,l;
    cin >> n >> m >> l;
    vector<vector<int>> a(n,vector<int> (m));
    nhap(a,n,m);
    //sử dụng mảng cộng dồn để tính tổng 1 vùng 
    vector<vector<int>> prefix(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //tính tổng từ (0,0) -> (i,j) vì trùng nên ta - đi prefix[i][j]
            prefix[i+1][j+1] = a[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
        }
    }

    int row = n-l+1;
    int col = m-l+1;
    int size = l*l;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            //r1,c1 là tọa độ đầu tiên của ma trận a
            int r1 = i , c1 = j;
            //r2,c2 là tọa độ kết thúc 
            int r2 = i+l-1 , c2 = j+l-1;
            //tìm hình vuông có tổng như ý
            int total = prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
            cout << total/size << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}