#include <iostream>
#include <algorithm>
#include <climits>

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
        int min = INT_MAX;
        sort(A,A+n,cmp);
        for(int i=0;i<n-1;i++){
            int a = A[i+1] - A[i];
            if(min > a) min = a;
        }
        cout << min << endl;
    }
    return 0;
}