#include <iostream>
#include <vector>

using namespace std;

bool so_fibo(int n){
    int a = 0, b = 1,c;
    if(n==0) return true;
    while(b < n){
        c = a + b;
        a = b;
        b = c;
    }
    return (b==n);
}   

void test_case(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++){
        if(so_fibo(v[i])){
            cout << v[i] << " ";
        }
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