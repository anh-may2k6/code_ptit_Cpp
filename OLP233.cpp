#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

inline void nhap(vector<ll> &a , int n){
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

ll Long_sum(vector<ll> &a){
    //vì lấy trị tuyệt đối nên ta sẽ sort lại
    sort(a.begin() , a.end());
    int n = a.size();

    vector<ll> prefix(n);
    prefix[0] = a[0];

    //dùng tổng prefix để làm vì O(n) sẽ nhanh hơn rất nhiều so với O(n^2)
    for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + a[i];

    ll sum = 0;
    for(int i=1;i<n;i++){
        //với mỗi a[i] được lặp lại thì ta sẽ có các hiệu tương ứng
        sum += a[i]*1LL*i - prefix[i-1];
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n);
    nhap(a,n);
    cout << Long_sum(a) << "\n";    
    return 0;
}