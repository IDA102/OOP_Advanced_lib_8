//Стандартная библиотека шаблонов - STL 
	//Контейнеры стандартной библиотеки - vector
	//Итераторы
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
void delString(vector<char> &string)//void delString(char *string,const size_t I)//Вариант с 2 параметрами
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
	// Контейнер стандартной библиотеки vector 

//////////////////////////////////////////////////////////////////////
	//Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 
	vector<int> vInt;
	stop
	size_t s = vInt.size();
	stop
	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте
	vInt.push_back(0);
	vInt.front()=1;
	int q = vInt.front();
	stop
	/*
	С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	На каждой итерации цикла следите за размером вектора с помощью методов
	size(), capacity(), max_size() и выводите значения элементов. 
	
	Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
	напишите шаблон функции, которая для вектора, содержащего элементы любого типа
	выводит его "реквизиты" и значения элементов на консоль.
	*/

	cout << vInt;//Прибавляет +15-20% к capacity
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
	Вектор вещественных - vDouble1 с заданным Вами начальным размером  и
	проверьте результат с помощью созданного Вами шаблона. Как будут
	проинициализированы элементы вектора?
	*/

	vector<double> vDouble1(5);//Нулями // Почему???
	cout << vDouble1;
	stop

	/*
	Bектор объектов типа MyString с начальным размером - 5 элементов
	и инициализацией каждого элемента строкой "A"
	C помощью функции at() а также с помощью оператора
	индексирования []  измените значения каких-либо элементов.
	Попробуйте "выйти" за границы вектора с помощью at() и
	с помощью []. 
	*/
	
	vector<MyString> MS(5,"A");
	stop
	cout << MS << endl;
	stop

	/*
	Bектор вещественных - vDouble3, который является копией элементов
	[0,5) массива вещественных чисел dMas. Предворительно массив dMas
	нужно создать и проинициализировать!
	*/

	double dMas[] = { 1, 2, 3, 4, 5};
	vector<double> vDouble3(dMas,dMas + sizeof(dMas)/sizeof(double));
	stop

	/*
	Bектор вещественных - vDouble4, который является копией элементов
	[2,5) вектора vDouble3. 
	*/

	//sizeof(vDouble3) всегда равно 16!!!!!!!!!!!!!!! Потому что в векторе содержиться 3 указателя в аллокаторе и что-то ещё.
	//vector<double> vDouble4(&vDouble3[1], &vDouble3[1] + sizeof(vDouble3) / vDouble3.size());
	vector<double> vDouble4(&vDouble3[1], &vDouble3[1] + 3);
	stop
	/*
	Bектор элементов типа Point - vPoint1
	а) с начальным размером 3. Какой конструктор
	будет вызван для каждого элемента?
	b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).
	*/
	
	vector<Point> vPoint1(3); //Будет вызван написаный в Point конструктор;
	stop
	vector<Point> vPoint2(5,Point(1,1));
	cout << vPoint2;
	stop

	/*
	Bектор указателей на Point - vpPoint с начальным размером 5
	Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
			
	Подсказка: для вывода на печать значений скорее всего Вам понадобится
	а) специализация Вашей шаблонной функции
	б) или перегрузка operator<< для Point*
	*/

	{//Добавил delite
	size_t I = 5;
	vector<Point*> vPoint1(I);// ,new Point());
	stop
	cout << vPoint1 << endl;
	stop//Перегрузить push и pop
		for (size_t i = 0 ; i < I ; i++)
		{
			vPoint1.push_back( (new Point(i, i)) ); //	Как вариант	vPoint1[i] = new  Point(i,i);
			stop

		}
	cout << vPoint1 << endl;
	stop
	for (size_t i = 0; i < vPoint1.size(); i++)
	{
		delete vPoint1[i];
	}
	stop
	}//Какие дополнительные действия нужно предпринять для такого вектора? ----- Добавить delite


	///////////////////////////////////////////////////////////////////////
	//Резервирование памяти.
	//Подумайте, всегда ли верны приведенные ниже проверки?
	/*
	{
	size_t n=...
	vector<int> v(n);
	v.resize(n/2);
	if(v.capacity() == n) //true?--------------------------------------Да 
 	}
	*/

	/*
	{
	int n=...
	size_t m=...
	vector<int> v(n);
	v.reserve(m);
	if(v.capacity() == m) //true?--------------------------------------Нет
	}
	*/

	/*
	{
	vector<int> v(3,5);---------------------5 5 5
	v.resize(4,10); //значения?-------------5 5 5 10
	v.resize(5); //значения?----------------5 5 5 10 0

	}
	*/

	/*
	Создайте два "пустых" вектора с элементами
	любого (но одного и того же типа) типа.
	В первом векторе зарезервируйте память под 5 элементов, а потом заполните
	его значениями с помощью push_back.
	Второй вектор просто заполните значениями посредством push_back.
		
	Сравните размер, емкость векторов и значения элементов
	*/
	vector<int> v1;
	vector<int> v2;
	stop
	v1.reserve(5);
	cout << v1;
	stop
	size_t N = 5;
		for (size_t i = 0 ; i < N ; i++)//Добавляет по 2 до чётного количества
		{
			v1.push_back(i * 5);
			cout << v1;
			stop
		}
	stop
	cout << "----------------------------------------------------------------------------------------------------" << endl;
		for (size_t i = 0; i < N; i++)//Добавляет по 2 до чётного количества начиная с 4
		{
			v2.push_back(i * 5);
			cout << v2;
			stop
		}
	stop

	/*
	!!! shrink_to_fit - Уменьшение емкости вектора.
	Для любого вектора из предыдущего задания требуется уменьшить емкость до size.
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
		Создание "двухмерного вектора" - вектора векторов
		Задан одномерный массив int ar[] = {11,2,4,3,5};
		Создайте вектор векторов следующим образом:
		вектор vv[0] - содержит 11 элементов со значением 11
		vv[1] - содержит 2,2
		vv[2] - содержит 4,4,4,4
		...
		Распечатайте содержимое такого двухмерного вектора по строкам
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
Вставка элемента последовательности insert().
В вектор vChar2 вставьте в начало вектора символ только при	условии, что в векторе такого еще нет.
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
	//Вставьте перед каждым элементом вектора vChar2 букву 'W'
	size_t cnt = vChar2.size();
	for (size_t i = 0; i < cnt; i++)
	{ 
		vChar2.insert(vChar2.begin() + i * 2,'W');// Почему нельзя указать в качестве первого аргумента адрес? А нужен только итератор.
	}
	stop
		///////////////////////////////////////////////////////////////////
	/*
	Напишите функцию, которая должна удалять только повторяющиеся последовательности.
	Например: было - "qwerrrrty12222r3", стало - "qwety1r3"
	*/
	//char *str = "qwe"; // Попросить прокоментировать, понадобилось const, (при такой инициализоции размещение в статитческой памяти)
	vector<char> vChar = { 'q','w','e','r','r','r','r','t','y','1','2','2','2','2','r','3' };
	delString(vChar);
	cout << vChar << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	stop
