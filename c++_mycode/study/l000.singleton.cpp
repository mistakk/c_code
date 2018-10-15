using namespace std;
#include <iostream>
#include <mutex>
class Singleton {
public:
	static Singleton* GetInstance1();
	static Singleton* GetInstance2();
	void DestoryInstance();
	void print() {std::cout << "print" << endl;}
private:
	Singleton() {}
private:
	static Singleton *m_single;
	static mutex m_mutex;
};

// 单例 - 主动释放
void Singleton::DestoryInstance() {
	if (m_single != NULL) {		delete m_single;		m_single = NULL;	}
}


//懒汉模式
Singleton *Singleton::m_single = NULL;mutex Singleton::m_mutex;
Singleton *Singleton::GetInstance1() {
	if (m_single == NULL) {
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_single == NULL) {
			m_single = new Singleton();
		}
	}
	return m_single;
}

//饿汉模式
//Singleton *Singleton::m_single = new Singleton();
//Singleton *Singleton::GetInstance2() {//	return m_single;//}


int main() {

	//懒汉初始化
	//singleton *p1 = NULL;
	Singleton *singleton1 = Singleton::GetInstance1();	singleton1->print();
	Singleton::GetInstance1()->DestoryInstance();
	////饿汉初始化
	//singleton *singleton2 = singleton::GetInstance2();
	//singleton2->print();

	return 0;
}






