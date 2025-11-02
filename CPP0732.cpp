#include <iostream>
#include <vector>

using namespace std;

inline void nhap(vector<int> &a,int n){
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

void test_case(){
    int n;
    cin >> n;
    vector<int> a(n);
    nhap(a,n);
    vector<int> LIS_sum(n);
    for(int i=0;i<n;i++){
        LIS_sum[i] = a[i];
        for(int j=0;j<i;j++){
            if(a[j] < a[i]){
                LIS_sum[i] = max(LIS_sum[i] , LIS_sum[j] + a[i]);
            }
        }
    }
    
    int max_sum = 0;
    for(int i=0;i<n;i++){
        max_sum = max(max_sum , LIS_sum[i]);
    }
    cout << max_sum << endl;
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