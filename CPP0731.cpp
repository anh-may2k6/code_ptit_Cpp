#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int solve(vector<ll> &a,int n){
    if(n == 1) return 0; //đã ở cuối
    if(a[0] == 0) return -1;

    ll MaxRoach = a[0];
    ll steps = a[0];
    int dem = 1;
    
    for(int i=1;i<n;i++){
        if(i == n-1) return dem;

        MaxRoach = max(MaxRoach , (ll)i + a[i]);
        steps--;

        if(steps == 0){
            dem++;
            if(i >= MaxRoach){
                return -1;
            }
            steps = MaxRoach - i;
        }
    }
    return -1;
}

void test_case(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << solve(a,n) << "\n";
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