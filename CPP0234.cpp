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
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n,vector<int> (m));
    vector<int> result;
    nhap(a,n,m);
    int h1 = 0 , h2 = n-1 , c1 = 0 , c2 = m-1;
    while(c1 <= c2 && h1 <= h2){
        for(int i=c1;i<=c2;i++){
            result.push_back(a[h1][i]);
        }
        h1++;
        for(int i=h1;i<=h2;i++){
            result.push_back(a[i][c2]);
        }
        c2--;
        if(h1 <= h2){
            for(int i=c2;i>=c1;i--){
                result.push_back(a[h2][i]);
            }
            h2--;
        }
        if(c1 <= c2){
            for(int i=h2;i>=h1;i--){
                result.push_back(a[i][c1]);
            }
            c1++;
        }
    }
    cout << result[k-1] << endl;
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