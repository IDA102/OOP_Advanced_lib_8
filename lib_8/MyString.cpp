#include "MyString.h"
//---------------------------------------------------------------------------
MyString::MyString(const char *pStr )
{
//Динамически выделить требуемое количество памяти.
	m_pStr = new char[strlen( pStr ) + 1];	// + 1, так как нулевой байт тоже нужно скопировать
	strcpy( m_pStr, pStr );//Если память выделена, скопировать строку-аргумент в строку-член класса
}
MyString::MyString()
{
	//Динамически выделить требуемое количество памяти.    А КАК ЛУЧШЕ?????????????????????
	m_pStr = new char[1];
	m_pStr[0] ='\0';
//m_pStr = new char(0);//если 0, то везде проверять!!!   При печати  и в деструкторе не требует проверки
	
//Возможные неприятности !!!!!!!!!!!!
//m_pStr = 0;	  //??????  при выводе на печать 0 указатель даст ошибку
//m_pStr = "Default";  //в деструкторе попытаемся удалить m_pStr и будет ошибка, т.к. там адрес строкового литерала
}
MyString::MyString(const MyString &other)
{
	//Выделение памяти под копию строки
	m_pStr= new char [strlen (other.m_pStr)+1]; 
	//Копирование строки
	strcpy (m_pStr,other.m_pStr);
}
MyString::~MyString()
{
	delete[] m_pStr;//Освобождение памяти, занятой в конструкторе для строки-члена класса
	m_pStr=0;
}
const char* MyString::GetString() const
{
	return  m_pStr;
}
MyString& MyString::GetString()
{
	return *this;
}
 void MyString::SetNewString (const char *pStr)
 {
	 int len1,len2;
	 //Определяем какая из строк длиннее, старая или новая
	 len1=strlen (this->m_pStr)+1;
	 len2=strlen (pStr)+1;
	 //Новая строка помещается на место старой
	 if (len2 <= len1)
		 strcpy(m_pStr,pStr);
	 else
	 {	//Для новой строки требуется места больше
		 //Удаление указателя на старую строку
		 delete []m_pStr;
		 //Распределение памяти под новую строку
		 m_pStr=new char[len2];
		 //Копирование одной строки в другую
		 strcpy(m_pStr,pStr);
	 }
 }
//Правильный оператор присваивания =
 MyString& MyString::operator=(const MyString& s)
 {
	// m_pStr=s.m_pStr; //это не корректно, т.к при разрушении объектов возникнет ошибка
	 //надо выделить новую память
	 if (this!=&s)//проверяем, не один ли это объект  
	 {
		 delete m_pStr; //удаляется старый адрес
		 m_pStr= new char[strlen(s.m_pStr)+1];
		 strcpy(m_pStr,s.m_pStr);
	 }
	 return *this;
 }
 /*MyString& MyString::operator=(const char* str)
 {
	delete m_pStr; //удаляется старый адрес
	m_pStr= new char[strlen(str)+1];
	strcpy(m_pStr,str);
	return *this;
 }*/
 //-----------------------------------------------------------------------------
//// оператор присваивания (move semantics)
 /* MyString& MyString::operator=( MyString&& s)
  {
	  delete m_pStr; //удаляется старый адрес 
	  m_pStr=s.m_pStr;  // отняли у s
	   s.m_pStr= nullptr;//обнулили у s
	   return *this;
  }*/
//------------------------------------------------------------------------------
/*MyString MyString::operator+(const MyString& s)
 {
	//создается новый объект  (возврат по значению)
	 int len= strlen(m_pStr)+strlen(s.m_pStr)+1;
	 char* ptr=new char[len];
	 strcpy(ptr,m_pStr);
	 strcat(ptr,s.m_pStr);
	 //создаем временный объект
	 MyString temp (ptr); 
	 //Возвращаем копию !!! НО НЕ ССЫЛКУ!!!
	 //уничтожаем вспомогательный массив
	 delete[] ptr; 
	 return(temp);	//будет вызван move-конструктор копирования !!!
 }*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*MyString MyString::operator+(const MyString& s)const //предлагает Элджер
 {
	//создается новый объект  (возврат по значению)
	 int len= strlen(m_pStr)+strlen(s.m_pStr)+1;
	 char* ptr=new char[len];
	 strcpy(ptr,m_pStr);
	 strcat(ptr,s.m_pStr);
	 //создаем временный объект
	 MyString temp (ptr);
	 //уничтожаем вспомогательный массив
	 delete[] ptr; 
	 return(temp);
 }*/
//------------------------------------------------------------------------------
/*MyString& MyString::operator+=(const MyString& s)//можно возвратить адрес, т.к. объект существует
 {
	 //изменяется существующий	(возврат по ссылке)
	 MyString temp= *this;
	 delete m_pStr; //удаляется старый адрес
	 m_pStr= new char[strlen(temp.m_pStr)+strlen(s.m_pStr)+1];
	 strcpy(m_pStr,temp.m_pStr);
	 strcat(m_pStr,s.m_pStr);
	 return *this;
 }*/
bool MyString::operator==(const MyString& other)
{
	return(strcmp(this->m_pStr,other.m_pStr)==0);
}
/*bool MyString::operator==(const char* other)
{
	return(strcmp(this->m_pStr,other)==0);

}*/
//------------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// конструктор копирования (move semantics)
/* MyString::MyString(MyString&& other ) //&&- указывает на то, что это временный объект
 {
	 m_pStr=other.m_pStr;  // отняли у временного
	 other.m_pStr= nullptr;//обнулили у временного
 }
 //-----------------------------------------------------------------------------
 */