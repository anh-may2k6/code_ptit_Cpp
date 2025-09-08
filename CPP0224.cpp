#include <iostream>
#include <vector>

using namespace std;

int n,m;
int A[101][101];
// đánh dấu để những chỗ nào có thể tạo thành 1 miền
bool check[101][101];

// khởi tạo 8 hướng 
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

// những ô nào thỏa mãn điều kiện thì true
void dem(int x,int y){
    check[x][y] = true;
    for(int i=0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        // nếu đã được đánh dấu rồi thì bỏ qua còn không thì đánh dấu 
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !check[nx][ny] && A[nx][ny] == 1){
            dem(nx,ny);
        }
    }
}

void test_case(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> A[i][j];
            check[i][j] = false;
        }
    }
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] == 1 && !check[i][j]){
                dem(i,j);
                count++;
            }
        }
    }
    cout << count << endl;
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