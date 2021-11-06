#pragma once
#include <iostream>
class se
{
private:
	int* _data;
	int _size;
public:
	se()
	{
		_size = 1;
		_data = NULL;
	};
	se(int* _data, int _size);
	//se(const int size);
	se(const se& rhs);
	int get_size() const;
	~se()
	{
		delete[] _data;
	}
	int& operator()(int size);
	void operator()(int col, int val);
	se operator-(se&);
	se operator*(se&);
	se operator+(se&);
	se operator%(int);
	se operator/(int);
	friend std::ostream& operator<<(std::ostream& s, const se& o);
};