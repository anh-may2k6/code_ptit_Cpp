#include <iostream>
#include <vector>

using namespace std;

void nhap(vector<int> &a,int n){
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

void test_case(){
    int n;
    cin >> n;
    vector<int> A1(n),A2(n);

    nhap(A1,n);
    nhap(A2,n);

    int ans = 0;
    for(int i=0;i<n-1;i++){
        int sum_1 = A1[i] , sum_2 = A2[i] , longer = 1 , tmp = 0;
        for(int j=i+1;j<n;j++){
            sum_1 += A1[j];
            sum_2 += A2[j];
            if(sum_1 == sum_2){
                longer++;
                longer+=tmp;
                tmp = 0;
            }
            else{
                tmp++;
            }
        }
        ans = max(ans,longer);
    }
    cout << ans << endl;
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