#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    // dp_a là xâu toàn là A 
    //dp_b là xâu toàn là B
    vector<int> dp_a(n) , dp_b(n);
    //ta sẽ tìm số bước biến đổi thành xâu toàn A dp_a[n-1]
    dp_a[0] = ((s[0] == 'A') ? 0 : 1);
    dp_b[0] = ((s[0] == 'B') ? 0 : 1);

    for(int i=1;i<n;i++){
        if(s[i] == 'A'){
            dp_a[i] = dp_a[i-1];
            dp_b[i] = min(dp_b[i-1] + 1 , dp_a[i-1] + 1);
            // vd: AA thì xâu toàn A sẽ giữu nguyên là 0 còn lại xâu B sẽ đổi luôn cả dãy thay vì chỉ đổi 1 phần tử
        }
        else{ //s[i] == 'B
            //nó sẽ tương tự như if trên
            dp_a[i] = min(dp_a[i-1] + 1 , dp_b[i-1] + 1);
            dp_b[i] = dp_b[i-1];
        }
    }
    cout << dp_a[n-1] << endl;
    return 0;
}