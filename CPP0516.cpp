#include <iostream>
#include <iomanip>

using namespace std;

struct hang{
    int id;
    string name , group;
    float mua , ban , loi;
};

void nhap(hang a[],int n){
    for(int i=0;i<n;i++){
        a[i].id = i+1;
        cin.ignore();
        getline(cin , a[i].name);
        getline(cin , a[i].group);
        cin >> a[i].mua >> a[i].ban;
        a[i].loi = a[i].ban - a[i].mua;
    }
}

void sapxep(hang a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j].loi > a[i].loi){
                swap(a[i],a[j]);
            }
        }
    }
}

void in(hang a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i].id << " " << a[i].name << " "
        << a[i].group << " " << fixed << setprecision(2)
        << a[i].loi << endl; 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    hang mh[n];
    nhap(mh , n);
    sapxep(mh , n);
    in(mh , n);
    return 0;
}