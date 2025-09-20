#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,a,m;
    cin >> t;
    while(t--){
        bool check = false;
        cin >> a >> m;
        for(int i=0;i<m;i++){
            int e = a*i;
            if(e%m == 1){
                check = true;
                cout << i << endl;
                break;
            }
        }
        if(!check){
            cout << "-1" << endl;
        }
    }
    return 0;
}