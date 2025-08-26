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

void bien(vector<vector<int>> &a,int n){
    vector<vector<int>> v(n,vector<int> (n));
    for(int i=0;i<n;i++){
        if(i==0 || i == n-1) continue;
        for(int j=0;j<n;j++){
            if(j==0 || j == n-1) continue;
            else{
                v[i][j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!v[i][j]){
                cout << a[i][j] << " ";
            }
            else{
                cout << " " << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>> a(n,vector<int> (n));
        nhap(a,n);
        bien(a,n);
    }
    return 0;
}