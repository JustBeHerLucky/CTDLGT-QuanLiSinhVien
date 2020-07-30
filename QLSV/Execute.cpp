#include "Execute.h"

int Menu()
{
	system("cls");
	cout << "\t1.Hieu chinh danh sach lop tin chi \n";
	cout << "\t2.In danh sach sinh vien da dang ki lop tin chi \n";
	cout << "\t3.Cap nhat sinh vien cua mot lop \n";
	cout << "\t4.In danh sach sinh vien thuoc mot lop\n";
	cout << "\t5.Hieu chinh mon hoc\n";
	cout << "\t6.In danh sach mon hoc\n";
	cout << "\t7.Dang ky lop tin chi\n";
	cout << "\t8.Nhap diem\n";
	cout << "\t9.In bang diem mon hoc cua mot lop tin chi\n";
	cout << "\t10.In bang diem trung binh theo lop\n";
	cout << "\t0.Thoat\n";
	int luachon;
	cout << "\tLua chon:";
	cin >> luachon;
    return luachon;
}

int LuaChonHieuChinhDanhSachLopTinChi() {
	system("cls");
	cout << "\t1. Them lop tin chi\n";
	cout << "\t2. Sua lop tin chi\n";
	cout << "\t3. Xoa lop tin chi\n";
	cout << "\t0. Quay lai\n";
	int luachon;
	cout << "\tLua chon:";
	cin >> luachon;
	return luachon;
}

void HieuChinhDanhSachLopTinChi(DSLTC& dsltc, DSMH dsmh) {
	while (true) {
		switch (LuaChonHieuChinhDanhSachLopTinChi())
		{
		case 1: {
			LopTinChi* ltc = NhapLopTinChi(dsltc.DS, dsmh);
			ThemLopTinChi(dsltc.DS, ltc);
			dsltc.SL++;
			system("pause");
			break;
		}
		case 2: {
			InDanhSach(dsltc);
			SuaLopTinChi(dsltc, dsmh);
			system("pause");
			break;
		}
		case 3: {
			InDanhSach(dsltc);
			XoaLopTinChi(dsltc);
			system("pause");
			break;
		}
		case 0: {
			return;
		}
		}
	}
}

int LuaChonInDanhSachSinhVienDK() {
	system("cls");
	cout << "\t1. In danh sach sinh vien dang ki lop tin chi theo nien khoa\n";
	cout << "\t2. In danh sach sinh vien dang ki lop tin chi theo nhom\n";
	cout << "\t3. In danh sach sinh vien dang ki lop tin chi theo hoc ky\n";
	cout << "\t4. In danh sach sinh vien dang ki lop tin chi theo ma mon hoc\n";
	cout << "\t0. Thoat\n";
	int luachon;
	cout << "\tLua chon:";
	cin >> luachon;
	return luachon;
}

void InDanhSachSinhVienDaDangKy(DSLTC dsltc, DSSV dssv, DSMH dsmh) {
	while (true) {
		switch (LuaChonInDanhSachSinhVienDK())
		{
		case 1: {
			system("cls");
			cout << "\n\tNhap nien khoa: ";
			string nienKhoa;
			cin.ignore();
			getline(cin, nienKhoa);
			InDanhSachTheoNienKhoa(dsltc.DS, dssv, nienKhoa);
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			cout << "\n\tNhap nhom: ";
			int nhom;
			cin >> nhom;
			InDanhSachTheoNhom(dsltc.DS, dssv, nhom);
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			cout << "\n\tNhap hoc ky: ";
			int hocKy;
			cin >> hocKy;
			InDanhSachTheoHocKy(dsltc.DS, dssv, hocKy);
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			cout << "\n\tNhap ma mon hoc: ";
			string maMon;
			cin.ignore();
			getline(cin, maMon);
			while (!MaMHTonTai(dsmh, maMon)) {
				cout << "*****Ma mon hoc khong ton tai! Nhap lai: ";
				getline(cin, maMon);
			}
			InDanhSachTheoMaMon(dsltc.DS, dssv, maMon);
			system("pause");
			break;
		}
		case 0: {
			return;
		}
		default:
			break;
		}
	}
}

int LuaChonCapNhatSinhVien(string maLop) {
	system("cls");
	cout << "\n\t====Hieu chinh lop " << maLop << "====\n";
	cout << "\n\t1.Them sinh vien!";
	cout << "\n\t2.Xoa sinh vien!";
	cout << "\n\t3.Sua sinh vien!";
	cout << "\n\t0.Thoat!";
	cout << "\n\tLua chon:";
	int luachon;
	cin >> luachon;
	return luachon;
}

