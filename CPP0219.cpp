#include <iostream>
#include <vector>

using namespace std;

void output(vector<vector<int>> &a , int n ,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
}

void transform(vector<vector<int>> &a , int n,int m){
    vector<int> row(n) , col(m); // cho hàng có n phần tử 0 , cột có m phần tử 0
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 1){
                row[i] = 1; // hàng i = 1
                col[j] = 1; // cột j = 1
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] || col[j]) a[i][j] = 1; // nếu hàng i = 1 or cột j = 1 thì gán a = 1
        }
    }
}

void input(vector<vector<int>> &a,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<int>> a(n,vector<int> (m));
        output(a,n,m);
        transform(a,n,m);
        input(a,n,m);
        cout << endl;
    }
}