#include"header.h"

void khoiTaoSVList(SVList& svlist) {
	svlist.Head = NULL;
	svlist.Tail = NULL;
}

void khoiTaoClassList(ClassList& classlist) {
	classlist.Head = NULL;
	classlist.Tail = NULL;
}

void khoiTaoCourseList(CourseList& courselist) {
	courselist.Head = NULL;
	courselist.Tail = NULL;
}

//Doc sinh vien tu file
SinhVien* DocSV(string a) {
	fstream f;
	f.open(a);
	SinhVien* p = new SinhVien;
	getline(f, p->No, ',');
	getline(f, p->MSSV, ',');
	getline(f, p->Ten, ',');
	getline(f, p->Ho, ',');
	getline(f, p->Gioitinh, ',');
	getline(f, p->Ngaysinh, ',');
	getline(f, p->ID, '\n');
	p->pnext = NULL;
	return p;
}

// add sinh vien vao danh sach
void addSV(SVList& DS, SinhVien* sv) {
	if (sv == NULL)
		return;
	if (DS.Head == NULL) {
		DS.Head = sv;
		DS.Tail = sv;
	}
	else {
		DS.Tail->pnext = sv;
		DS.Tail = sv;
	}
}

//add lop hoc vao danh sach lop hoc
void addClass(ClassList& classlist, Class* iclass) {
	if (iclass == NULL)
		return;
	if (classlist.Head == NULL) {
		classlist.Head = iclass;
		classlist.Tail = iclass;
	}
	else {
		classlist.Tail->pnext = iclass;
		classlist.Tail = iclass;
	}
}

//add khoa hoc vao danh sach khoa hoc
void addCourse(CourseList& courselist, Course* course) {
	if (course == NULL)
		return;
	if (courselist.Head == NULL) {
		courselist.Head = course;
		courselist.Tail = course;
	}
	else {
		courselist.Tail->pnext = course;
		courselist.Tail = course;
	}
}

//xoa sinh vien
void xoaSV(SVList& DS, SinhVien* sv) {
	if (DS.Head == NULL)
		return;
	else if (DS.Head == sv) {
		DS.Head = DS.Head->pnext;
		delete sv;
	}
	else if (DS.Head == sv && DS.Tail == sv) {
		DS.Head = DS.Tail = NULL;
		delete sv;
	}
	else {
		SinhVien* p = DS.Head;
		while (p->pnext != sv) {
			p = p->pnext;
		}
		p->pnext = sv->pnext;
		delete sv;
	}
}

//xoa khoa hoc
void xoaCourse(CourseList& courselist, Course* course) {
	if (courselist.Head == NULL)
		return;
	else if (courselist.Head == course) {
		courselist.Head = courselist.Head->pnext;
		delete course;
	}
	else if (courselist.Head == course && courselist.Tail == course) {
		courselist.Head = courselist.Tail = NULL;
		delete course;
	}
	else {
		Course* p = courselist.Head;
		while (p->pnext != course) {
			p = p->pnext;
		}
		p->pnext = course->pnext;
		delete course;
	}
}

Class* CreateClass(string a) {
	Class* newClass = new Class;
	newClass->maLop = a;
	newClass->pnext = NULL;
	return newClass;
}


//CHECK CLASSLIST 
bool checkClassList(ClassList classlist) {
	if (classlist.Head == NULL) {
		return true;
	}
	return false;
}


//SAVE CLASSLIST
void saveClassList(ClassList& classlist) {
	fstream f;
	f.open("ClassList.csv");
	if (f.fail()) {
		cout << "Khong the mo duoc file" << endl;
		return;
	}
	while (!f.eof()) {
		string a;
		f >> a;
		Class* newClass = CreateClass(a);
		if (checkClassList(classlist)){
			classlist.Head = newClass;
			classlist.Tail = newClass;
		}
		else {
			classlist.Tail->pnext = newClass;
			classlist.Tail = newClass;
		}
	}
}


