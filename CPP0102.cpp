#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    char c;
    cin >> t;
    cin.ignore();
    while(t--){
        cin >> c;
        if(c >= 97 && c <= 122){ // đối chiếu trong bảng ASCII
            c = toupper(c); // in hoa
        }
        else if(c >= 65 && c <= 90){
            c = tolower(c); // in thường 
        }
        cout << c << endl;
    }
    return 0;
}