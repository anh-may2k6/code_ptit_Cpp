#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const int& a,const int& b){
    return a<b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int A[n];
        for(int i=0;i<n;i++){
            cin >> A[i];
        }
        int dem = 1;
        sort(A,A+n,cmp);
        for(int i=0;i<n;i++){
            if(A[i] < dem) continue; 
            if(dem == A[i]){
                dem++;
            }
            else if(A[i] > dem){
                break;
            }
        }
        cout << dem << endl;
    }
    return 0;
}