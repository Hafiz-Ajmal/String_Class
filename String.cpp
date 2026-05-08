#include <iostream>
#include "String.h"
using namespace std;

String::String()
{
	data = nullptr;
	size = 0;

}
String::String(const char c)
{
	size = 2;
	data = new char[size];
	data[0] = c;
	data[1] = '\0';

}
String::String(const char* src)
{

	size = getLength(src) + 1;
	data = new char[size];
	copyString(src);


}
String::String(const String& a) :String()
{
	if (a.data != nullptr && a.data[0] != '\0')
	{
		size = a.size;
		data = new char[size + 1];
		int i;
		for (i = 0; i < size; i++)
		{
			data[i] = a.data[i];
		}
		data[i] = '\0';

	}
	else
	{
		data = nullptr;
		size = 0;
	}
}
String::String(String&& s)
{
	data = s.data;
	size = s.size;
	s.data = nullptr;
	s.size = 0;

}
String& String::operator=(String&& s)
{
	if (this == &s)
	{
		return *this;
	}
	delete[] data;
	data = s.data;
	size = s.size;
	s.data = nullptr;
	s.size = 0;
	return *this;
}
String::~String()
{
	delete[] data;
	data = nullptr;
	size = 0;
}
String& String::operator =(const String& a)
{
	if (this == &a)
		return *this;
	if (a.data != nullptr && a.data[0] != '\0')
	{
		size = a.size;
		delete[] data;
		data = new char[size + 1];
		int i;
		for (i = 0; i < size; i++)
		{
			data[i] = a.data[i];
		}
		data[i] = '\0';

	}
	else
	{
		data = nullptr;
		size = 0;
	}
	return *this;
}
String& String::operator= (const long long int num)
{

	int len = getIntegerLength(num), i = 0;
	long long int n = num;
	if (n < 0)
	{
		n = -num;
	}
	delete[] data;
	data = new char[len + 1];
	i = len - 1;
	data[i--] = '\0';
	if (n == 0)
	{
		data[i--] = '0';
	}
	for (; i >= 0 && n > 0; i--)
	{

		data[i] = (n % 10) + '0';
		n = n / 10;

	}
	if (num < 0)
	{
		data[0] = '-';
	}
	
	size = len + 1;
	return *this;
}
bool String::operator ! () const
{
	if (data == nullptr || data[0] == '\0')
	{
		return true;
	}
	return false;

}
String::operator long long int() const
{
	int i = 0;
	long long int num=0;
	int sign = 1;
	if (data[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (data[i] != '\0')
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			num = num * 10 + (data[i] - '0');
			i++;
		}
		else
		{
			cout << " invalid input for operator long long int\n";
			exit(0);
		}
		
	}

	return num * sign;
}
String::operator double() const
{
	if (!data||data[0]=='\0')
	{
		return 0.00;
	}
	int i = 0;
	double num = 0;
	double frac = 0;
	long long  int ten = 1;
	bool fraction = 0;
	int sign = 1;
	if (data[0] == '-')
	{
		sign = -1;
		i++;
	}
	
	while (data[i] != '\0')
	{
		if (data[i] == '.')
		{
			fraction = 1;
			
		}
		if (!fraction)
		{
			
			num =num* 10+(data[i]-'0');
		}
		if (fraction && data[i] != '.')
		{
			frac = frac * 10 + (data[i] - '0');
			ten *= 10;
		}
		i++;
		
	}
	double result = num + (frac / ten);

	return result * sign;
}
String::operator bool() const
{
	return (data != nullptr && data[0] != '\0');
}
void String::copyString(const char* src)
{
	int i = 0;
	for (i = 0; src[i] != '\0'; i++)
	{
		data[i] = src[i];
	}
	data[i] = '\0';
}
void String::copyString(const char* src, char* des)
{
	int i = 0;
	for (i = 0; src[i] != '\0'; i = i + 1)
	{
		des[i] = src[i];
	}
	des[i] = '\0';
}
int String::getIntegerLength(const long long int num)
{
	int i = 0;
	long long int  n = num;
	if (n < 0 || n == 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
	    i++;
	}
	return i;
}


