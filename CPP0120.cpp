#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

void MOD(int m,int n,int a){
    int start = ((m+a-1)/a)*a , end = n; // lấy bộ số nhỏ nhất a>=m
    for(int i=start;i<=end;i+=a){
        v.push_back(i);
    }
}

void test_case(){
    v.clear();
    int m,n,a,b;
    cin >> m >> n >> a >> b;
    MOD(m,n,a);
    MOD(m,n,b);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end()); // loại bỏ trùng nhau
    cout << v.size() << endl;
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