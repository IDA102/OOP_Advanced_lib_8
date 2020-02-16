 #pragma once
#include "H.h"

/*class MyString
{
	//friend 	void Swap(MyString& a, MyString& b); //если используем перегрузку имен функции
	friend ostream& operator<<(ostream& os, const MyString& s);
    char* m_pStr;	//строка-член класса
public:
	// конструктор с параметрами
	explicit MyString(const char *pStr);//Запрет неявного преобразования
	MyString();//Конструктор по умолчанию		
	MyString(const MyString &other);//Конструктор копирования
	MyString(MyString &&other);//Конструктор копирования (move semantics) 
    ~MyString();//деструктор   

	//char* GetString(){return m_pStr;}//Это может привести к ошибкам(см.main)
	//char& GetString(){return  *m_pStr;}//const для того, чтобы нельзя было по возвращенному адресу что-то присвоить
	const char* GetString(){return  m_pStr;}//было char* GetString();
	//MyString&	 GetString(){	return *this;}
	  
	  void SetNewString (const char* pStr);
	  MyString& operator=(const MyString& s); 
	  MyString& operator=(const char* str);

	  // оператор присваивания (move semantics)	
	  MyString& operator=(MyString&& s);

	MyString operator+(const MyString& s);
	MyString operator+(const MyString& s)const ; //предлагает Элджер
	MyString& operator+=(const MyString& s);

	 bool operator==(const MyString& other);
	 bool operator==(const char* other);

	//friend void Swap(MyString& a, MyString& b);   //Это, если используем перегрузку имен функций 
	//template <>  friend void Swap(MyString& a, MyString& b); //специализацию шаблона нельзя сделать другом 
	//обратить внимание на порядок записи: friend  после template!!!!!  
	//template <typename T> friend void Swap(T& a, T& b);  // так можно
	 template<typename T> friend  void Swap(T& s1, T& s2);	
};*/

class MyString
{
    char *m_pStr;//Cтрока-член класса
public:
	MyString();//Объявление конструктора по умолчанию
	MyString(const char* pStr );//Объявление конструктора
	~MyString();// объявление деструктора
	const char* GetString() const;   
	MyString& GetString();
	MyString(const MyString &other );//Конструктор копирования
	void SetNewString (const char* pStr);
	MyString& operator=(const MyString& s);
	bool operator==(const MyString& other) const;
	friend ostream& operator<< (ostream& os, const MyString &s);
	//перегрузка имен функций
	//friend void Swap(MyString& a, MyString& b);

	//специализация шаблона для  типа MyString
	//template <> friend void Swap(MyString& a, MyString& b);
	//friend void SWAP(MyString& a, MyString& b);
};