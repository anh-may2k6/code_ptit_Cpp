#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

class student{
    string id , name , lop , email;
public:
    friend void nhap(student a[],int n);
    friend bool cmp(const student &a,const student &b);
    friend void sap_xep(student a[],int n);
    friend void in(student a[],int n);
};

void nhap(student a[],int n){
    for(int i=0;i<n;i++){
        cin >> a[i].id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin , a[i].name);
        cin >> a[i].lop >> a[i].email;
    }
}

bool cmp(const student &a,const student &b){
    return a.lop < b.lop;
}

void sap_xep(student a[],int n){
    sort(a,a+n,cmp);        
}

void in(student a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i].id << " " << a[i].name << " "
        << a[i].lop << " " << a[i].email << endl;
    }
}

int main(){
    int n;
    cin >> n;
    vector<student> sv(n);
    nhap(sv.data(),n); //sv.data() là trỏ về vị trí ban đầu của mảng 
    sap_xep(sv.data(),n);
    in(sv.data(),n);
    return 0;
}