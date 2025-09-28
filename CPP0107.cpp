#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    cin >> t;
    cin.ignore();

    vector<char> va = {'A','B','B','A','D','C','C','A','B','D','C','C','A','B','D'}; // các đáp án đúng theo đề 
    vector<char> vb = {'A','C','C','A','B','C','D','D','B','B','C','D','D','B','B'};

    while(t--){
        cin >> n;
        cin.ignore();
        double diem = 0;
        char c;
        for(int i=0;i<15;i++){
            if(n==101){ // đối chiếu xem có khớp với mã đề rồi check đáp án
                cin >> c;
                if(c==va[i]){ // nếu đúng thì + điểm
                    diem+=(2.0/3);
                }
            }
            else if(n==102){
                cin >> c;
                if(c==vb[i]){
                    diem+=(2.0/3);
                }
            }
        }
        cout << fixed << setprecision(2) << diem << endl;
    }
    return 0;
}