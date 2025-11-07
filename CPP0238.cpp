#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void test_case(){
    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    //lên , xuống , phải , trái
    vector<pair<int,int>> d = {{-1,0} , {1,0} , {0,1} , {0,-1}};    
    vector<vector<bool>> used(n,vector<bool> (m));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0 || i==n-1 || j==0 || j==m-1) && a[i][j] == 'O'){
                q.push({i,j});
                used[i][j] = true;
            }
        }
    }
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(auto [dx,dy] : d){
            int nx = x + dx;
            int ny = y + dy;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !used[nx][ny] && a[nx][ny] == 'O'){
                q.push({nx,ny});
                used[nx][ny] = true;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!used[i][j] && a[i][j] == 'O'){
                a[i][j] = 'X';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[i][j] << " ";
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