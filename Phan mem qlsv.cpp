#include <bits/stdc++.h>
using namespace std;
struct Diem{
	string maSV;
	int maMon;
	float DiemCK;
	float DiemQT;
	float Diemhp;
	float GPA;
	float CPA;
};
Diem listDiem[1000];
int totalDiem = 0;
struct MonHoc{
	int maMon;
	string tenMon;
	int hocky;
	int soTC;//tinchi
};
MonHoc listMonhoc[1000];//mang chua cac mon hoc
int totalMon=0;

class Giang_Vien{
	string maGV;
	string school;//truong dien dien tu
	string khoa;//khoa dien tu
	string phong_lam_viec;
};
void menu_chinh(){
	cout<<"======================HE THONG QUAN LY SINH VIEN========================="<<endl;
	cout<<"0.thoat chuong trinh"<<endl;
	cout<<"1.Sinh Vien"<<endl;
	cout<<"2.Giang Vien"<<endl;
	cout<<"3.Phong dao tao"<<endl;
	cout<<"========================================================================="<<endl;

}
//phong dao tao
struct user{
	string username;
	string password;
	string ten;
	string MS;//ma so
	string sdt;//so dien thoai
	string lop;//ET1-10
	string ngaysinh;
	int role;//chon 1=sinh vien 2=giang vien 3=phong dao tao
};
user listUser[1000];//bien luu danh sach tai khoan
int totalUser = 0;
void tao_tai_khoan(){
	user u;
	cout<<"nhap ten tai khoan: ";
	cin>>u.username;
	cout<<"nhap mat khau ";
	cin>>u.password;
	cout<<"nhap so dien thoai ";
	cin>>u.sdt;
	cout << "Chon doi tuong (1: Sinh vien, 2: Giang vien): ";
    cin >> u.role;
    if(u.role==1){
	  cout<<"nhap ten sinh vien ";//sinh vien
      cin>>u.ten;
      cout<<"nhap ma so sinh vien ";
      cin>>u.MS;
	  cout<<"nhap lop hoc cua sinh vien ";
	  cin>>u.lop;
	  cout<<"nhap ngay sinh cua sinh vien ";
	  cin>>u.ngaysinh;}
    if(u.role==2){
      cout<<"nhap ten giang vien ";//giang vien
      cin>>u.ten;
      cout<<"nhap ma so giang vien ";
      cin>>u.MS;
      cout<<"nhap ngay sinh cuar giang vien ";
      cin>>u.ngaysinh;
}
    listUser[totalUser++] = u;
    cout << ">>> Tao tai khoan thanh cong!\n";
}
void xoa_tai_khoan() {
    string tk;
    int loai;

    cout << "Nhap ten tai khoan muon xoa: ";
    cin >> tk;
    cout << "Loai doi tuong (1: SV, 2: GV): ";
    cin >> loai;

    for (int i = 0; i < totalUser; i++) {
        if (listUser[i].username == tk && listUser[i].role == loai) {
            for (int j = i; j < totalUser - 1; j++)
                listUser[j] = listUser[j + 1];

            totalUser--;
            cout << "Xoa tai khoan thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay tai khoan!\n";
}
struct PhanCong {
    string maGV;
    int maMon;
    string tenmon;
};

PhanCong dsPhanCong[100];
int totalPC = 0;
void phan_cong_mon() {
    PhanCong pc;
    cout << "Nhap ma giang vien: ";
    cin >> pc.maGV;

    cout << "Nhap ma mon hoc: ";
    cin >> pc.maMon;

    cout << "Nhap ten mon: ";
    cin >> pc.tenmon;

    dsPhanCong[totalPC++] = pc;
    cout << " Phan cong mon hoc thanh cong!\n";
}
void menu_phong_daotao() {
    int chon3;

    do {
        cout << "\n========== MENU PHONG DAO TAO ==========\n";
        cout << "1. Tao tai khoan\n";
        cout << "2. Xoa tai khoan\n";
        cout << "3. Phan cong mon hoc cho giang vien\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon3;

        switch (chon3) {
            case 1: tao_tai_khoan(); break;
            case 2: xoa_tai_khoan(); break;
            case 3: phan_cong_mon(); break;
            case 0: break;
            default: cout << "Lua chon khong hop le!\n";
        }

    } while (chon3 != 0);
}
string adminUser = "admin";
string adminPass = "123456";

bool dang_nhap_phong_daotao() {
    string user, pass;
    cout << "\n===== DANG NHAP PHONG DAO TAO =====\n";
    cout << "Nhap username: ";
    cin >> user;
    cout << "Nhap password: ";
    cin >> pass;

    if (user == adminUser && pass == adminPass) {
        cout << ">>> Dang nhap thanh cong!\n";
        return true;
    }

    cout << "Sai tai khoan hoac mat khau!\n";
    return false;
}
//sinh vien
int a;//thu tu sinh vien trong mang
int login_sinhvien(){
	string user,pass;
	cout<<"==================DANG NHAP SINH VIEN=====================\n";
	while (true){
		cout<<"nhap tai khoan (nhap 0 de thoat) ";
		cin>>user;
		if(user=="0"){
			cout << "Thoat khoi man hinh dang nhap.\n";
            return -1;
		}
		cout<<"nhap mat khau ";
		cin>>pass;
		for(int i=0;i<totalUser;i++){
			if(listUser[i].username==user&&
			listUser[i].password==pass&&
			listUser[i].role==1){
				cout <<"dang nhap thanh cong";
				return i;
			}
			}
			cout<<"sai ten dang nhap hoac mat khau,vui long nhap lai\n";
	}
	}
void xem_diem_so(string maSV) {
    cout << "\n===== DIEM SO CAC MON CUA SINH VIEN =====\n";

    for (int i = 0; i < totalDiem; i++) {

        if (listDiem[i].maSV == maSV) {

            // ten mon hoc
            string tenMon;
            int soTC;
            for (int j = 0; j < totalMon; j++) {
                if (listMonhoc[j].maMon == listDiem[i].maMon) {
                    tenMon = listMonhoc[j].tenMon;
                    soTC = listMonhoc[j].soTC;
                }
            }

            cout << "Mon: " << tenMon << endl;
            cout << "Ma mon: " << listDiem[i].maMon << endl;
            cout << "So tin chi: " << soTC << endl;
            cout << "QT: " << listDiem[i].DiemQT << endl;
            cout << "CK: " << listDiem[i].DiemCK << endl;
            cout << "Diem hoc phan: " << listDiem[i].Diemhp << endl;
            cout << "-------------------------------------\n";
        }
    }
}

void xuat_thong_tin(string maSV) {
    for (int i = 0; i < totalUser; i++) {
        if (listUser[i].MS == maSV && listUser[i].role == 1) {
            cout << "\n===== THONG TIN CA NHAN =====\n";
            cout << "Ho ten      : " << listUser[i].ten << endl;
            cout << "MSSV        : " << listUser[i].MS << endl;
            cout << "So dien thoai: " << listUser[i].sdt << endl;
            cout << "Lop         : " << listUser[i].lop << endl;
            cout << "Ngay sinh   : " << listUser[i].ngaysinh << endl;
            return;
        }
    }
}

void xuat_thong_tin_sinh_vien_theo_lop(int a){
	int j=1;
	for (int i;i<totalUser;i++){
	    if(listUser[i].lop==listUser[a].lop&&listUser[i].role==listUser[a].role){
	    	cout<<"stt"<<j;
	    	cout<<"ten sinh vien "<<listUser[i].ten;
	    	cout<<"mssv: "<<listUser[i].MS;
	    	cout<<"sdt: "<<listUser[i].sdt;
	    	cout<<"ngay sinh:"<<listUser[i].ngaysinh;
	    	j++;
		}
	}
}
void sua_thong_tin_sinhvien(int index) {

    int chon;
    do {
        cout << "\n===== CAP NHAT THONG TIN CA NHAN =====\n";
        cout << "1. Doi ho ten\n";
        cout << "2. Doi so dien thoai\n";
        cout << "3. Doi ngay sinh\n";
        cout << "4. Doi lop\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> chon;

        switch(chon) {

            case 1:
                cout << "Nhap ho ten moi: ";
                cin.ignore();
                getline(cin, listUser[index].ten);
                cout << ">>> Cap nhat thanh cong!\n";
                break;

            case 2:
                cout << "Nhap so dien thoai moi: ";
                cin >> listUser[index].sdt;
                cout << ">>> Cap nhat thanh cong!\n";
                break;

            case 3:
                cout << "Nhap ngay sinh moi (dd/mm/yyyy): ";
                cin >> listUser[index].ngaysinh;
                cout << ">>> Cap nhat thanh cong!\n";
                break;

            case 4:
                cout << "Nhap lop moi: ";
                cin >> listUser[index].lop;
                cout << ">>> Cap nhat thanh cong!\n";
                break;

            case 0:
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);
}
void tim_kiem_theo_mssv() {
    string mssv;
    cout << "Nhap MSSV can tim: ";
    cin >> mssv;

    bool found = false;

    for (int i = 0; i < totalUser; i++) {
        if (listUser[i].role == 1 && listUser[i].MS == mssv) {
            cout << "\n===== THONG TIN SINH VIEN =====\n";
            cout << "Ho ten      : " << listUser[i].ten << endl;
            cout << "MSSV        : " << listUser[i].MS << endl;
            cout << "Lop         : " << listUser[i].lop << endl;
            cout << "So dien thoai: " << listUser[i].sdt << endl;
            cout << "Ngay sinh   : " << listUser[i].ngaysinh << endl;
            cout << "-------------------------------------\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Khong tim thay sinh vien voi MSSV nay!\n";
}
void tim_kiem_theo_sdt() {
    string sdt;
    cout << "Nhap so dien thoai can tim: ";
    cin >> sdt;

    bool found = false;

    for (int i = 0; i < totalUser; i++) {
        if (listUser[i].role == 1 && listUser[i].sdt == sdt) {
            cout << "\n===== THONG TIN SINH VIEN =====\n";
            cout << "Ho ten      : " << listUser[i].ten << endl;
            cout << "MSSV        : " << listUser[i].MS << endl;
            cout << "Lop         : " << listUser[i].lop << endl;
            cout << "So dien thoai: " << listUser[i].sdt << endl;
            cout << "Ngay sinh   : " << listUser[i].ngaysinh << endl;
            cout << "-------------------------------------\n";
            found = true;
        }
    }

    if (!found)
        cout << "Khong tim thay sinh vien voi so dien thoai nay!\n";
}
void tim_kiem_sinh_vien() {
    int chon;

    do {
        cout << "\n===== TIM KIEM SINH VIEN =====\n";
        cout << "1. Tim theo MSSV\n";
        cout << "2. Tim theo SDT\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon) {
            case 1:
                tim_kiem_theo_mssv();
                break;
            case 2:
                tim_kiem_theo_sdt();
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);
}
bool da_dang_ky_mon(string maSV, int maMon) {//kiem tra xem sinh vien dang ki mon chua
    for (int i = 0; i < totalDiem; i++) {
        if (listDiem[i].maSV == maSV && listDiem[i].maMon == maMon) {
            return true;
        }
    }
    return false;
}
void hien_thi_danh_sach_mon() {
    cout << "\n===== DANH SACH MON HOC =====\n";
    for (int i = 0; i < totalMon; i++) {
        cout << "Ma mon: " << listMonhoc[i].maMon << " | "
             << "Ten mon: " << listMonhoc[i].tenMon << " | "
             << "So TC: " << listMonhoc[i].soTC << endl;
    }
}
void dang_ky_hoc_phan(int index) {
    string maSV = listUser[index].MS;
    int maMon;

    hien_thi_danh_sach_mon();

    cout << "\nNhap ma mon muon dang ky: ";
    cin >> maMon;

    bool found = false;//kiem tra co ton tai ma mon khong
    for (int i = 0; i < totalMon; i++) {
        if (listMonhoc[i].maMon == maMon) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << ">>> Ma mon khong ton tai!\n";
        return;
    }

    if (da_dang_ky_mon(maSV, maMon)) {//kiem tra xem dki chua
        cout << ">>> Ban da dang ky mon nay roi!\n";
        return;
    }

    // hop le-> th�m v�o listDiem
    Diem d;
    d.maSV = maSV;
    d.maMon = maMon;
    d.DiemQT = 0;
    d.DiemCK = 0;
    d.Diemhp = 0;

    listDiem[totalDiem++] = d;

    cout << ">>> Dang ky hoc phan thanh cong!\n";
}

void menu_sinhvien(int index) {
    int chon;

    do {
        cout << "\n===== MENU SINH VIEN =====\n";
        cout << "1. Xuat thong tin ca nhan\n";
        cout << "2. Xem diem cac mon hoc\n";
        cout << "3. Xem sinh vien cung lop\n";
        cout << "4.Sua thong tin ca nhan\n";
        cout << "5. Tim kiem sinh vien\n";
        cout << "6.�ang ki hoc phan\n ";
        cout << "0. Dang xuat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;

        switch(chon) {

            case 1:
                xuat_thong_tin(listUser[index].MS);
                break;

            case 2:
                xem_diem_so(listUser[index].MS);
                break;

            case 3:
                xuat_thong_tin_sinh_vien_theo_lop(index);
                break;

            case 4:sua_thong_tin_sinhvien(index);

            case 5: tim_kiem_sinh_vien();

            case 6:dang_ky_hoc_phan(index);

            case 0:
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);
}

void dangnhap_sinhvien_run() {
    int index = login_sinhvien();
    if(index>=0)
    menu_sinhvien(index);
}
//giang vien
int login_giangvien(){
	string user,pass;
	cout<<"==================DANG NHAP GIANG VIEN=====================\n";
	while (true){
		cout<<"nhap tai khoan (nhap 0 de thoat) ";
		cin>>user;
		if(user=="0"){
			cout << "Thoat khoi man hinh dang nhap.\n";
            return -1;
		}
		cout<<"nhap mat khau ";
		cin>>pass;
		for(int i=0;i<totalUser;i++){
			if(listUser[i].username==user&&
			listUser[i].password==pass&&
			listUser[i].role==2){
				cout <<"dang nhap thanh cong";
				return i;
			}
			}
			cout<<"sai ten dang nhap hoac mat khau,vui long nhap lai\n";
	}
	}
void sua_thong_tin_giangvien(int index) {

    int chon;
    do {
        cout << "\n===== CAP NHAT THONG TIN CA NHAN =====\n";
        cout << "1. Doi ho ten\n";
        cout << "2. Doi so dien thoai\n";
        cout << "3. Doi ngay sinh\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> chon;

        switch(chon) {

            case 1:
                cout << "Nhap ho ten moi: ";
                cin.ignore();
                getline(cin, listUser[index].ten);
                cout << ">>> Cap nhat thanh cong!\n";
                break;

            case 2:
                cout << "Nhap so dien thoai moi: ";
                cin >> listUser[index].sdt;
                cout << ">>> Cap nhat thanh cong!\n";
                break;

            case 3:
                cout << "Nhap ngay sinh moi (dd/mm/yyyy): ";
                cin >> listUser[index].ngaysinh;
                cout << ">>> Cap nhat thanh cong!\n";
                break;

            case 0:
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);
}
void them_diem() {
    Diem d;
    cout << "Nhap ma sinh vien: ";
    cin >> d.maSV;
    cout << "Nhap ma mon hoc: ";
    cin >> d.maMon;
    do {
        cout << "Nhap diem QT (0-10, chia het 0.5): ";
        cin >> d.DiemQT;
    } while (d.DiemQT < 0 || d.DiemQT > 10 || ((int)(d.DiemQT*10) % 5 != 0));
    do {
        cout << "Nhap diem CK (0-10, chia het 0.5): ";
        cin >> d.DiemCK;
    } while (d.DiemCK < 0 || d.DiemCK > 10 || ((int)(d.DiemCK*10) % 5 != 0));

    d.Diemhp = 0.3 * d.DiemQT + 0.7 * d.DiemCK;

    listDiem[totalDiem++] = d;

    cout << ">>> Them diem thanh cong!\n";
}
void xuat_thong_tin_giangvien(string maGV) {
    for (int i = 0; i < totalUser; i++) {
        if (listUser[i].MS == maGV && listUser[i].role == 2) {
            cout << "\n===== THONG TIN CA NHAN =====\n";
            cout << "Ho ten      : " << listUser[i].ten << endl;
            cout << "MSGV        : " << listUser[i].MS << endl;
            cout << "So dien thoai: " << listUser[i].sdt << endl;
            cout << "Ngay sinh   : " << listUser[i].ngaysinh << endl;
            cout <<"Cac mon duoc phan cong "<<endl;
            for (int j=0;j<totalPC;j++){
            	if(dsPhanCong[j].maGV==maGV){
            		cout << j+1 <<"." <<"Ten mon: "<< dsPhanCong[j].tenmon << "  Ma mon: " << dsPhanCong[j].maMon << endl;
				}

			}
            return;
        }
    }
}
void gv_xem_sinh_vien_theo_mon(string maGV) {

    cout << "\n===== CAC MON DUOC PHAN CONG =====\n";

    // 1. Hien thi cac mon duoc phan cong
    int dsMon[50];
    int soMon = 0;

    for (int i = 0; i < totalPC; i++) {
        if (dsPhanCong[i].maGV == maGV) {

            cout << soMon + 1 << ". "
                 << dsPhanCong[i].tenmon
                 << " | Ma mon: " << dsPhanCong[i].maMon << endl;

            dsMon[soMon] = dsPhanCong[i].maMon;
            soMon++;
        }
    }

    if (soMon == 0) {
        cout << "Giang vien chua duoc phan cong mon nao!\n";
        return;
    }

    // chon mon
    int chon;
    cout << "\nChon mon de xem danh sach sinh vien: ";
    cin >> chon;

    if (chon < 1 || chon > soMon) {
        cout << "Lua chon khong hop le!\n";
        return;
    }

    int maMon_chon = dsMon[chon - 1];

    cout << "\n===== DANH SACH SINH VIEN DANG KY MON NAY =====\n";

    int stt = 1;
    bool found = false;

    // 3. T�m trong listDiem xem sinh vi�n n�o dang k� m�n n�y
    for (int i = 0; i < totalDiem; i++) {

        if (listDiem[i].maMon == maMon_chon) {

            string mssv = listDiem[i].maSV;

            // t�m th�ng tin sinh vi�n
            for (int u = 0; u < totalUser; u++) {
                if (listUser[u].MS == mssv && listUser[u].role == 1) {

                    cout << stt++ << ". "
                         << listUser[u].ten
                         << " | MSSV: " << listUser[u].MS
                         << " | Lop: " << listUser[u].lop << endl;

                    found = true;
                }
            }
        }
    }

    if (!found) {
        cout << "Khong co sinh vien nao dang ky mon nay.\n";
    }
}
void menu_giangvien(int index) {

    int chon;

    do {
        cout << "\n=========== MENU GIANG VIEN ===========\n";
        cout << "1. Xem thong tin ca nhan\n";
        cout << "2. Cap nhat thong tin ca nhan\n";
        cout << "3. Nhap diem cho sinh vien\n";
        cout << "4. Xem danh sach sinh vien theo mon day\n";
        cout << "0. Dang xuat\n";
        cout << "========================================\n";
        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon) {

            case 1:
                xuat_thong_tin_giangvien(listUser[index].MS);
                break;

            case 2:
                sua_thong_tin_giangvien(index);
                break;

            case 3:
                them_diem();
                break;

            case 4:
                gv_xem_sinh_vien_theo_mon(listUser[index].MS);
                break;

            case 0:
                cout << "Dang xuat thanh cong!\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
                break;
        }

    } while (chon != 0);
}
void dangnhap_giangvien_run() {
    int index = login_giangvien();  // lay vi tri trong listUser
    if(index>=0)
    menu_giangvien(index);
}
int main(){
	int chon;
	chon=0;
	do{
		menu_chinh();
		cout<<"nhap lua chon cua ban ";
		cin>>chon;
		switch(chon){
			case 1: dangnhap_sinhvien_run();
			break;

		    case 2: dangnhap_giangvien_run();
			break;

			case 3:if(dang_nhap_phong_daotao()){
			menu_phong_daotao();}
				break;

			 case 0: break;
            default: cout << "Lua chon khong hop le!\n";
		}
	}while(chon!=0);

	return 0;
}