int String::getLength() const
{
	if (!data)
		return 0;
	int i = 0;
	while (data[i] != '\0')
	{
		i++;
	}
	return i;
}
int String::getLength(const char* src) const
{
	int i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return i;
}
int String::getSize() const
{
	return size;
}

void String::display() const
{
	if (!operator bool())
	{
		cout << "Empty String";
		return;
	}
	cout << data;
}
int String::find(const String& subStr, const  int start) const
{
	at(start);
	int i = start, j, m, cnt = 0;
	while (data[i] != '\0')
	{
		j = 0;
		if (data[i] == subStr.data[j])
		{
			m = i;
			while ((subStr.data[j] != '\0') && (data[m] == subStr.data[j]))
			{
				j = j + 1;
				m = m + 1;
			}
		}
		if (j == subStr.getLength())
		{
			return i;
		}
		i++;
	}
	return -1;
}
void String::insert(const int index, const String& subStr)
{
	int len = getLength();
	int ind = index, j;
	if (index >= 0 && index <= getLength())
	{
		for (int i = 0; subStr.data[i] != '\0'; i = i + 1, ind = ind + 1, len = len + 1)
		{

			for (j = len; j >= ind; j--)
			{
				if (j >= size - 1)
				{
					reSize(size * 2);

				}
				data[j] = data[j - 1];
			}
			data[ind] = subStr.data[i];
		}
		data[len] = '\0';
	}

}


void String::reSize(int capacity)
{
	if (capacity <= 0)
	{
		data = nullptr;
		size = 0;
		return;
	}
	else
	{
		char* temp = new char[capacity];
		int i = 0;
		while (i < capacity - 1 && i < size - 1)
		{
			temp[i] = data[i];
			i++;
		}
		temp[i] = '\0';
		delete[] data; //this->~String();
		size = capacity;
		data = temp;
	}
}
int String::replace(const String& old, const  String& newSubStr)
{
	int newSubStrLen = newSubStr.getLength();
	int oldStrLen = old.getLength();
	int i = 0, count = 0, index = 0;
	bool flag = 1;
	while (flag == 1 && data[i] != '\0')
	{

		index = find(old, i);
		if (index == -1)
		{
			flag = 0;

		}
		else
		{
			remove(index, oldStrLen);
			insert(index, newSubStr);
			i = index + newSubStrLen;
			count = count + 1;
		}
	}

	return count;
}

int String::operator==(const String& s2) const
{
	int i = 0;

	while (data[i] != '\0' && s2.data[i] != '\0')
	{
		if (data[i] != s2.data[i])
		{
			return false;
		}
		i++;
	}
\
	return (data[i] == '\0' && s2.data[i] == '\0');
}

