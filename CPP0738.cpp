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
    int sum = 0;
    while(true){
        bool allZero = true; //nếu đưa hết về 0 thì dừng lại 
        for(int x : a){
            if(x != 0){
                allZero = false;
                break;
            }
        }
        if(allZero) break;
        //nếu có số nào lẻ thì xử lí luôn
        for(int i=0;i<n;i++){
            if(a[i] % 2 == 1){
                a[i]--;
                sum++;
            }
        }
        //xử lý số chẵn và nếu còn cái nào > 0 rồi thì ta chia tiếp cho 2 tận dụng 0x2=0
        bool chia_2 = false;
        for(int x : a){
            if(x > 0){
                chia_2 = true;
                break;
            }
        }
        if(chia_2){
            for(int i=0;i<n;i++){
                a[i] /= 2; // chia tất cả các phần phần tử cho 2
            }
            sum++;
        }
    }
    cout << sum << endl;
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