#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct SinhVien {
    string id, name, lop;
    double x, y, z;

    void nhap() {
        cin.ignore();         // bỏ xuống dòng sau khi đọc n
        getline(cin, id);
        getline(cin, name);
        getline(cin, lop);
        cin >> x >> y >> z;
    }

    void in() {
        cout << id << " " << name << " " << lop << " "
             << fixed << setprecision(1) << x << " "
             << y << " " << z << endl;
    }
};

bool cmp(SinhVien &a, SinhVien &b) {
    return a.name < b.name;
}

int main() {
    int n;
    cin >> n;
    SinhVien ds[n];
    for (int i = 0; i < n; i++) ds[i].nhap();

    sort(ds, ds + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
        ds[i].in();
    }
    return 0;
}
