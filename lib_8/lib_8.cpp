//����������� ���������� �������� - STL 
	//���������� ����������� ���������� - vector
	//���������
#include "H.h"
template <typename T> ostream& operator<<(ostream& os, const vector<T> &ms)
{
	cout << "______________vector______________" << endl;
	cout << "capasity = " << ms.capacity() << endl;
	cout << "size     = " << ms.size() << endl;
	cout << "max_size = " << ms.capacity() << endl;
	for (size_t i = 0; i < ms.size(); i++)
	{
		cout << "[" << i << "]" << "=" << ms[i] << endl;
	}
	cout << endl;
	return os;
};
ostream& operator<<(ostream& os, const vector <Point*>& ms)
{
	cout << "______________Point______________" << endl;
	cout << "capasity = " << ms.capacity() << endl;
	cout << "size     = " << ms.size() << endl;
	cout << "max_size = " << ms.capacity() << endl;
	for (size_t i = 0; i < ms.size(); i++)
	{
		cout << "[" << i << "]" << "=" << ms[i] << endl;
	}
	cout << endl;
	return os;
};
ostream& operator<<(ostream& os, const MyString &ms)
{
	cout << ms.m_pStr;
	return os;
};
ostream& operator<<(ostream& os, const Point &ms)
{
	cout << ms.x << " " << ms.y;
	return os;
}
ostream& operator<<(ostream& os, const Point *ms)
{
	if (ms != NULL)
	{
		cout << ms->x << " " << ms->y;
	}
	else cout << "NULL";
		return os;
}
void delString(vector<char> &string)//void delString(char *string,const size_t I)//������� � 2 �����������
{
	vector<char>::iterator it = string.begin();
	vector<char>::iterator itLast = string.end();
	size_t cnt = 0;
	while (it != (string.end()-1))
	{
		if (*it == *(it + 1))
		{
			cnt++;
			while (*it == *(it + cnt + 1))
			{
				++cnt;
			}
			it = string.erase(it, it + (cnt + 1));
			cnt = 0;
		}
		else ++it;
	}
};
bool del_two(Point &b)
{
	bool ret = (b == Point(2, 2));
	return	ret;
}
int main()
{
	// ��������� ����������� ���������� vector 

//////////////////////////////////////////////////////////////////////
	//�������� ��������. 

	//�������� ��������� �������:
	//---------------------------
	//������ ������ ����� ����� - vInt � ��������� � ������� ������� size(),
	//��� ��� ������ �������. 
	vector<int> vInt;
	stop
	size_t s = vInt.size();
	stop
	//���������������� ��������� ��������, ��������� - ��� �� ���������
	//���� ���� ��������������, - ���������
	vInt.push_back(0);
	vInt.front()=1;
	int q = vInt.front();
	stop
	/*
	� ������� ������� push_back() � ����� ��������� ������ ������-���� ����������.
	�� ������ �������� ����� ������� �� �������� ������� � ������� �������
	size(), capacity(), max_size() � �������� �������� ���������. 
	
	���������: ��� ��� ����� �������� ����������� ��� � � ��������� ��������,
	�������� ������ �������, ������� ��� �������, ����������� �������� ������ ����
	������� ��� "���������" � �������� ��������� �� �������.
	*/

	cout << vInt;//���������� +15-20% � capacity
	vInt.push_back(5);
	cout << vInt;
	vInt.push_back(10);
	cout << vInt;
	vInt.push_back(15);
	cout << vInt;
	vInt.push_back(20);
	cout << vInt;
	stop

	/*
	������ ������������ - vDouble1 � �������� ���� ��������� ��������  �
	��������� ��������� � ������� ���������� ���� �������. ��� �����
	������������������� �������� �������?
	*/

	vector<double> vDouble1(5);//������ // ������???
	cout << vDouble1;
	stop

	/*
	B����� �������� ���� MyString � ��������� �������� - 5 ���������
	� �������������� ������� �������� ������� "A"
	C ������� ������� at() � ����� � ������� ���������
	�������������� []  �������� �������� �����-���� ���������.
	���������� "�����" �� ������� ������� � ������� at() �
	� ������� []. 
	*/
	
	vector<MyString> MS(5,"A");
	stop
	cout << MS << endl;
	stop

	/*
	B����� ������������ - vDouble3, ������� �������� ������ ���������
	[0,5) ������� ������������ ����� dMas. �������������� ������ dMas
	����� ������� � �������������������!
	*/

	double dMas[] = { 1, 2, 3, 4, 5};
	vector<double> vDouble3(dMas,dMas + sizeof(dMas)/sizeof(double));
	stop

	/*
	B����� ������������ - vDouble4, ������� �������� ������ ���������
	[2,5) ������� vDouble3. 
	*/

	//sizeof(vDouble3) ������ ����� 16!!!!!!!!!!!!!!! ������ ��� � ������� ����������� 3 ��������� � ���������� � ���-�� ���.
	//vector<double> vDouble4(&vDouble3[1], &vDouble3[1] + sizeof(vDouble3) / vDouble3.size());
	vector<double> vDouble4(&vDouble3[1], &vDouble3[1] + 3);
	stop
	/*
	B����� ��������� ���� Point - vPoint1
	�) � ��������� �������� 3. ����� �����������
	����� ������ ��� ������� ��������?
	b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).
	*/
	
	vector<Point> vPoint1(3); //����� ������ ��������� � Point �����������;
	stop
	vector<Point> vPoint2(5,Point(1,1));
	cout << vPoint2;
	stop

	/*
	B����� ���������� �� Point - vpPoint � ��������� �������� 5
	���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point
			
	���������: ��� ������ �� ������ �������� ������ ����� ��� �����������
	�) ������������� ����� ��������� �������
	�) ��� ���������� operator<< ��� Point*
	*/

	{//������� delite
	size_t I = 5;
	vector<Point*> vPoint1(I);// ,new Point());
	stop
	cout << vPoint1 << endl;
	stop//����������� push � pop
		for (size_t i = 0 ; i < I ; i++)
		{
			vPoint1.push_back( (new Point(i, i)) ); //	��� �������	vPoint1[i] = new  Point(i,i);
			stop

		}
	cout << vPoint1 << endl;
	stop
	for (size_t i = 0; i < vPoint1.size(); i++)
	{
		delete vPoint1[i];
	}
	stop
	}//����� �������������� �������� ����� ����������� ��� ������ �������? ----- �������� delite


	///////////////////////////////////////////////////////////////////////
	//�������������� ������.
	//���������, ������ �� ����� ����������� ���� ��������?
	/*
	{
	size_t n=...
	vector<int> v(n);
	v.resize(n/2);
	if(v.capacity() == n) //true?--------------------------------------�� 
 	}
	*/

	/*
	{
	int n=...
	size_t m=...
	vector<int> v(n);
	v.reserve(m);
	if(v.capacity() == m) //true?--------------------------------------���
	}
	*/

	/*
	{
	vector<int> v(3,5);---------------------5 5 5
	v.resize(4,10); //��������?-------------5 5 5 10
	v.resize(5); //��������?----------------5 5 5 10 0

	}
	*/

	/*
	�������� ��� "������" ������� � ����������
	������ (�� ������ � ���� �� ����) ����.
	� ������ ������� �������������� ������ ��� 5 ���������, � ����� ���������
	��� ���������� � ������� push_back.
	������ ������ ������ ��������� ���������� ����������� push_back.
		
	�������� ������, ������� �������� � �������� ���������
	*/
	vector<int> v1;
	vector<int> v2;
	stop
	v1.reserve(5);
	cout << v1;
	stop
	size_t N = 5;
		for (size_t i = 0 ; i < N ; i++)//��������� �� 2 �� ������� ����������
		{
			v1.push_back(i * 5);
			cout << v1;
			stop
		}
	stop
	cout << "----------------------------------------------------------------------------------------------------" << endl;
		for (size_t i = 0; i < N; i++)//��������� �� 2 �� ������� ���������� ������� � 4
		{
			v2.push_back(i * 5);
			cout << v2;
			stop
		}
	stop

	/*
	!!! shrink_to_fit - ���������� ������� �������.
	��� ������ ������� �� ����������� ������� ��������� ��������� ������� �� size.
	*/
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	for (size_t i = 0; i < N; i++)
	{
		v1.shrink_to_fit();
		cout << v1;
		stop
	}
	stop
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	for (size_t i = 0; i < N; i++)
	{
		v2.shrink_to_fit();
		cout << v2;
		stop
	}
	stop
	/*
		�������� "����������� �������" - ������� ��������
		����� ���������� ������ int ar[] = {11,2,4,3,5};
		�������� ������ �������� ��������� �������:
		������ vv[0] - �������� 11 ��������� �� ��������� 11
		vv[1] - �������� 2,2
		vv[2] - �������� 4,4,4,4
		...
		������������ ���������� ������ ����������� ������� �� �������
	*/
	int ar[] = { 11 , 2 , 4 , 3 , 5 };
	vector<vector<int>> vv;
	size_t size = sizeof(ar) / sizeof(int);
	vv.reserve(size);
	for(size_t i = 0 ; i < size ; i++)
	{
		vv.push_back(vector<int>((ar[i]), ar[i]));
	}
	stop
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
������� �������� ������������������ insert().
� ������ vChar2 �������� � ������ ������� ������ ������ ���	�������, ��� � ������� ������ ��� ���.
*/
	vector<char> vChar2;
	char sim = 'Q';
	bool flag = true;
	for (size_t i = 0 ; i < vChar2.size(); i++)
	{
		if (vChar2[i] == sim) { flag = false; break; }
	}
	if (flag)	{ vChar2.insert(vChar2.begin(),sim); }
	stop
	//vChar2.insert(vChar2.begin(), 'z');
	//vChar2.insert(vChar2.begin(), 'x');
	//vChar2.insert(vChar2.begin(), 'c');
	//vChar2.insert(vChar2.begin(), 'v');
	//vChar2.insert(vChar2.begin(), 'b');
	//�������� ����� ������ ��������� ������� vChar2 ����� 'W'
	size_t cnt = vChar2.size();
	for (size_t i = 0; i < cnt; i++)
	{ 
		vChar2.insert(vChar2.begin() + i * 2,'W');// ������ ������ ������� � �������� ������� ��������� �����? � ����� ������ ��������.
	}
	stop
		///////////////////////////////////////////////////////////////////
	/*
	�������� �������, ������� ������ ������� ������ ������������� ������������������.
	��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"
	*/
	//char *str = "qwe"; // ��������� ����������������, ������������ const, (��� ����� ������������� ���������� � ������������ ������)
	vector<char> vChar = { 'q','w','e','r','r','r','r','t','y','1','2','2','2','2','r','3' };
	delString(vChar);
	cout << vChar << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	stop
///////////////////////////////////////////////////////////////////
/*
�������� �������� ������������������ erase()
�������� ������� �������� �� ������ ������� ���� ������
*/
	vector<char> vChar3 = { 'q','q','w','e','r','r','r','r','t','y','1','2','2','2','2','r','3' };
	cout << vChar3 << endl;
	vector<char>::iterator it1 = vChar3.begin();
	vector<char>::iterator it2 = vChar3.begin()+1;
	stop
	while (it1 != vChar3.end())
	{
		while (it2 != vChar3.end())
		{
			if (*it1 == *it2)
			{
				it2 = vChar3.erase(it2);

			}
			else ++it2;
		}	
		++it1;
		it2 = it1;
		if (it1 != vChar3.end()) { ++it2; }//��� ����� ����������
		stop
	}
	cout << vChar3 << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	stop
///////////////////////////////////////////////////////////////////
/*
�������� ����� ������ ����� �������, ����� ��� �������� �����
������� ��������� ������ �� ��������� ����� ��������, �� �����������
���� �� � �������� �������
*/
{
	vector<int> vInt = {1,2,3,4,5,6,7,8,9,0};

	vector<int>::reverse_iterator it = vInt.rbegin();
	vector<int>::reverse_iterator itt = vInt.rend();
	vector<int> r_vInt(it,itt);
	stop
}
///////////////////////////////////////////////////////////////////
/*
������� 1. ������. ��������, ����������� ��� �������.
�������� ������ ������ �� ��������� Point - ptList1 � ���������
��� ���������� � ������� ������� push_back(),
push_front, insert()
*/
	list<Point> ptList1;
	ptList1.push_back(Point(1,1));
	stop
	ptList1.push_front(Point(2, 2));
	stop
	list<Point>::iterator itt = ptList1.begin();
	++itt;
	ptList1.insert(itt, Point(3, 3));
	stop
		/*
		�������� ������ �������, ������� ����� �������� ��������
		������ ���������� �� ������. ��������� ������ ������� �� �����������
		vector � list. ��������� - �������� �� ������� ��� ����������.
		*/
	ContOut(ptList1);
	ContOut(vChar3);
	stop
/*
�������� ����� �� ������� "�����������" - reverse()
*/
	ptList1.reverse();
	stop
/*
�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ����
������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
�� � �������� �������
*/
	vector<Point> vPoint = {Point(1,1),Point(2,2) ,Point(3,3) };
	list<Point> ptList2(vPoint.rbegin(), vPoint.rend());
	stop
/*
������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
�� �����������.
���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
�������� ����������/
*/
	ptList1.sort();
	ptList2.sort();
	stop
/*
���������� ��������������� ������ - merge(). ����������: ���
��� ���� ���������� � ������ �������.
*/

	ptList1.merge(ptList2); // �������� !!!�����������!!! � �����������
	stop
/*
���������� �������� �� ������ - remove()
��������� �� ������ ������� � ������������ ���������.
���������: ��� ������ ���� ����������� � ������ Point?
*/
	ptList1.remove(Point(1,1));//����� ����������� �������� ==
	stop
/*
���������� �������� �� ������, ���������������� ��������� �������:
����� �� ��������� ������������ - remove_if().
*/
	ptList1.remove_if(del_two);
	stop
/*���������� �� ������ ������ ������������� ������ - unique().*/
		ptList1.unique();
	stop

///////////////////////////////////////////////////////////////////
/*
	������� 2.������� � ����� ������� - ��������� deque

	�������� ������ deque � ���������� ���� Point. � �������
	assign ��������� deque ������� ��������� �������. � �������
	�������������� ���� � ���������� ������� �������������� �������
	�������� �������� ��������� �� ������
*/
	deque<Point> dPoint;
	dPoint.assign(2, Point(5,5));
	stop
	ContOut(dPoint);
	stop
/*
	�������� deque � ���������� ���� MyString. ��������� ��� ����������
	� ������� push_back(), push_front(), insert()
	� ������� erase ������� �� deque ��� ��������, � ������� �������
	���������� � 'A' ��� 'a'
*/
	deque<MyString> dMS;
	dMS.push_back("ABC");
	dMS.push_back("BAC");
	dMS.push_front("CAB");
	dMS.push_front("DSCB");
	dMS.insert(dMS.begin(),"H");
	dMS.insert(dMS.end(), "H");
	
	deque<MyString>::iterator iterator = dMS.begin();
	stop
	while (iterator != dMS.end())
	{
		const MyString qq = (*iterator).GetString();//��� ���������� ������ ����������� ������!!!
		const char *q = qq.GetString();
		if ((q[0] == 'A') || (q[0] == 'a'))
		{
			iterator = dMS.erase(iterator);
		}
		else { ++iterator; };
	}
	stop//��� �� ����� ����������� ������ ����� [];

	return 0;
}