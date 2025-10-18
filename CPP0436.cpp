#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(){
    int n;
    cin >> n;
    vector<int> num(n);
    set<int> a;
    for(int i=0;i<n;i++){
        cin >> num[i];
        a.insert(num[i]);
    }
    for(int x : num){
        //it sẽ là tìm số mà lớn hơn x và gần x nhất trong a
        auto it = a.upper_bound(x);
        if(it == a.end()) cout << "_ ";
        else cout << *it << " ";
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