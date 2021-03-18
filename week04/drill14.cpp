
#include "std_lib_facilities.h"


using namespace std;

class B1
{
public:
	virtual void vf() { cout << "B1::vf()" << endl; };
	void f() { cout << "B1::f()" << endl; };
	virtual void pvf() = 0;
};


class D1 : public B1
{
public:
	void vf() override { cout << "D1::vf()" << endl; };
	void f() { cout << "D1::f()" << endl; };
	void pvf() override { cout << "D1::pvf()" << endl; }
};


class D2 : public D1
{
public:
	void pvf() override { cout << "D2::pvf()" << endl; };
};


class B2
{
public:
	virtual void pvf() = 0;
};


class D21 : public B2
{
public:
	virtual void pvf() override { cout << str << endl; }
private:
	string str{"Drill14\n"};
};


class D22 : public B2
{
public:
	virtual void pvf() override { cout << num << endl; }
private:
	int num = 10;
};


void f(B2& k)
{
	k.pvf();
}

int main()
{
	/*B1 b1;

	b1.vf();
	b1.f();*/

	D1 d1;
	B1& bref = d1;

	d1.vf();
	d1.f(); //hogyha nem lenne megirva a D1 f()-je akkor a B1 f()-je lenne meghivva

	bref.vf();
	bref.f();
	cout << endl;

	//B1 egy absztrakt osztaly ezert az alabbi sor nem fut le
	//b1.pvf();
	d1.pvf();
	bref.pvf();
	cout << endl;


	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();
	cout << endl;
	

	D21 d21;
	D22 d22;
	f(d21);
	f(d22);
	cout << endl;

	return 0;
}