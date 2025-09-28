#include <iostream>
#include <vector>

using namespace std;

void nhap(vector<vector<int>> &a , int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
}

void snake(vector<vector<int>> &a,int n){
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                cout << a[i][j] << " ";
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                cout << a[i][j] << " ";
            }
        }
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
        snake(a,n);
        cout << endl;
    }
    return 0;
}