String String::operator+(const String& s2) const
{

	String x;

	x.size = getLength() + s2.getLength();
	x.data = new char[x.size + 1];
	x.copyString(data);
	int index = x.getLength();
	x.insert(index, s2.data);
	return x;


}
void String::operator +=(const String& s2)
{
	int len = getLength();
	insert(len, s2);
}
String String::right(const int count)
{

	String x;
	x.size = count + 1;
	x.data = new char[x.size];
	int i, len;
	len = getLength();
	len = len - 1;
	for (i = 0; len >= 0 && i < count; i++, len--)
	{
		x.data[i] = data[len];
	}
	x.data[i] = '\0';
	return x;

}
String String::left(const int count)
{
	String x;
	x.size = count + 1;
	x.data = new char[x.size];
	int i;
	for (i = 0; i < count && data[i] != '\0'; i++)
	{
		x.data[i] = data[i];
	}
	x.data[i] = '\0';
	return x;
}
void String::shrink()
{
	reSize(this->getLength() + 1);
}
void String::reverse()
{
	int len = this->getLength();
	len = len - 1;
	char c;
	for (int i = 0; i < len; i++, len--)
	{
		c = data[i];
		data[i] = data[len];
		data[len] = c;
	}
}
void String::makeUpper()
{
	for (int i = 0; data[i] != '\0'; i++)
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			data[i] = data[i] - 32;
		}
	}
}
void String::makeLower()
{
	for (int i = 0; data[i] != '\0'; i++)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = data[i] + 32;
		}
	}
}
void String::trimLeft()
{
	int i = 0, cnt = 0;
	while (data[cnt] == ' ' || data[cnt] == '\n' || data[cnt] == '\t')
	{
		cnt++;
	}
	while (data[cnt] != '\0')
	{
		data[i] = data[cnt];
		i++;
		cnt++;
	}
	data[i] = '\0';
}
void String::trimRight()
{
	int len = this->getLength();
	len = len - 1;
	while (data[len] == ' ' || data[len] == '\n' || data[len] == '\t')
	{
		data[len] = '\0';
		len = len - 1;
	}
}
void String::trim()
{
	trimRight();
	trimLeft();
}
void String::remove(const int index, const int count)
{
	at(index);
	int i = index + count;
	int ind = index;
	if (i < this->getLength())
	{
		for (; data[i] != '\0'; i++, ind++)
		{
			data[ind] = data[i];
		}
		data[ind] = '\0';
	}
	else
	{
		data[ind] = '\0';
	}
	shrink();
}
void String::input()
{
	size = 2;                  // start with space for 1 char + '\0'
	data = new char[size];
	int count = 0;
	char ch;

	while ((ch = cin.get()) != '\n') {
		if (count + 1 == size) {   // check before writing
			reSize(size * 2);
		}
		data[count++] = ch;
	}
	data[count] = '\0';
}

char& String::at(const int index)
{
	if (index >= 0 && index < getLength(data))
	{
		return data[index];
	}
	else
	{
		cout << "Invalid Index";
		exit(0);
	}
}
const char& String::at(const int index) const
{
	if (index >= 0 && index < this->getLength())
	{
		return data[index];
	}
	else
	{
		cout << "Invalid Index";
		exit(0);
	}
}

String String::operator()(const String& delim)
{
	if (*this)
	{

		return String();
	}

	int j = delim.getLength() - 1;
	int k = j;
	int m = getLength();
	String s;
	s.data = new char[size + 1];
	int i = 0, l = 0;
	bool flag = 1;
	for (; i < getLength() && flag == 1; i++, l++)
	{
		while (j >= 0)
		{
			if (data[i] == delim.data[j])
			{
				l = m;
				flag = 0;

			}
			j--;
		}
		j = k;

		if (l != m)
		{
			s.data[i] = data[i];
		}
	}
	this->remove(0, i);
	if (i != m)
	{
		i--;
	}
	s.size = i;
	s.data[i] = '\0';
	//pos=pos+(j+1);
	return s;
}
char& String::operator[](const int index)
{
	if (index >= 0 && index <= size)
	{
		return data[index];
	}
	exit(0);
}
const  char& String::operator[](const int index) const
{
	if (index >= 0 && index <= size)
	{
		return data[index];
	}
	exit(0);
}

istream& operator>>(istream& op, String& s)
{
	
	s.input();
	return op;
}
ostream& operator <<(ostream& op, String& s)
{
	
	s.display();
	return op;
}
//String& String::operator=(const double num) {
//	delete[] data;
//
//	long long intPart = (long long)num;
//	double fracPart = num - intPart;
//
//	// Convert integer part first
//	String intStr;
//	intStr = intPart;
//
//	// For fractional part, take some precision (e.g., 6 digits)
//	char frac[20];
//	int fracLen = 0;
//	if (fracPart != 0.0) {
//		frac[fracLen++] = '.';
//		for (int i = 0; i < 6; ++i) { // 6 decimal places
//			fracPart *= 10;
//			int digit = (int)fracPart;
//			frac[fracLen++] = digit + '0';
//			fracPart -= digit;
//		}
//	}
//	frac[fracLen] = '\0';
//
//	// join integer + fractional
//	int totalLen = intStr.getLength() + fracLen;
//	data = new char[totalLen + 1];
//	strcpy(data, intStr.data);
//	strcat(data, frac);
//
//	size = totalLen;
//	return *this;
//}