#include "std_lib_facilities.h"

class B1 {
	public:
	virtual void vf() { cout << "B1::vf()\n"; }
	void f() { cout << "B1::f()\n"; }
	virtual void pvf() =0;   //We can't add a pure virtual function in case we wan't to create an object of i
};

class D1 : public B1 {
	public:
	void vf() override { cout << "D1::vf()\n"; }
	void f() { cout << "D1::f()\n"; }
	void pvf() {cout<<"D1::pvf"<<'\n';}
};

class D2 : public D1 {
	public:
	void pvf() override { cout << "D2::pvf()\n"; }
};

 class B2 {
 	public:
	virtual void pvf() =0;
};

class D21 : public B2 {
	public:
	string s = "Some text";
	void pvf() override { cout << s << '\n'; }
};

class D22 : public B2 {
	public:
	int i = 12;
	void pvf() override { cout << i << '\n'; }
};

void f (B2& b)
{
	b.pvf();
};



int main()
{
	/*cout << "First task: \n \n";
	B1 B1_object;
	B1_object.vf();
	B1_object.f();
    
	cout << "\n The task runs normally, and the name of the functions are shown. \n \n";*/
    

	cout << "Second task: \n \n";
	D1 D1_object;
	D1_object.vf();
	D1_object.f();
	D1_object.pvf();
    
	cout << "\nThe result of the task depends on if we've already defined an f() function for D1 \n If we did so, the f() function will be from the D1 class \n If we haven't then the f() function will be from the B1 class as D1 was derived from B1 so any non-overwritten functions are the same with B1 \n \n";

	cout << "Third task: \n \n";
	B1& B1_reference {D1_object};
	B1_reference.vf();
	B1_reference.f();
    
	cout << "\nThe result will show the overwritten function, D1::vf() and it will show B1::f() regardles of whether or not we've defined an f() function for D1 as references only change overwritten functions\n \n";

 	cout << "Task 5 can only be performed if we define pvf() in a subclass, in itself it only results in an error \n";

	cout << "\nTask 6: \n";
	D2 D2_object;
	D2_object.vf();
	D2_object.f();
	D2_object.pvf();

	cout << "\nTask 7: \n";

	D21 D21_object;
    	D22 D22_object;

    	f(D21_object);
    	f(D22_object);
}