void CapNhatSinhVien(DSSV& l) {
	system("cls");
	string maLop;
	cin.ignore();
	cout << "\n\tNhap lop can hieu chinh: ";
	getline(cin, maLop);
	while (true) {
		switch (LuaChonCapNhatSinhVien(maLop))
		{
		case 1: {
			while (true) {
				system("cls");
				if (!ThemSinhVienVaoLop(l, maLop))
				{
					cout << "\n\t===Ket thuc nhap sinh vien===\n";
					system("pause");
					break;
				}
			}
			break;
		}
		case 2: {
			XoaSinhVien(l,maLop);
			break;
		}
		case 3: {
			if (SuaSVTrongLop(l)) {
				cout << "\n\t=====Sua thanh cong!=====\n";
				system("pause");
			}
			break;
		}
		case 0: {
			return;
		}
		default:
			cout << "\n\tLua chon khong hop le\n";
			system("pause");
			break;
		}	
	}
	SapXepDanhSachSV(l);
}

int LuaChonHieuChinhMonHoc() {
	system("cls");
	cout << "\n\t===================Hieu chinh mon hoc================";
	cout << "\n\t1.Them mon hoc";
	cout << "\n\t2.Sua mon hoc";
	cout << "\n\t3.Xoa mon hoc";
	cout << "\n\t0.Thoat";
	cout << "\n\tLua chon:";
	int luachon;
	cin >> luachon;
	return luachon;
}

void HieuChinhDanhSachMonHoc(DSMH& dsmh) {
	while (true) {
		switch (LuaChonHieuChinhMonHoc())
		{
		case 1: {
			system("cls");
			MH* mh = NhapThongTinMonHoc(dsmh);
			ThemMonHoc(dsmh, mh);
			cout << "\n\t*****Them mon hoc thanh cong*****";
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			InDSMonHoc(dsmh);
			SuaMonHoc(dsmh);
			cout << "\n\t*****Sua mon hoc thanh cong*****";
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			InDSMonHoc(dsmh);
			XoaMonHoc(dsmh);
			cout << "\n\t*****Xoa mon hoc thanh cong*****";
			system("pause");
			break;
		}
		case 0: {
			return;
		}
		default:
			break;
		}
	}
}

int LuaChonDangKiLopTinChi() {
	system("cls");
	cout << "\n\t1.Dang ki lop tin chi!";
	cout << "\n\t2.Huy dang ki lop tin chi";
	cout << "\n\t0.Thoat";
	cout << "\n\tLua chon: ";
	int luachon;
	cin >> luachon;
	return luachon;
}

void DangKiLopTinChi(DSLTC& dsltc, DSSV& dssv, DSMH& dsmh)
{
	cout << "\n\tNhap ma so sinh vien:";
	string maSV;
	cin.ignore();
	getline(cin, maSV);
	while (!MSSVDaTontai(dssv, maSV)) {
		cout << "\n\t*****MA so sinh vien khong ton tai. Nhap lai: ";
		getline(cin, maSV);
	}

	while (true) {
		switch (LuaChonDangKiLopTinChi())
		{
		case 1: {
			cout << "\n\tNhap nien khoa: ";
			string nienKhoa;
			cin.ignore();
			getline(cin, nienKhoa);
			cout << "\n\tNhap hoc ky: ";
			int hocKy;
			cin >> hocKy;

			while (true) {
				system("cls");
				cout << "\n\t=====Danh sach cac lop co the dang ki=====\n";
				InDanhSachCacLopCoTheDangKi(dsltc.DS, nienKhoa, hocKy, maSV);
				cout << "\n\tNhap ma lop muon dang ki (Nhap -1 de ket thuc):";
				int maLop;
				cin >> maLop;
				if (maLop == -1) break;
				while (!LopCoTheDangKi(dsltc.DS, maLop, nienKhoa, hocKy) || LopCoSinhVienX(dsltc.DS, maSV, maLop) || LopDaFULL(dsltc.DS, maLop)) {
					cout << "\n\tKhong the dang ki lop nay! Nhap lai ma lop: ";
					cin >> maLop;
					if (maLop == -1) break;
				}
				SinhVienDangKiLop(dsltc.DS, maLop, maSV);
			}
			break;
		}
		case 2: {
			int check = 0;
			InCacLopDaDangKi(dsltc.DS, maSV, check);
			if (check == 0) {
				cout << "\n\t***********Sinh vien chua dang ki lop tin chi nao*************";
			}
			else {
				cout << "\n\tNhap ma lop muon huy dang ki:";
				int maLop;
				cin >> maLop;
				if (!LopCoSinhVienX(dsltc.DS, maSV, maLop)) {
					cout << "\n\t***********Sinh vien chua dang ki lop tin chi nay.*************";
				}
				else {
					XoaDangKiSinhVien(dsltc.DS, maLop, maSV);
				}
			}
			break;
		}
		case 0: {
			return;
		}
		default:
			break;
		}
	}

}

