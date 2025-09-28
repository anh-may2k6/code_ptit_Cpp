#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//sinh hoán vị kế tiếp
int n;
vector<int> a;

bool sinh(){
    int i = n-1;
    while(i>0 && a[i] > a[i+1]) i--;
    if(i==0) return false;

    int j = n;
    while(a[i] > a[j]) j--;
    swap(a[i],a[j]);
    reverse(a.begin()+i+1,a.end());
    return true;
}

void test_case(){
    cin >> n;
    a.resize(n+1);
    for(int i=1;i<=n;i++) a[i] = i;
    do{
        for(int i=1;i<=n;i++) cout << a[i];
        cout << " ";
    }while(sinh());
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