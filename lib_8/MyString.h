 #pragma once
#include "H.h"

/*class MyString
{
	//friend 	void Swap(MyString& a, MyString& b); //���� ���������� ���������� ���� �������
	friend ostream& operator<<(ostream& os, const MyString& s);
    char* m_pStr;	//������-���� ������
public:
	// ����������� � �����������
	explicit MyString(const char *pStr);//������ �������� ��������������
	MyString();//����������� �� ���������		
	MyString(const MyString &other);//����������� �����������
	MyString(MyString &&other);//����������� ����������� (move semantics) 
    ~MyString();//����������   

	//char* GetString(){return m_pStr;}//��� ����� �������� � �������(��.main)
	//char& GetString(){return  *m_pStr;}//const ��� ����, ����� ������ ���� �� ������������� ������ ���-�� ���������
	const char* GetString(){return  m_pStr;}//���� char* GetString();
	//MyString&	 GetString(){	return *this;}
	  
	  void SetNewString (const char* pStr);
	  MyString& operator=(const MyString& s); 
	  MyString& operator=(const char* str);

	  // �������� ������������ (move semantics)	
	  MyString& operator=(MyString&& s);

	MyString operator+(const MyString& s);
	MyString operator+(const MyString& s)const ; //���������� ������
	MyString& operator+=(const MyString& s);

	 bool operator==(const MyString& other);
	 bool operator==(const char* other);

	//friend void Swap(MyString& a, MyString& b);   //���, ���� ���������� ���������� ���� ������� 
	//template <>  friend void Swap(MyString& a, MyString& b); //������������� ������� ������ ������� ������ 
	//�������� �������� �� ������� ������: friend  ����� template!!!!!  
	//template <typename T> friend void Swap(T& a, T& b);  // ��� �����
	 template<typename T> friend  void Swap(T& s1, T& s2);	
};*/

class MyString
{
    char *m_pStr;//C�����-���� ������
public:
	MyString();//���������� ������������ �� ���������
	MyString(const char* pStr );//���������� ������������
	~MyString();// ���������� �����������
	const char* GetString() const;   
	MyString& GetString();
	MyString(const MyString &other );//����������� �����������
	void SetNewString (const char* pStr);
	MyString& operator=(const MyString& s);
	bool operator==(const MyString& other) const;
	friend ostream& operator<< (ostream& os, const MyString &s);
	//���������� ���� �������
	//friend void Swap(MyString& a, MyString& b);

	//������������� ������� ���  ���� MyString
	//template <> friend void Swap(MyString& a, MyString& b);
	//friend void SWAP(MyString& a, MyString& b);
};