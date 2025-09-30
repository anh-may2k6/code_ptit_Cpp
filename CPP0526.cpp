#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

struct people{
    string name , date;
};

void nhap(people a[],int n){
    cin.ignore();
    for(int i=0;i<n;i++){
        string str;
        getline(cin , str);

        int pos = str.find_last_of(' ');
        a[i].name = str.substr(0,pos);
        a[i].date = str.substr(pos+1);
    }
}

bool cmp(people &a,people &b){
    int da , ma , ya , db , mb , yb;
    char sep;

    stringstream ss_a(a.date);
    ss_a >> da >> sep >> ma >> sep >> ya;

    stringstream ss_b(b.date);
    ss_b >> db >> sep >> mb >> sep >> yb;

    if(ya != yb) return ya < yb;
    if(ma != mb) return ma < mb;
    return da < db;
}

int main(){
    int n;
    cin >> n;
    people pp[n];
    nhap(pp,n);
    sort(pp,pp+n,cmp);
    cout << pp[n-1].name << endl;
    cout << pp[0].name << endl;
    return 0;
}