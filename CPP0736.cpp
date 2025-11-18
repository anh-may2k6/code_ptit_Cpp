#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

void test_case(){
    int n;
    ll x;

    cin >> n >> x;

    ll sum = 0;
    queue<int> q;
    int res = 1e9;

    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        q.push(a);

        sum += a;

        while(!q.empty() && sum - q.front() > x){
            sum -= q.front();
            q.pop();
        }
        if(sum > x){
            res = min(res , (int)q.size());
        }
    }
    if(res == 1e9){
        cout << "-1";
    }
    else{
        cout << res;
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