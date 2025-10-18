#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

void nhap(vector<ll> &a ,int n){
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

void test_case(){
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    vector<ll> a(n1) , b(n2) , c(n3);
    nhap(a,n1);
    nhap(b,n2);
    nhap(c,n3);

    //kỹ thuật 3 con trỏ
    int i=0 , j=0 , k=0;
    bool check = false;

    while(i<n1 && j<n2 && k<n3){
        if(a[i] == b[j] && b[j] == c[k]){
            cout << a[i] << " ";
            check = true;
            ll val = a[i];
            while(i<n1 && a[i] == val) i++;
            while(j<n2 && b[j] == val) j++;
            while(k<n3 && c[k] == val) k++;
        }
        else{
            ll MIN = min(a[i],min(b[j],c[k]));
            if(a[i] == MIN) i++;
            else if(b[j] == MIN) j++;
            else k++;
        }
    }
    if(!check){
        cout << "-1";
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