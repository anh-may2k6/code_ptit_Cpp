#include <iostream>
#include <vector>

using namespace std;

int dem(vector<vector<int>> &a,int n){
    int dem = 0,count;
    for(int i=0;i<n;i++){
        count = 0;
        for(int j=0;j<3;j++){
            if(a[i][j] == 1){
                count++;
            }
        }
        if(count > 1){
            dem++;
        }
    }
    return dem;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int> (3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> a[i][j];
        }
    }
    cout << dem(a,n) << endl;
    return 0;
}