void NhapDiem(DSLTC& dsltc, DSSV dssv, DSMH dsmh) {
	cout << "\n\tNhap nien khoa: ";
	string nienKhoa;
	cin.ignore();
	getline(cin, nienKhoa);

	cout << "\tNhap hoc ky: ";
	int hocKi; cin >> hocKi;

	cout << "\tNhap nhom: ";
	int nhom; cin >> nhom;

	cout << "\tNhap ma mon hoc: ";
	string maMH; 
	cin.ignore();
	getline(cin, maMH);
	while (!MaMHTonTai(dsmh, maMH)) {
		cout << "*****Ma mon hoc khong ton tai! Nhap lai: ";
		getline(cin, maMH);
	}

	NhapDiemChoCacSinhVien(dsltc.DS, dssv, nienKhoa, hocKi, nhom, maMH);
}

void InBangDiem(DSLTC dsltc, DSSV dssv, DSMH dsmh) {
	cout << "\n\tNhap nien khoa: ";
	string nienKhoa;
	cin.ignore();
	getline(cin, nienKhoa);

	cout << "\tNhap hoc ky: ";
	int hocKi; cin >> hocKi;

	cout << "\tNhap nhom: ";
	int nhom; cin >> nhom;

	cout << "\tNhap ma mon hoc: ";
	string maMH;
	cin.ignore();
	getline(cin, maMH);
	while (!MaMHTonTai(dsmh, maMH)) {
		cout << "*****Ma mon hoc khong ton tai! Nhap lai: ";
		getline(cin, maMH);
	}

	InDiemChoCacSinhVien(dsltc.DS, dssv, nienKhoa, hocKi, nhom, maMH);
	system("pause");
}

void InDiemTrungBinh(DSLTC dsltc, DSSV dssv, DSMH dsmh) {
	cout << "\tNhap ma lop: "; 
	string maLop;
	cin.ignore();
	getline(cin, maLop);
	int i = 0;
	for (SV* k = dssv.pHead; k != NULL; k = k->pNext) {
		if (k->maLop.compare(maLop) == 0) {
			cout << "STT: " << ++i;
			InSinhVienTheoMSSV(dssv, k->maSV);
			cout << "\tDiem TB: " << TinhDiemTB1SV(dsltc.DS, dsmh, k->maSV) << endl;
		}
	}
	system("pause");
}

void Execute(DSLTC& dsltc, DSSV& dssv, DSMH& dsmh) {
	while (true) {
		switch (Menu())
		{
		case 1: {
			system("cls");
			HieuChinhDanhSachLopTinChi(dsltc, dsmh);
			break;
		}
		case 2: {
			system("cls");
			InDanhSachSinhVienDaDangKy(dsltc, dssv, dsmh);
			break;
		}
		case 3: {
			system("cls");
			CapNhatSinhVien(dssv);
			break;
		}
		case 4: {
			InSinhVienThuocLopA(dssv);
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			SapXepMonHoc(dsmh);
			HieuChinhDanhSachMonHoc(dsmh);
			SapXepMonHoc(dsmh);
			break;
		}
		case 6: {
			system("cls");
			SapXepMonHoc(dsmh);
			InDSMonHoc(dsmh);
			system("pause");
			break;
		}
		case 7: {
			system("cls");
			DangKiLopTinChi(dsltc, dssv, dsmh);
			break;
		}
		case 8: {
			system("cls");
			NhapDiem(dsltc, dssv, dsmh);
			break;
		}
		case 9: {
			system("cls");
			InBangDiem(dsltc, dssv, dsmh);
			break;
		}
		case 10: {
			system("cls");
			InDiemTrungBinh(dsltc, dssv, dsmh);
			break;
		}
		case 0: {
			SaveDSLTC(dsltc);
			SaveDSMH(dsmh);
			SaveDSSV(dssv);
			SaveDSDK(dsltc);
			exit(0);	
		}
		default:
			break;
		}
	}
}