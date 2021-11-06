#include "set1.h"
std::ostream& operator<<(std::ostream& s, const se& o)
{
	s << "(";
	for (int i = 0; i < o._size; i++)
	{
		if (o._data[i] != NULL)
		{
			s << o._data[i];
			if (i != o._size) s << ';';
		}
	}
	s << '0';
	s << ')';
	return s;
}
//se::se()
//{
//	/*_size = 0;
//	_data = NULL;*/
//}
int se::get_size() const
{
	return _size;
}
//se::se(const int size)
//{
//	_size = size;
//	_data = new int[_size];
//}
se::se(int* _data, int _size)
{
	for (int i = 0; i < _size; ++i)
	{
		int k = i + 1;
		for (k; k < _size; ++k)
		{
			if (_data[i] == _data[k])
			{
				_data[k] = NULL;
			}
		}
	}
	this->_size = _size;
	this->_data = new int[_size];

	for (int i = 0; i < _size; i++)
	{
		this->_data[i] = _data[i];
	}
}

se::se(const se& rhs)
{
	this->_size = rhs._size;

	this->_data = new int[rhs._size];

	for (int i = 0; i < _size; i++)
	{
		this->_data[i] = rhs._data[i];
	}
}

int& se::operator() (int col)
{
	if (col >= _size || col < 0)
		throw"incorrect size";
	return _data[col];
}
void se::operator() (int col, int val)
{
	if (col < 0 || col >= _size)
		throw"incorrect size";
	_data[col] = val;
}
se se:: operator%(int term)
{
	int a = 0;
	for (int i = 0; i < _size; ++i)
	{
		if (_data[i] == term)
		{
			++a;
			break;
		}
	}
	if (a == 0)
	{
		_data[_size] = term;
		++_size;
	}

	return *this;
}
se se:: operator/(int term)
{

	for (int i = 0; i < _size; ++i)
	{
		if (_data[i] == term)
		{
			for (i; i < _size; ++i)
			{
				_data[i] = _data[i + 1];
				if (i == _size - 1)
				{
					_data[i] = NULL;
				}
			}
			break;
		}
	}
	return *this;
}
se se::operator+(se& obj2)
{
	int k = 0;
	for (int i = 0; i < _size; ++i)
	{
		if (_data[i] != NULL)
			k++;
	}
	for (int i = 0; i < obj2._size; ++i)
	{
		if (obj2._data[i] != NULL)
			k++;
	}
	int* m = new int[k];
	int t = 0;
	for (int i = 0; i < _size; ++i)
	{
		if (_data[i] != NULL)
		{
			m[t] = _data[i];
			t++;
		}
	}
	for (int i = 0; i < obj2._size; ++i)
	{
		if (obj2._data[i] != NULL)
		{
			m[t] = obj2._data[i];
			t++;
		}
	}se obj3(m, k);

	return obj3;
}
se se::operator-(se& obj2)
{
	int d = 0;
	for (int i = 0; i < _size; i++)
	{
		int t = 0;
		for (int j = 0; j < obj2._size; j++)
		{
			if (_data[i] != obj2._data[j])
			{
				t++;
				if (t == obj2._size)
				{
					d++;
				}
			}
		}
	}
	int* n = new int[d];
	int c = 0;
	for (int i = 0; i < _size; i++)
	{
		int t = 0;
		for (int j = 0; j < obj2._size; j++)
		{
			if (_data[i] != obj2._data[j])
			{
				t++;
				if (t == obj2._size)
				{
					n[c] = _data[i];
					c++;
				}
			}
		}
	}se obj4(n, d);
	return obj4;
}

se se::operator*(se& obj2)
{
	int k = 0;
	for (int i = 0; i < _size; ++i)
	{
		for (int j = 0; j < obj2._size; ++j)
		{
			if (_data[i] == obj2._data[j])
			{
				k++;
			}
		}
	}
	int* v = new int[k];
	int t = 0;
	for (int i = 0; i < _size; ++i)
	{
		for (int j = 0; j < obj2._size; ++j)
		{
			if (_data[i] == obj2._data[j])
			{
				v[t] = _data[i];
				t++;
			}
		}
	}
	se obj5(v, k);
	return obj5;
}