#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a ,vector<int> &b){
    if(a.size() != b.size()) return a.size() > b.size();
    return a[0] < b[0];
}

void test_case() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) cin >> num[i];

    sort(num.begin(), num.end());
    vector<vector<int>> ans;

    int i = 0;
    while (i < n) {
        int j = i;
        vector<int> group;
        while (j < n && num[j] == num[i]) {
            group.push_back(num[j]);
            j++;
        }
        ans.push_back(group);
        i = j;
    }

    sort(ans.begin() , ans.end() , cmp);
    int l = ans.size();
    for(int i=0;i<l;i++){
        for(auto &x:ans[i]){
            cout << x << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) test_case();
}
