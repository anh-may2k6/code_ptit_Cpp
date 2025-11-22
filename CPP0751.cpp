#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline void nhap(vector<int> &a , int n){
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}
//xử lí các trường hợp đặc biệt
int test(int a_i , vector<int> &b , int m , vector<int> &dem){
    //0^y < y^0
    if(a_i == 0) return 0;
    if(a_i == 1) return dem[0];
    //tìm vị trí gần nhất > a_i
    auto i = upper_bound(b.begin(), b.end() ,a_i);
    //số phần tử lớn hơn a_i
    int a = b.end() - i;
    a += (dem[0] + dem[1]);
    if(a_i == 2){
        //2^3 < 3^2 || 2^4 == 4^2
        a -= (dem[3] + dem[4]);
    }
    if(a_i == 3){
        a += dem[2];
    }
    return a;
}

int count(vector<int> &a , vector<int> &b , int n , int m){
    vector<int> dem(5);
    for(int i=0;i<m;i++){
        if(b[i] < 5){
            dem[b[i]]++;
        }
    }
    sort(b.begin(), b.end());
    int res = 0;
    for(int i=0;i<n;i++){
        res += test(a[i] , b , m , dem); 
    }
    return res;
}

void test_case(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n) , b(m);
    nhap(a,n);
    nhap(b,m);
    cout << count(a,b,n,m) << "\n";    
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