#include <iostream>
#include <vector>

using namespace std;

void in(vector<vector<int>> &a,int n,int m){
    int c1 = 0 , c2 = m-1 , h1 = 0 , h2 = n-1;
    while(c1 <= c2 && h1 <= h2){
        for(int i=c1;i<=c2;i++){
            cout << a[h1][i] << " ";
        }
        h1++;
        for(int i=h1;i<=h2;i++){
            cout << a[i][c2] << " ";
        }
        c2--;
        if(h1 <= h2){
            for(int i=c2;i>=c1;i--){
                cout << a[h2][i] << " ";
            }
            h2--;
        }
        if(c1 <= c2){
            for(int i=h2;i>=h1;i--){
                cout << a[i][c1] << " ";
            }
            c1++;
        }
    } 
}

void test_case(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    in(a,n,m);
    cout << endl;
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