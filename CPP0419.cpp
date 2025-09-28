#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//nhập dãy số
void nhap(vector<int> &a,int n){
    //cấp phát bộ nhớ cho a
    a.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];
}

void printUni(vector<int> &a,vector<int> &b){
    int i = 0 , j = 0;
    bool first = true;
    while(i < (int)a.size() && j < (int)b.size()){
        int val;
        // cái nào có số nhỏ hơn thì sẽ in ra vì nó là union
        if(a[i] < b[j]) val = a[i++];
        else if(a[i] > b[j]) val = b[j++];
        else{ 
            val = a[i++];
            j++;
        }
        //nếu là lần đầu thì sẽ ko in cách
        if(!first) cout << " ";
        cout << val;
        first =false;
    }
    // nếu in còn dư 1 trong 2 dãy thì in ra hết 
    while(i < (int)a.size()){
        if(!first) cout << " ";
        cout << a[i++];
        first = false;
    }
    while(j < (int)b.size()){
        if(!first) cout << " ";
        cout << b[j++];
        first = false;
    }
    cout << endl;
}

void printInter(vector<int> &a, vector<int> &b){
    //ngược lại với hợp thì giao chỉ cần in những số nằm khoảng của nhau
    int i = 0 , j = 0;
    bool first = true;
    while(i < (int)a.size() && j < (int) b.size()){
        if(a[i] == b[j]){
            if(!first) cout << " ";
            cout << a[i];
            first = false;
            i++;j++;
        }
        else if(a[i] < b[j]) i++;
        else j++;
    }
    cout << endl;
}

void test_case(){
    int n,m;
    cin >> n >> m;
    vector<int> a,b;
    nhap(a,n);
    nhap(b,m);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    printUni(a,b);
    printInter(a,b);
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