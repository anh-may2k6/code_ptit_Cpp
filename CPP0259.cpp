#include <iostream>
#include <vector>

using namespace std;

void nhap(vector<vector<int>> &a,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
}

void xuat(vector<vector<int>> &c,int n,int p){
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,p;
    cin >> n >> m >> p;
    vector<vector<int>> a(n,vector<int> (m));
    vector<vector<int>> b(m,vector<int> (p));
    vector<vector<int>> c(n,vector<int> (p));
    nhap(a,n,m);
    nhap(b,m,p);
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            for(int k=0;k<m;k++){
                c[i][j] +=(a[i][k]*b[k][j]);
            }
        }
    }
    xuat(c,n,p);
    return 0;
}