#include <iostream>

using namespace std;

void test_case(){
    int n;
    cin >> n;
    bool check = false;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(x != i && !check){
            cout << i << endl;
            i++;
            check = true;
        }
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