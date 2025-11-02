#include <iostream>
#include <vector>

using namespace std;

inline void nhap(vector<int> &a , int n){
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

void test_case(){
    int n;
    cin >> n;
    vector<int> a(n);
    nhap(a,n);
    vector<int> LIS(n,1); //dãy con tăng và kết thúc ở i
    vector<int> LDS(n,1); //dãy con giảm và bắt đầu ở i

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j] < a[i]){
                LIS[i] = max(LIS[i] , LIS[j]+1);
            }
        }
    }
    
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(a[j] < a[i]){
                LDS[i] = max(LDS[i] , LDS[j]+1);
            }
        }
    }

    int max_len = 0;
    for(int i=0;i<n;i++){
        //vì nó đếm cả begin là 1 nên ta phải -1 cho bớt số tại i bị lặp lại
        max_len = max(max_len , LIS[i] + LDS[i] - 1);
    }
    cout << max_len << endl;
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