#include "H.h"
//����������

//�������: 
	//		������� �������,
	//		������� �������,

//#include <stdexcept>
void SWAP(MyString &r_S_a, MyString &r_S_b)
{
	MyString *c = &r_S_a;
	r_S_a = r_S_b;
	r_S_b = *c;
	c = 0;
};
//���������� �������
ostream& operator<<(ostream &os, const MyStack2_List<int> &ms)//�������� ������ ��� ������� ����� ������� ��� 
{
	const MyStack2_List<int>::Node *p = &ms.Head;
	p = p->pNext;
	for (size_t i = 0; i < ms.m_size; i++)
	{
		os << *(p->m_Data) << endl;
		p = p->pNext;
	}
	return os;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
		//����. ������� �������.
		//�������� ������ ������� ������������ ������� ����
		//�������� - Swap(). ��������� ����������������� ����������
		//������� � ������� ������������ ���� ��������� ����.
		//��������� 1: ���������� ������� ���������� ��������� � .h-����.

		int iX = 1, iY = -1;
		SWAP(iX, iY);
 		stop

		double dX = 0.5, dY = -5.5;
		SWAP(dX, dY);
		stop

		//��������� 2: ���������, ��� ����� �����������, ��� ����,
		//			����� ��������� ����� ������� � ��������� MyString
		//			�� ������ ���������, �� � ����������
		MyString str1("One"), str2("Two");
		//SWAP(str1, str2);
		stop
			/////////////////////////////////////////////////////////////////////

				//����. ������� �������.
				//������� 1.
				//�������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
				//���������: 1.�������� ����� ���-�� ������� - ������� � ������� ���������
				//			��� �������� ��������������� ������������� � ������ ���������
				//			�������� ������, 
				//			2.��� ������� ������������� ������� ����� ����� ���� �����������
				//			��������-��������� �������
				//			3.������������� ���������� �� ������ �������� "push" � "pop". ���
				//			����, ����� ������������� ���������� ���������� ���� �������� 
				//			������ ���� �� ������������ ���������� � ��������� ��������
				//			4. ������������� ���������� operator[] ����� �������, ����� ������������
				//			��� ������/�������� �������� ������ ��� ���������, ������� �� ����������


				//� ������� ������� MyStack �������� ���� �� 5 ��������� int - iStack �
				//���� �� 10 ��������� MyString - strStack � ������������������� � ���������
				//push() � pop(), operator[]
		MyArray<int, 4> iStack;
		stop
			try
		{//������ � ����
			for (int i = 0 ; i < 4 ; i++)
			{
				iStack.push(i);
			}
			stop
			for (int i = 0; i < 4 ; i++)
			{//���������� �� �����
				iStack.pop();
			}
			stop
		}
		catch(const char *error)
		{
			cout << error << endl;
		}
		stop
		//��������� ��������������
		int i = iStack[8];
		stop
		//������� 2. ���������� ������ ����� - MyStack2 ����� �������, ����� 
		//��� �������� ��������� ������������� ����������� ������.
		//���������� ����������� ����������� �������� ����� � ��� �������, � ������� �� ������� (push())
		//������������
		MyStack2_List<int>	q;
		stop
		for (int i = 0 ; i < 5 ; i++)//PUSH
		{
			int w = i + 1;
			q.push(w);
		}
		stop
		for (int i = 0; i < 5; i++)//POP
		{
			int u = q.pop();
		}
		stop
		//�������� []
		for (int i = 0; i < 3; i++)//PUSH
		{
			int w = i + 10;
			q.push(w);
		}
		int w = q[0];
		stop
		w = q[1];
		stop
		w = q[3];
		stop
		w = q[3];
		stop
		//����� � �����
		cout << "-------------------------------------------------------------" << endl;
		cout << q << endl;
		stop
	return 0;
}