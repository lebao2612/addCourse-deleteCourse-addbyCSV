#include"header.h"
//hello
int main() {
	SVList DS;
	fstream f;
	//xuatThongTinLop(f,DS);
	ClassList classlist;
	CourseList courselist;
	khoiTaoClassList(classlist);
	khoiTaoCourseList(courselist);
	saveClassList(classlist);
	saveCourseList(courselist);
	Course* p = courselist.Head;
	xuatDanhSachMonHoc(courselist);
	//xoaKhoaHoc();
	//xuatHocSinhMonHoc("ADD00031");
	//capnhatThongTinKhoaHoc("ADD00031", courselist);
	//xuatDanhSachCacLop(classlist);
	//xuatThongTinSVCuaLop("TNT1");
	//them1SVKhoaHoc("ADD00031");
	//xoa1SVKhoaHoc("ADD00031", "22120022");
	themHocSinhVaoKhoaHoc("PHY00081", "student.csv");
}