///////////////////////////////////////////////////////////////////
/*
Удаление элемента последовательности erase()
Напишите функцию удаления из любого вектора всех дублей
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
		if (it1 != vChar3.end()) { ++it2; }//Тут пожно покрасивше
		stop
	}
	cout << vChar3 << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	stop
///////////////////////////////////////////////////////////////////
/*
Создайте новый вектор таким образом, чтобы его элементы стали
копиями элементов любого из созданных ранее векторов, но расположены
были бы в обратном порядке
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
Задание 1. Списки. Операции, характерные для списков.
Создайте пустой список из элементов Point - ptList1 и наполните
его значениями с помощью методов push_back(),
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
		Напишите шаблон функции, которая будет выводить элементы
		ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
		vector и list. Подсказка - хотелось бы увидеть тип контейнера.
		*/
	ContOut(ptList1);
	ContOut(vChar3);
	stop
/*
Сделайте любой из списков "реверсивным" - reverse()
*/
	ptList1.reverse();
	stop
/*
Создайте список ptList2 из элементов Point таким образом, чтобы он стал
копией вектора элементов типа Point, но значения элементов списка располагались
бы в обратном порядке
*/
	vector<Point> vPoint = {Point(1,1),Point(2,2) ,Point(3,3) };
	list<Point> ptList2(vPoint.rbegin(), vPoint.rend());
	stop
/*
Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
по возрастанию.
Подумайте: что должно быть перегружено в классе Point для того, чтобы
работала сортировка/
*/
	ptList1.sort();
	ptList2.sort();
	stop
/*
Объедините отсортированные списки - merge(). Посмотрите: что
при этом происходит с каждым списком.
*/

	ptList1.merge(ptList2); // Элементы !!!переносятся!!! и сортируются
	stop
/*
Исключение элемента из списка - remove()
Исключите из списка элемент с определенным значением.
Подумайте: что должно быть перегружено в классе Point?
*/
	ptList1.remove(Point(1,1));//Нужно перегрузить оператор ==
	stop
/*
Исключение элемента из списка, удовлетворяющего заданному условию:
любая из координат отрицательна - remove_if().
*/
	ptList1.remove_if(del_two);
	stop
/*Исключение из списка подряд расположенных дублей - unique().*/
		ptList1.unique();
	stop

///////////////////////////////////////////////////////////////////
/*
	Задание 2.Очередь с двумя концами - контейнер deque

	Создайте пустой deque с элементами типа Point. С помощью
	assign заполните deque копиями элементов вектора. С помощью
	разработанного Вами в предыдущем задании универсального шаблона
	выведите значения элементов на печать
*/
	deque<Point> dPoint;
	dPoint.assign(2, Point(5,5));
	stop
	ContOut(dPoint);
	stop
/*
	Создайте deque с элементами типа MyString. Заполните его значениями
	с помощью push_back(), push_front(), insert()
	С помощью erase удалите из deque все элементы, в которых строчки
	начинаются с 'A' или 'a'
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
		const MyString qq = (*iterator).GetString();//Мне ненравится делать константный объект!!!
		const char *q = qq.GetString();
		if ((q[0] == 'A') || (q[0] == 'a'))
		{
			iterator = dMS.erase(iterator);
		}
		else { ++iterator; };
	}
	stop//Так же можно пробежаться циклом через [];

	return 0;
}