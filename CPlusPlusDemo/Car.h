#pragma once

class Customer;

//命名空间
namespace GlobalSpace
{
	//全局变量
	static long GlobalCarCount = 5799999L;

	//全局函数
	void SetGlobalCarCount(long lValue);

	//结构
	struct CarParameter
	{
		int weight;
		int size;
		int door;
		char engine[100];
	};

	//联合：多个数据共享一块内存
	union CarIndex
	{
		int i;
		char ch[4];
	};
}

//枚举
enum CardType
{
	S1, S2, S3
};

//使用宏命令定义常量
#define MAX_CAR_COUNT 10000

//因为正面的函数需要用到Car，可以先声明后定义这个类
class Car;

//全局重载操作符，参数比成员函数多一个，返回Car& 可以实现代码 Car>>12>>54>>86;
Car& operator >>(Car & myCar, int mMile);

class Car
{
public:
	//构造函数，如果没有，编译器产生一个默认的无参构造函数
	Car(const char* brandName, CardType ct, const char *colorName, 
		int power = 78, int seatCount = 4);

	//构造函数重载
	Car(const char* brandName, CardType ct);

	//复制构造函数，如果没有编译器产生一个默认的复制构造函数
	Car(const Car& myCar);

	//转换构造函数(只有一个参数的构造函数)
	Car(const char *brandName);

	//虚析构函数(防止使用基类指针delete子类对象时，会导致没有调到子类的析构函数的问题)
	virtual ~Car(void);

	//重载赋值操作符(成员函数，[] () -> =只能重载为成员函数，其他的可以是全局也可以是成员函数)
	void operator = (const Car& myCar);

	//重载后置++操作符
	Car operator ++();

	//重载前置++操作符，前置要返回本身
	Car& operator ++(int k);

	//把全局重载函数声明为元友，这样才能访问私有变量
	friend Car& operator >>(Car & myCar, int mMile);

	//重载类型转换符，类型转换函数没有返回值类型
	operator int();

	//行走里程，函数声明为虚函数后，派生类都默认是虚函数，不管有没有virtual关键字
	//virtual void Run(int mMile) = 0;  //如果是纯虚函数，基类不能实例化，派生类必须要重写这个函数
	virtual void Run(int mMile);

	//显示汽车基本信息(常量成员函数，不能修改成员变量；常量对象只能调用常量成员函数)
	void Show() const;

	//登记拥有人
	void SetMaster(Customer *pMaster);

	char *mBrand;		//品牌
	CardType mType;		//类型
	char *mColor;		//颜色

	Customer *mMaster;	//拥有人(成员类对象都使用指针，避免造成循环定义)
protected:
	//重置里程表(只能在派生类内部调用)：内联函数将代码拼接在调用处，对于高频函数来说减少栈的开销
	inline void ResetMileage();

	int mMileage;		//里程数
	int mOilCount;		//油量
private:
	int mPower;			//排量
	int mSeatCount;		//座位数
};

