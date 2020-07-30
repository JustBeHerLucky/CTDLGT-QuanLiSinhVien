#include "DanhSachDangKi.h"
#include "DanhSachLopTinChi.h"
#include "DanhSachMonHoc.h"
#include "DanhSachSinhVien.h"
#include "Something.h"
using namespace std;

int Menu();
void Execute(DSLTC& dsltc, DSSV& dssv, DSMH& dsmh);
int LuaChonHieuChinhDanhSachLopTinChi();
void HieuChinhDanhSachLopTinChi(DSLTC& dsltc, DSMH dsmh);
int LuaChonCapNhatSinhVien(string maLop);
void CapNhatSinhVien(DSSV& l);
void NhapDiem(DSLTC& dsltc, DSSV dssv, DSMH dsmh);