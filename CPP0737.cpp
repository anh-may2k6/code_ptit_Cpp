#include <iostream>
#include <vector>

using namespace std;

double tb_sum(vector<int> &a , int l , int r){
    int ans = 0;
    while(r--){
        ans += a[l++];
    }
    return ans/4.0;
}

void test_case(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int Max = 0;
    double Max_value = tb_sum(a,0,k);
    for(int i=1;i<=n-k;i++){
        double tmp = tb_sum(a,i,k);
        if(Max_value < tmp){
            Max_value = tmp;
            Max = i;
        }
    }
    while(k--){
        cout << a[Max++] << " ";
    }
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