#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdio>

using namespace std;

struct SinhVien {
	//string maLop;
	string No;
	string MSSV;
	string Ten;
	string Ho;
	string Gioitinh;
	string Ngaysinh;
	string ID;
	SinhVien* pnext;
};

struct SVList {
	SinhVien* Head;
	SinhVien* Tail;
};

struct Class {
	string maLop;
	SVList* DS;
	Class* pnext;
};

struct ClassList {
	Class *Head;
	Class* Tail;
};

struct Course {
	string maMH;
	string tenMH;
	string tenLop;
	string tenGV;
	int soTin;
	int soLuongMax;
	int namHoc;
	//int thuHoc;
	string gioHoc;
	Course* pnext;
};

struct CourseList {
	Course* Head;
	Course* Tail;
};


Class* CreateClass(string a);
bool checkClassList(ClassList classlist);
void saveClassList(ClassList& classlist);
void xuatDanhSachCacLop(ClassList classlist);
void khoiTaoSVList(SVList& svlist);
void saveSVList(SVList& svlist, string a);
void khoiTaoClassList(ClassList& classlist);
void khoiTaoCourseList(CourseList& courselist);
SinhVien* DocSV(string a);
void xuatThongTinSVCuaLop(string a);
bool checkCourseList(CourseList courselist);
void saveCourseList(CourseList& courselist);
void xuatDanhSachMonHoc(CourseList courselist);
void xuatHocSinhMonHoc(string a);
void capnhatThongTinKhoaHoc(string a, CourseList& courselist);
void them1SVKhoaHoc(string a);
void xoa1SVKhoaHoc(string a, string b);
void themKhoaHoc();
void xoaKhoaHoc();
void themHocSinhVaoKhoaHoc(string a, string b);