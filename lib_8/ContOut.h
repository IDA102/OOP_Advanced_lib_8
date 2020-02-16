#pragma once
template<typename T> void ContOut(T &cont)
{
	cout << "Container type: " << typeid(cont).name() << endl;
	stop
	typename T::iterator first = cont.begin();
	typename T::iterator last = cont.end();
	while (first != last)
	{
		cout << *first << endl;
		++first;
	}
	cout << endl;
}