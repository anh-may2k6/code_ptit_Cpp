#include <iostream>
#include <vector>

using namespace std;

//sliding window
void test_case(){
    string a,b;
    cin >> a >> b;
    int n = a.size();

    vector<int> need(256,0) , have(256,0);
    for(auto x : b){
        need[x]++;
    }

    int s = 0;
    for(auto x : need){
        if(x > 0){
            s++;
        }
    }

    int formed = 0;
    int left = 0 , right = 0;
    int best_len = 1e9 , bestl = 0;

    while(right < n){
        have[a[right]]++;

        if(need[a[right]] > 0 && have[a[right]] == need[a[right]]){
            formed++;
        }

        while(left <= right && formed == s){
            //cập nhật kết quả nhỏ nhất
            if(right - left + 1 < best_len){
                best_len = right - left + 1;
                bestl = left;
            }
            //thu nhỏ cửa sổ
            have[a[left]]--;
            if(need[a[left]] > 0 && have[a[left]] < need[a[left]]){
                formed--;
            }
            left++;
        }
        right++;
    }
    if(best_len == 1e9){
        cout << "-1" << endl;
    }
    else{
        cout << a.substr(bestl,best_len) << endl;
    }
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