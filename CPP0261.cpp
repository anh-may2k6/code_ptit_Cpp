#include <iostream>
#include <vector>

using namespace std;

void nhap(vector<vector<int>> &a,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
}

void in(vector<vector<int>> &a,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n;
    vector<vector<int>> a(n,vector<int> (n));
    nhap(a,n);
    cin >> m;
    vector<vector<int>> b(m,vector<int> (m));
    nhap(b,m);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j] *= b[i%m][j%m];
        }
    }
    in(a,n);
    return 0;
}