#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void in(vector<int> &v,int n){
    int l = 0;
    int h1 = 0 , h2 = n-1 , c1 = 0 , c2 = n-1;
    vector<vector<int>> a(n,vector<int> (n));
    while(h1 <= h2 && c1 <= c2){
        for(int i=c1;i<=c2;i++){
            a[h1][i] = v[l];
            l++; 
        }
        h1++;
        for(int i=h1;i<=h2;i++){
            a[i][c2] = v[l];
            l++;
        }
        c2--;
        if(h1 < h2){
            for(int i=c2;i>=c1;i--){
                a[h2][i] = v[l];
                l++;
            }
            h2--;
        }
        if(c1 < c2){
            for(int i=h2;i>=h1;i--){
                a[i][c1] = v[l];
                l++;
            }
            c1++;
        }
    }
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

    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            v.push_back(x);
        }
    }
    sort(v.begin(),v.end());
    in(v,n);
    return 0;
}