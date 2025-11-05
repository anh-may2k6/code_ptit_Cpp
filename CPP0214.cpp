//bài này thì dùng cửa sổ trượt thôi

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void test_case(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    deque<int> dq;
    for(int i=0;i<k;i++){
        while(!dq.empty() && a[i] >= a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << a[dq.front()];
    for(int i=k;i<n;i++){
        //loại bỏ các dữ liệu nằm ngoài cửa sổ hiện tại
        while(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }
        //Loại bỏ cần phần tử nhỏ hơn phần tử hiện tại
        while(!dq.empty() && a[i] >= a[dq.back()]){
            dq.pop_back();
        }

        dq.push_back(i);
        cout << " " << a[dq.front()];
    }
    cout << endl;
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