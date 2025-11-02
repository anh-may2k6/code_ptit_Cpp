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
    
    vector<vector<int>> prefix(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            prefix[i+1][j+1] = a[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
        }
    }

    int row = n-l+1;
    int col = m-l+1;
    int size = l*l;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int r1 = i , c1 = j;
            int r2 = i+l-1 , c2 = j+l-1;
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