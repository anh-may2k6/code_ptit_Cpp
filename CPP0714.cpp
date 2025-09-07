#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void hoan_vi(vector<int> &a){
    int l = a.size();
    int i = l - 2;
    while(i >= 0 && a[i] < a[i+1]) --i; // check từ phải sang trái để có thể swap 
    if(i<0){
        reverse(a.begin(),a.end()); // i về 0 tức là hoán vị đến cuối cùng r ta chỉ cần lật ngược lại là ok    
    }
    else{
        int j = l-1;
        while(a[j] > a[i]) --j; // néu có phần tử lớn hơn thì swap , nếu i >= 0 thì giữ nguyên từ đầu cho đến i
        swap(a[i],a[j]);
        reverse(a.begin()+i+1,a.end()); // đảo ngược lại từ cuối đến i+1 là ta sẽ ra được hoán vị phía trước của nó 
    }
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
    hoan_vi(v);
    for(auto x : v){
        cout << x << " ";
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