//XUAT DANH SACH CAC LOP 15
void xuatDanhSachCacLop(ClassList classlist) {
	Class* p = classlist.Head;
	while (p != NULL) {
		cout << p->maLop << endl;
		p = p->pnext;
	}
	string a;
	cout << "Nhap lop muon xem: ";
	cin >> a;
	xuatThongTinSVCuaLop(a);
}

bool checkSVList(SVList svlist) {
	if (svlist.Head == NULL)
		return true;
	return false;
}


void saveSVList(SVList& svlist,string a) {
	fstream f;
	f.open(a, ios::in);
	if (f.fail()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	while (!f.eof()) {
		SinhVien* p = new SinhVien;
		getline(f, p->No, ',');
		getline(f, p->MSSV, ',');
		getline(f, p->Ten, ',');
		getline(f, p->Ho, ',');
		getline(f, p->Gioitinh, ',');
		getline(f, p->Ngaysinh, ',');
		getline(f, p->ID, '\n');
		p->pnext = NULL;
		if (checkSVList(svlist))
			svlist.Head = svlist.Tail = p;
		else {
			svlist.Tail->pnext = p;
			svlist.Tail = p;
		}
	}
	f.close();
}


//XUAT DANH SACH SINH VIEN CUA LOP 16
void xuatThongTinSVCuaLop(string a) {
	string b = "Classes\\" + a + ".csv";
	fstream f;
	f.open(b, ios::in);
	if (f.fail()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	string No, Maso, Ten, Ho, GioiTinh, Ngaysinh, ID;
	while (!f.eof()) {
		getline(f, No, ',');
		if (No == "")
			break;
		getline(f, Maso, ',');
		getline(f, Ten, ',');
		getline(f, Ho, ',');
		getline(f, GioiTinh, ',');
		getline(f, Ngaysinh, ',');
		getline(f, ID, '\n');
		string hoten = Ho + " " + Ten;
		cout << No << "\t" << Maso << "\t" << hoten << "\t" << GioiTinh << "\t" << Ngaysinh << "\t" << ID << endl;
	}
}

bool checkCourseList(CourseList courselist) {
	if (courselist.Head == NULL)
		return true;
	return false;
}


//SAVE COURSELIST
void saveCourseList(CourseList& courselist) {
	fstream f;
	f.open("CoursesList.csv");
	if (f.fail()) {
		cout << "Khong the mo duoc file" << endl;
		return;
	}
	while (!f.eof()) {
		string a, b, c;
		Course* p = new Course;
		getline(f, p->maMH, ',');
		if (p->maMH == "\n" || p->maMH == "")
			break;
		getline(f, p->tenMH, ',');
		getline(f, p->tenLop, ',');
		getline(f, p->tenGV, ',');
		getline(f, a, ',');
		p->soTin = stoi(a);
		getline(f, b, ',');
		p->soLuongMax = stoi(b);
		getline(f, c, ',');
		p->namHoc = stoi(c);
		getline(f, p->gioHoc, '\n');
		p->pnext = NULL;
		if (checkCourseList(courselist)) {
			courselist.Head = p;
			courselist.Tail = p;
		}
		else {
			courselist.Tail->pnext = p;
			courselist.Tail = p;
		}
	}
}


//XUAT DANH SACH CAC KHOA HOC 9 17
void xuatDanhSachMonHoc(CourseList courselist) {
	Course* p = courselist.Head;
	cout << "Ma MH" << "\t"<<"\t" << "Ten Mon Hoc" << "\t" << "Ten Lop" << "\t" << "Ten giao vien" << "\t" << "So tin" << "\t" << "So luong" << "\t" << "Nam hoc" << "\t" << "Gio hoc" << endl;
	while (p != NULL) {
		cout << p->maMH << "\t" << p->tenMH << "\t" << p->tenLop << "\t"<<p->tenGV<<"\t"<<p->soTin<<"\t" << p->soLuongMax << "\t" << p->namHoc << "\t" << p->gioHoc << endl;
		p = p->pnext;
	}
}


//XEM DANH SACH HOC SINH CUA KHOA HOC 18
void xuatHocSinhMonHoc(string a) {
	string b = "Courses\\" + a + ".csv";
	fstream f;
	f.open(b, ios::in);
	if (f.fail()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	string No, Maso, Ten, Ho, GioiTinh, Ngaysinh, ID;
	while (!f.eof()) {
		getline(f, No, ',');
		if (No == "")
			break;
		getline(f, Maso, ',');
		getline(f, Ten, ',');
		getline(f, Ho, ',');
		getline(f, GioiTinh, ',');
		getline(f, Ngaysinh, ',');
		getline(f, ID, '\n');
		string hoten = Ho + " " + Ten;
		cout << No << "\t" << Maso << "\t" << hoten << "\t" << GioiTinh << "\t" << Ngaysinh << "\t" << ID << endl;
	}
}


//CAP NHAT THONG TIN KHOA HOC 10
void capnhatThongTinKhoaHoc(string a,CourseList &courselist) {
	Course* i = courselist.Head;
	while (i != NULL) {
		if (i->maMH == a)
			break;
		i = i->pnext;
	}
	if (i == NULL)
		return;
	cout << "Nhap ten mon hoc moi: ";
	getline(cin, i->tenMH);
	cout << "Nhap ten lop moi: ";
	getline(cin, i->tenLop);
	cout << "Nhap ten giao vien moi: ";
	getline(cin, i->tenGV);
	cout << "Nhap so tin moi: ";
	cin >> i->soTin;
	cout << "Nhap so luong hoc sinh toi da: ";
	cin >> i->soLuongMax;
	cout << "Nhap nam hoc: ";
	cin >> i->namHoc;
	cin.ignore();
	cout << "Nhap gio hoc: ";
	getline(cin, i->gioHoc);
	fstream f;
	f.open("CoursesList.csv", ios::out);
	if (f.fail()) {
		cout << "Khong the mo duoc file" << endl;
		return;
	}
	i = courselist.Head;
	while (i != NULL) {
		f << i->maMH << "," << i->tenMH << "," << i->tenLop << "," << i->tenGV << "," << i->soTin << "," << i->soLuongMax << "," << i->namHoc << "," << i->gioHoc << endl;
		i = i->pnext;
	}
	f.close();
}


//THEM 1 SINH VIEN VAO KHOA HOC 11
// a la ten khoa hoc
void them1SVKhoaHoc(string a) {
	fstream f;
	f.open("Courses\\" + a + ".csv", ios::app);
	if (f.fail()) {
		cout << "Khong the mo duoc file" << endl;
		return;
	}
	string No, Maso, Ten, Ho, GioiTinh, Ngaysinh, ID;
	cout << "Nhap so thu tu: ";
	getline(cin, No);
	cout << "Nhap ma so: ";
	getline(cin, Maso);
	cout << "Nhap ten: ";
	getline(cin, Ten);
	cout << "Nhap ho: ";
	getline(cin, Ho);
	cout << "Nhap gioi tinh: ";
	getline(cin, GioiTinh);
	cout << "Nhap ngay sinh: ";
	getline(cin, Ngaysinh);
	cout << "Nhap ID: ";
	getline(cin, ID);
	string hoten = Ho + " " + Ten;
	f << No << "," << Maso << "," << Ten << "," << Ho << "," << GioiTinh << "," << Ngaysinh << "," << ID << endl;
	f.close();
}

// a la ten khoa hoc , b la MSSV can xoa
void xoa1SVKhoaHoc(string a, string b) {
	fstream f;
	a = "Courses\\" + a + ".csv";
	SVList svlist;
	khoiTaoSVList(svlist);
	saveSVList(svlist, a);
	SinhVien* i = svlist.Head;
	while (i != NULL) {
		if (i->MSSV == b)
			break;
		i = i->pnext;
	}
	if (i == NULL)
		return;
	if (i == svlist.Head) {
		svlist.Head = svlist.Head->pnext;
		delete i;
	}
	else {
		SinhVien* j = svlist.Head;
		while (j->pnext != i)
			j = j->pnext;
		j->pnext = i->pnext;
		delete i;
	}
	f.open(a, ios::out);
	if (f.fail()) {
		cout << "Khong the mo duoc file" << endl;
		return;
	}
	i = svlist.Head;
	while (i != NULL) {
		f << i->No << "," << i->MSSV << "," << i->Ten << "," << i->Ho << "," << i->Gioitinh << "," << i->Ngaysinh << "," << i->ID;
		if (i->pnext != NULL)
			f << endl;
		else
			break;
		i = i->pnext;
	}
	f.close();
}

//THEM 1 KHOA HOC 7
void themKhoaHoc() {
	string a, b, c, d, e;
	int x, y, z;
	cout << "Nhap ma mon hoc: ";
	getline(cin, a);
	cout << "Nhap ten mon hoc: ";
	getline(cin, b);
	cout << "Nhap ten lop: ";
	getline(cin, c);
	cout << "Nhap ten giao vien: ";
	getline(cin, d);
	cout << "Nhap so tin: ";
	cin >> x;
	y = 50;
	cout << "Nhap nam hoc: ";
	cin >> z;
	cin.ignore();
	cout << "Nhap gio hoc: ";
	getline(cin, e);
	fstream f;
	f.open("CoursesList.csv", ios::app);
	if (f.fail()) {
		cout << "Khong the mo duoc file" << endl;
		return;
	}
	f << a << "," << b << "," << c << "," << d << "," << x << "," << y << "," << z << "," << e << endl;
	f.close();
	f.open("Courses\\" + a + ".csv", ios::out);
	if (f.fail()) {
		cout << "Khong the mo duoc file" << endl;
		return;
	}
	f.close();
}



//THEM DANH SACH SINH VIEN VAO KHOA HOC BANG FILE CSV 8 
// 
//a la ten ma khoa hoc, b la file hoc sinh de them
void themHocSinhVaoKhoaHoc(string a,string b) {
	fstream f1, f2;
	f1.open("Courses\\" + a + ".csv", ios::app);
	if (f1.fail()) {
		cout << "Khong the mo duoc file" << endl;
		return;
	}
	f2.open(b, ios::in);
	if (f2.fail()) {
		cout << "Khong the mo duoc file" << endl;
		return;
	}
	string No, Maso, Ten, Ho, GioiTinh, Ngaysinh, ID;
	while (!f2.eof()) {
		getline(f2, No, ',');
		if (No == "")
			return;
		getline(f2, Maso, ',');
		getline(f2, Ten, ',');
		getline(f2, Ho, ',');
		getline(f2, GioiTinh, ',');
		getline(f2, Ngaysinh, ',');
		getline(f2, ID);
		f1 << No << "," << Maso << "," << Ten << "," << Ho << "," << GioiTinh << "," << Ngaysinh << "," << ID << endl;
	}
	f2.close();
	f1.close();
}

//XOA KHOA HOC 13
void xoaKhoaHoc() {
	string a;
	cout << "Nhap ma mon hoc can xoa: ";
	getline(cin, a);
	CourseList courselist;
	khoiTaoCourseList(courselist);
	saveCourseList(courselist);
	Course* i = courselist.Head;
	while (i != NULL) {
		if (i->maMH == a)
			break;
		i = i->pnext;
	}
	if (i == NULL)
		return;
	if (i == courselist.Head) {
		courselist.Head = courselist.Head->pnext;
		delete i;
	}
	else {
		Course* j = courselist.Head;
		while (j->pnext != i)
			j = j->pnext;
		j->pnext = i->pnext;
		delete i;
	}
	fstream f;
	f.open("CoursesList.csv", ios::out);
	if (f.fail()) {
		cout << "Khong the mo duoc file" << endl;
		return;
	}
	i = courselist.Head;
	while (i != NULL) {
		f << i->maMH << "," << i->tenMH << "," << i->tenLop << "," << i->tenGV << "," << i->soTin << "," << i->soLuongMax << "," << i->namHoc << "," << i->gioHoc;
		if (i->pnext != NULL)
			f << endl;
		else
			break;
		i = i->pnext;
	}
	f.close();
	remove(("Courses\\" + a + ".csv").c_str());
}