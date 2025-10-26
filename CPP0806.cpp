#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;
using ll = long long;

ifstream in_kh("KH.in");
ifstream in_mh("MH.in");
ifstream in_hd("HD.in");

int idx_kh = 0 , idx_mh = 0 , idx_hd = 0;

class HoaDon;

class KhachHang{
    string id , name , gender , date , addr;
public:
    static KhachHang ds[21];
    static int n;
    friend istream &operator >> (istream &in , KhachHang &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_kh;
        a.id = "KH" + tmp.str();
        if(in.peek() == '\n') in.ignore();
        getline(in , a.name);
        getline(in , a.gender);
        getline(in , a.date);
        getline(in , a.addr);
        ds[n++] = a;
        return in;
    }
    string get_id(){return id;}
    string get_name(){return name;}
    string get_addr(){return addr;}
    friend class HoaDon;
};

KhachHang KhachHang::ds[21];
int KhachHang::n=0;

class MatHang{
    string id , name , dvt;
    int buy , pass;
public:
    static MatHang ds[41];
    static int n;
    friend istream &operator >> (istream &in , MatHang &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_mh;
        a.id = "MH" + tmp.str();
        if(in.peek() == '\n') in.ignore();
        getline(in , a.name);
        getline(in , a.dvt);
        string buy_str , pass_str;
        getline(in , buy_str);
        getline(in , pass_str);
        a.buy = stoi(buy_str);
        a.pass = stoi(pass_str);
        ds[n++] = a;
        return in;
    }
    string get_id(){ return id;}
    string get_name(){return name;}
    string get_dvt(){return dvt;}
    int get_buy(){return buy;}
    int get_pass(){return pass;}
    friend class HoaDon;
};

MatHang MatHang::ds[41];
int MatHang::n=0;

class HoaDon{
    string id_hd , id_kh , id_mh;
    int sl;
public:
    friend istream &operator >> (istream &in , HoaDon &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_hd;
        a.id_hd = "HD" + tmp.str();
        in >> a.id_kh >> a.id_mh >> a.sl;
        return in;
    }
    friend ostream &operator << (ostream &out , HoaDon a){
        KhachHang kh;
        MatHang mh;
        for(int i=0;i<KhachHang::n;i++){
            if(a.id_kh == KhachHang::ds[i].get_id()) kh = KhachHang::ds[i];
        }
        for(int i=0;i<MatHang::n;i++){
            if(a.id_mh == MatHang::ds[i].get_id()) mh = MatHang::ds[i];
        }
        ll sum = 1LL*a.sl*mh.get_pass();
        out << a.id_hd << " " << kh.get_name() << " " << kh.get_addr() << " " <<
        mh.get_name() << " " << mh.get_dvt() << " " << mh.get_buy() << " "
        << mh.get_pass() << " " <<  a.sl << " " << sum << endl;
        return out;
    }
};

int main(){
    int n,m,k;
    in_kh >> n;
    KhachHang dskh[n];
    for(int i=0;i<n;i++){
        in_kh >> dskh[i];
    }

    in_mh >> m;
    MatHang dsmh[m];
    for(int i=0;i<m;i++){
        in_mh >> dsmh[i];
    }
    
    in_hd >> k;
    HoaDon dshd[k];
    for(int i=0;i<k;i++){
        in_hd >> dshd[i];
    }

    for(int i=0;i<k;i++){
        cout << dshd[i];
    }
    return 0;
}