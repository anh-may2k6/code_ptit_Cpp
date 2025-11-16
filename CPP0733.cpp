#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//lên -> phải -> xuống -> trái
vector<int> dx = {-1 , 0 , 1 , 0};
vector<int> dy = {0 , 1 , 0 , -1};

inline void nhap(vector<vector<int>> &a , int n ,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
}

void test_case(){
    int n,m,x,y,z,t;
    cin >> n >> m >> x >> y >> z >> t;

    vector<vector<int>> a(n,vector<int> (m));
    nhap(a,n,m);


    if(a[x][y] == 0 || a[z][t] == 0){
        cout << "-1" << "\n";
        return;
    }
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n,vector<int> (m,-1));
    
    q.push({x,y});
    dist[x][y] = 0;
    while(!q.empty()){
        auto [u,v] = q.front();
        q.pop();
        //kết thúc hàm ở đây
        if(u == z && v == t){
            break;
        }
        
        for(int i=0;i<4;i++){
            int nx = u + dx[i];
            int ny = v + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(a[nx][ny] == 1 && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[u][v] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    cout << dist[z][t] << "\n";
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