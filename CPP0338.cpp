#include <iostream>
#include <vector>

using namespace std;

int dem(string &s , int k){
    int n = s.size();
    int left = 0 , len = 0 , ans = 0;
    // khởi tạo mảng có kiểu char 
    vector<int> a(256,0);
    for(int right = 0 ; right < n ; right++){
        if(a[(unsigned char)s[right]]++ == 0){
            len++;
        }
        while(len > k){
            if(--a[(unsigned char)s[left]] == 0){
                len--;
            }
            left++;
        }
        ans += (right - left + 1);
    }
    return ans;
}

void test_case(){
    string s; int k;
    cin >> s >> k;
    int ans = dem(s,k) - dem(s,k-1);
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}