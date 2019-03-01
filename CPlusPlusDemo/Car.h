#pragma once

class Customer;

//�����ռ�
namespace GlobalSpace
{
	//ȫ�ֱ���
	static long GlobalCarCount = 5799999L;

	//ȫ�ֺ���
	void SetGlobalCarCount(long lValue);

	//�ṹ
	struct CarParameter
	{
		int weight;
		int size;
		int door;
		char engine[100];
	};

	//���ϣ�������ݹ���һ���ڴ�
	union CarIndex
	{
		int i;
		char ch[4];
	};
}

//ö��
enum CardType
{
	S1, S2, S3
};

//ʹ�ú�����峣��
#define MAX_CAR_COUNT 10000

//��Ϊ����ĺ�����Ҫ�õ�Car���������������������
class Car;

//ȫ�����ز������������ȳ�Ա������һ��������Car& ����ʵ�ִ��� Car>>12>>54>>86;
Car& operator >>(Car & myCar, int mMile);

class Car
{
public:
	//���캯�������û�У�����������һ��Ĭ�ϵ��޲ι��캯��
	Car(const char* brandName, CardType ct, const char *colorName, 
		int power = 78, int seatCount = 4);

	//���캯������
	Car(const char* brandName, CardType ct);

	//���ƹ��캯�������û�б���������һ��Ĭ�ϵĸ��ƹ��캯��
	Car(const Car& myCar);

	//ת�����캯��(ֻ��һ�������Ĺ��캯��)
	Car(const char *brandName);

	//����������(��ֹʹ�û���ָ��delete�������ʱ���ᵼ��û�е����������������������)
	virtual ~Car(void);

	//���ظ�ֵ������(��Ա������[] () -> =ֻ������Ϊ��Ա�����������Ŀ�����ȫ��Ҳ�����ǳ�Ա����)
	void operator = (const Car& myCar);

	//���غ���++������
	Car operator ++();

	//����ǰ��++��������ǰ��Ҫ���ر���
	Car& operator ++(int k);

	//��ȫ�����غ�������ΪԪ�ѣ��������ܷ���˽�б���
	friend Car& operator >>(Car & myCar, int mMile);

	//��������ת����������ת������û�з���ֵ����
	operator int();

	//������̣���������Ϊ�麯���������඼Ĭ�����麯����������û��virtual�ؼ���
	//virtual void Run(int mMile) = 0;  //����Ǵ��麯�������಻��ʵ���������������Ҫ��д�������
	virtual void Run(int mMile);

	//��ʾ����������Ϣ(������Ա�����������޸ĳ�Ա��������������ֻ�ܵ��ó�����Ա����)
	void Show() const;

	//�Ǽ�ӵ����
	void SetMaster(Customer *pMaster);

	char *mBrand;		//Ʒ��
	CardType mType;		//����
	char *mColor;		//��ɫ

	Customer *mMaster;	//ӵ����(��Ա�����ʹ��ָ�룬�������ѭ������)
protected:
	//������̱�(ֻ�����������ڲ�����)����������������ƴ���ڵ��ô������ڸ�Ƶ������˵����ջ�Ŀ���
	inline void ResetMileage();

	int mMileage;		//�����
	int mOilCount;		//����
private:
	int mPower;			//����
	int mSeatCount;		//��λ��
};

