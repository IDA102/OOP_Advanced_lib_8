#include "MyString.h"
//---------------------------------------------------------------------------
MyString::MyString(const char *pStr )
{
//����������� �������� ��������� ���������� ������.
	m_pStr = new char[strlen( pStr ) + 1];	// + 1, ��� ��� ������� ���� ���� ����� �����������
	strcpy( m_pStr, pStr );//���� ������ ��������, ����������� ������-�������� � ������-���� ������
}
MyString::MyString()
{
	//����������� �������� ��������� ���������� ������.    � ��� �����?????????????????????
	m_pStr = new char[1];
	m_pStr[0] ='\0';
//m_pStr = new char(0);//���� 0, �� ����� ���������!!!   ��� ������  � � ����������� �� ������� ��������
	
//��������� ������������ !!!!!!!!!!!!
//m_pStr = 0;	  //??????  ��� ������ �� ������ 0 ��������� ���� ������
//m_pStr = "Default";  //� ����������� ���������� ������� m_pStr � ����� ������, �.�. ��� ����� ���������� ��������
}
MyString::MyString(const MyString &other)
{
	//��������� ������ ��� ����� ������
	m_pStr= new char [strlen (other.m_pStr)+1]; 
	//����������� ������
	strcpy (m_pStr,other.m_pStr);
}
MyString::~MyString()
{
	delete[] m_pStr;//������������ ������, ������� � ������������ ��� ������-����� ������
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
	 //���������� ����� �� ����� �������, ������ ��� �����
	 len1=strlen (this->m_pStr)+1;
	 len2=strlen (pStr)+1;
	 //����� ������ ���������� �� ����� ������
	 if (len2 <= len1)
		 strcpy(m_pStr,pStr);
	 else
	 {	//��� ����� ������ ��������� ����� ������
		 //�������� ��������� �� ������ ������
		 delete []m_pStr;
		 //������������� ������ ��� ����� ������
		 m_pStr=new char[len2];
		 //����������� ����� ������ � ������
		 strcpy(m_pStr,pStr);
	 }
 }
//���������� �������� ������������ =
 MyString& MyString::operator=(const MyString& s)
 {
	// m_pStr=s.m_pStr; //��� �� ���������, �.� ��� ���������� �������� ��������� ������
	 //���� �������� ����� ������
	 if (this!=&s)//���������, �� ���� �� ��� ������  
	 {
		 delete m_pStr; //��������� ������ �����
		 m_pStr= new char[strlen(s.m_pStr)+1];
		 strcpy(m_pStr,s.m_pStr);
	 }
	 return *this;
 }
 /*MyString& MyString::operator=(const char* str)
 {
	delete m_pStr; //��������� ������ �����
	m_pStr= new char[strlen(str)+1];
	strcpy(m_pStr,str);
	return *this;
 }*/
 //-----------------------------------------------------------------------------
//// �������� ������������ (move semantics)
 /* MyString& MyString::operator=( MyString&& s)
  {
	  delete m_pStr; //��������� ������ ����� 
	  m_pStr=s.m_pStr;  // ������ � s
	   s.m_pStr= nullptr;//�������� � s
	   return *this;
  }*/
//------------------------------------------------------------------------------
/*MyString MyString::operator+(const MyString& s)
 {
	//��������� ����� ������  (������� �� ��������)
	 int len= strlen(m_pStr)+strlen(s.m_pStr)+1;
	 char* ptr=new char[len];
	 strcpy(ptr,m_pStr);
	 strcat(ptr,s.m_pStr);
	 //������� ��������� ������
	 MyString temp (ptr); 
	 //���������� ����� !!! �� �� ������!!!
	 //���������� ��������������� ������
	 delete[] ptr; 
	 return(temp);	//����� ������ move-����������� ����������� !!!
 }*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*MyString MyString::operator+(const MyString& s)const //���������� ������
 {
	//��������� ����� ������  (������� �� ��������)
	 int len= strlen(m_pStr)+strlen(s.m_pStr)+1;
	 char* ptr=new char[len];
	 strcpy(ptr,m_pStr);
	 strcat(ptr,s.m_pStr);
	 //������� ��������� ������
	 MyString temp (ptr);
	 //���������� ��������������� ������
	 delete[] ptr; 
	 return(temp);
 }*/
//------------------------------------------------------------------------------
/*MyString& MyString::operator+=(const MyString& s)//����� ���������� �����, �.�. ������ ����������
 {
	 //���������� ������������	(������� �� ������)
	 MyString temp= *this;
	 delete m_pStr; //��������� ������ �����
	 m_pStr= new char[strlen(temp.m_pStr)+strlen(s.m_pStr)+1];
	 strcpy(m_pStr,temp.m_pStr);
	 strcat(m_pStr,s.m_pStr);
	 return *this;
 }*/
bool MyString::operator==(const MyString& other) const
{
	return(strcmp(this->m_pStr,other.m_pStr)==0);
}
/*bool MyString::operator==(const char* other)
{
	return(strcmp(this->m_pStr,other)==0);

}*/ 
//------------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// ����������� ����������� (move semantics)
/* MyString::MyString(MyString&& other ) //&&- ��������� �� ��, ��� ��� ��������� ������
 {
	 m_pStr=other.m_pStr;  // ������ � ����������
	 other.m_pStr= nullptr;//�������� � ����������
 }
 //-----------------------------------------------------------------------------
 */