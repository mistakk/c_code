#include <iostream>
#include <stdio.h>
using namespace std;

class A {
public:
	A() : m_data1(7), m_data2(8) {}
	virtual void vfunc1() { cout << "A::vfunc1" << endl; };
	virtual void vfunc2() { cout << "A::vfunc2" << endl; };
	void func1() { 
		cout << "A::func1" << endl; 
		printf("%p\n", (&A::m_data1));
	};
	void func2() { cout << "A::func2" << endl; };
public:
	int m_data1, m_data2;
};

class B : public A {
public:
	B() : A(), m_data3(5), m_data4(6) {}
	virtual void vfunc1() { cout << "B::vfunc1" << endl; };
	void func1() { cout << "B::func1" << endl; };
	int m_data3;
	int m_data4;
};

class C : public B {
public:
	C() : B(), m_data1(0), m_data4(0) {}
	virtual void vfunc2() { cout << "C::vfunc2" << endl; };
	void func2() { cout << "C::func2" << endl; };
private:
	int m_data1, m_data4;
};

int main2()
{
	A aaObject;
	A aaObject2;
	printf("dest is %p, val is %d\n", &(aaObject.m_data1), aaObject.m_data1);
	printf("dest is %p, val is %d\n", &(aaObject.m_data2), aaObject.m_data2);
	char *p = (char *)&aaObject;
	cout << sizeof(A) << endl;
	for (int i = 0; i < sizeof(aaObject); ++i) {
		printf("dest is %p, val is %p \n", p + 4*i, *(p + 4 * i));
	}
	B bObject;
	A *pa = &bObject;
	//ָ��pa�� A*���ͣ���ֵ��B����ĵ�ַ���ڵ��ó�Ա������A�ķ�Χ�������ڵ����麯��ʱ���Ȼ�ָ��B����ĵ�ַ���������ָ��ָ��B����麯����
	//��ʱ���pa�����麯�������ҵ�B����ĺ�����ַ���Ӷ�ʵ�ֶ�̬
	int a = pa->m_data1;
	//int b = pa->m_data3;   m_data3����A�ĳ�Ա
	cout << sizeof(bObject) << endl;
	printf("dest is %p, val is %d\n", &(bObject.m_data3), bObject.m_data3);
	printf("dest is %p, val is %d\n", &(bObject.m_data4), bObject.m_data4);
	char *pb = (char *)&bObject;
	cout << sizeof(A) << endl;
	for (int i = 0; i < sizeof(bObject); ++i) {
		printf("dest is %p, val is %p \n", pb + 4 * i, *(pb + 4 * i));
	}
	/*
	system("pause");

	A *p = &bObject;
	p->vfunc1();

	A aObject = (A)bObject;
	aObject.vfunc1();
	13fcfbc38
	C cObject;
	p = &cObject;
	p->vfunc1();
	p->vfunc2();

	cObject.A::func1();
	*/
	return 0;
}