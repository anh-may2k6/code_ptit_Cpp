//bài này chỉ việc tạo 1 dãy giống dãy đầu và sort 
//sort xong chỉ cần sắp xếp lại và dùng 2 con trỏ đẻ tìm left và right 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(){
    int n;
    cin >> n;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
        b.push_back(x);
    }
    sort(b.begin(),b.end());
    int l = 0 , r = n-1 , left = 0 , right = 0;
    bool check_1 = false ,check_2 = false;
    while(l<r){
        if(check_1 && check_2) break;
        if(!check_1 && a[l] != b[l]){
            check_1 = true;
            left = l;
        }
        if(!check_2 && a[r] != b[r]){
            check_2 = true;
            right = r;
        }
        l++;r--;
    }
    cout << left+1 << " " << right+1 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}