#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;
using ll = long long;

int idxKhachHang = 0 , idxMatHang = 0 , idxHoaDon = 0;

class HoaDon;
class KhachHang{
    string id = "" , name , gender , date , addr;
public:
    static KhachHang ds[25];
    static int n;

    friend istream &operator >> (istream &in , KhachHang &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idxKhachHang;
        a.id = "KH" + tmp.str();
        //loại bỏ \n ở main
        if(in.peek() == '\n') in.ignore();
        //dùng getline thống nhất để tránh rối loạn cin vs getline
        getline(in , a.name);
        getline(in , a.gender);
        getline(in , a.date);
        getline(in , a.addr);
        ds[n++] = a;
        return in;
    }
    string getID_kh(){ return id;}
    string getName_kh(){return name;}
    string getAddr_kh(){return addr;}
    friend class HoaDon;
};

KhachHang KhachHang::ds[25];
int KhachHang::n = 0;
class MatHang{
    string id = "", name , dvt;
    int buy , pass;
public:
    static MatHang ds[45];
    static int n;

    friend istream &operator >> (istream &in , MatHang &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idxMatHang;
        a.id = "MH" + tmp.str();
        if(in.peek() == '\n') in.ignore();
        getline(in , a.name);
        getline(in , a.dvt);
        string buy_tmp , pass_tmp;
        getline(in , buy_tmp);
        getline(in , pass_tmp);
        a.buy = stoi(buy_tmp);
        a.pass = stoi(pass_tmp);
        ds[n++] = a;
        return in;
    }
    string getID_mh(){return id;}
    string getName_mh(){return name;}
    string getDVT_mh(){return dvt;}
    int get_buy(){return buy;}
    int get_pass(){return pass;}
    friend class HoaDon;
};

MatHang MatHang::ds[45];
int MatHang::n = 0;
class HoaDon{
    string id_hd = "" , id_kh , id_mh;
    int sl;
public:
    friend istream &operator >> (istream &in , HoaDon &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idxHoaDon;
        a.id_hd = "HD" + tmp.str();
        if(in.peek() == '\n') in.ignore();
        in >> a.id_kh >> a.id_mh >> a.sl;
        return in;
    }
    friend ostream &operator << (ostream &out , HoaDon &a){
        KhachHang *kh = nullptr;
        MatHang *mh = nullptr;
        for(int i=0;i<KhachHang::n;i++){
            if(a.id_kh == KhachHang::ds[i].getID_kh()) kh = &KhachHang::ds[i];
        }
        for(int i=0;i<MatHang::n;i++){
            if(a.id_mh == MatHang::ds[i].getID_mh()) mh = &MatHang::ds[i];
        }
        ll sum = 1LL * a.sl * mh->get_pass();
        out << a.id_hd << " " << kh->getName_kh() << " " << kh->getAddr_kh()
        << " " << mh->getName_mh() << " " << mh->getDVT_mh() << " " <<
        mh->get_buy() << " " << mh->get_pass() << " " << a.sl << " " << 
        sum << endl;
        return out;
    }
};

int main(){
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    int N,M,K,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> dskh[i];
    cin >> M;
    for(i=0;i<M;i++) cin >> dsmh[i];
    cin >> K;
    for(i=0;i<K;i++) cin >> dshd[i];
    
    for(i=0;i<K;i++) cout << dshd[i];
    return 0;
}
