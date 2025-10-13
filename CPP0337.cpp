#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void test_case(){
    string s;
    cin >> s;
    int n = s.size();

    unordered_set<char> unique_chars(s.begin() , s.end());
    int total = unique_chars.size();
    unordered_map<char , int> cnt;
    int left = 0 , right = 0, have = 0, res = n;
    while(right < n){
        cnt[s[right]]++;
        if(cnt[s[right]] == 1) have++;
        while(have == total){
            res = min(res , right - left + 1);
            // thu nhỏ cửa sổ
            cnt[s[left]]--;
            //điều kiện để kết thúc hàm while
            if(cnt[s[left]] == 0) have--;
            left++;
        } 
        right++;
    }
    cout << res << endl;
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