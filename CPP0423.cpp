#include <iostream>
#include <vector>

using namespace std;

void test_case(){
    int n,k,count = 0;
    cin >> n >> k;
    vector<int> a;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i] <= k){
            count++;
        }
    }
    int good = 0;
    for(int i=0;i<count;i++){
        if(a[i] <= k){
            good++;
        }
    }
    int max_good = good;
    for(int i=count;i<n;i++){
        //reset đòn đánh tay
        if(a[i-count] <= k) --good;
        if(a[i] <= k) ++good;
        max_good = max(max_good,good);
    }
    cout << count-max_good << endl;
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