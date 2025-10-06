#include <iostream>
#include <vector>

using namespace std;

void test_case(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int left = 0 , right = n-1;
    int MAX = 0;
    while(left < n){
        if(a[left] <= a[right]){
            MAX = max(MAX , right - left);
            left++;
            right = n-1;
            continue;
        }
        right--;
        if(left == right){
            left++;
            right = n-1;
        }
    }
    cout << MAX << endl;   
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