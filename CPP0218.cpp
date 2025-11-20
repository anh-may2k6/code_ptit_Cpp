#include <iostream>
#include <vector>

using namespace std;

void test_case(){
    int n;
    cin >> n;
    vector<int> a(n);
    int max_num = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        max_num = max(max_num , a[i]);
    }

    bool s = false;
    for(int i=0;i<n-1;i++){
        if(a[i] != a[i+1]){
            s = true;
        }
    }

    int count = 0;
    for(int i=1;i<=max_num;i++){
        int p = a[0] % i;
        int dem = 1;
        for(int j=1;j<n;j++){
            if(a[j] % i != p){
                break;
            }
            else{
                dem++;
            }
        }
        if(dem == n) count++;
    }
    if(!s){
        cout << 0;
    }
    else{
        cout << count;
    }
    cout << "\n";
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