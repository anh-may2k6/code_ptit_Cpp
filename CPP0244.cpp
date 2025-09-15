#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin >> n;
    map<int,int> a; // map nó có sẵn less<int> nên là nó sẽ sắp xếp từ bé đến lơn 
    for(int i=0;i<n;i++){
        cin >> x;
        a[x]++; // nếu gặp số trùng nhau thì ++
    }
    for(auto y : a){
        cout << y.first << " ";
    }
    cout << endl;
    return 0;
}
