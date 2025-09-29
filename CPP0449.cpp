#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void test_case(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    unordered_set<int> b;
    for(int i=0;i<n;i++){
        if(b.count(a[i] - x) || b.count(a[i] + x)){
            cout << "1" << endl;
            return;
        }
        b.insert(a[i]);
    }
    cout << "-1" << endl;
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