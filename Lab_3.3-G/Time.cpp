//Time.cpp

#include "Time.h"
#include <iostream>

void Time::SetHour(unsigned int value)
{
	if (value > 23 || value < 0)
		value = 0;
	this->hour = value;
}

void Time::SetMinute(unsigned int value)
{
	if (value > 59 || value < 0)
		value = 0;
	this->minute = value;
}

void Time::SetSecond(unsigned int value)
{
	if (value > 59 || value < 0)
		value = 0;
	this->second = value;
}

Time::Time()
	:hour(0), minute(0), second(0)
{}

Time::Time(unsigned int y, unsigned int m, unsigned int d)
{
	SetHour(y);
	SetMinute(m);
	SetSecond(d);
}

Time::Time(const Time& v)
{
	*this = v;
}

Time& Time::operator = (const Time& n)
{
	hour = n.hour;
	minute = n.minute;
	second = n.second;
	return *this;
}

Time::~Time()
{}

Time::operator string () const
{
	stringstream sout;
	sout << " " << hour << ":" << minute << ":" << second;
	return sout.str();
}

ostream& operator <<(ostream& out, const Time& p)
{
	out << string(p);
	return out;
}

istream& operator >>(istream& in, Time& p)
{
	unsigned int h, m, s;
	do {
		cout << " Enter hour: "; in >> h;
	} while (h > 23 || h < 0);

	do {
		cout << " Enter minute: "; in >> m;
	} while (m > 59 || m < 0);

	do {
		cout << " Enter second: "; in >> s;
	} while (s > 59 || s < 0);

	p.SetHour(h);
	p.SetMinute(m);
	p.SetSecond(s);
	return in;
}

Time& Time::operator --()
{
	--hour;
	return *this;
}

Time& Time::operator ++()
{
	++hour;
	return *this;
}

Time Time::operator --(int)
{
	Time a = *this;
	second--;
	//--second;
	return a;
}

Time Time::operator ++(int)
{
	Time a = *this;
	second++;
	//++second;
	return a;
}

bool operator <(const Time& T1, const Time& T2)
{
	return T1.hour < T2.hour ||
		T1.hour == T2.hour && T1.minute < T2.minute ||
		T1.hour == T2.hour && T1.minute == T2.minute && T1.second < T2.second;
}

bool operator == (const Time& T1, const Time& T2)
{
	return T1.hour == T2.hour && T1.minute == T2.minute && T1.second == T2.second;
}

bool operator > (const Time& T1, const Time& T2)
{
	return T1.hour > T2.hour ||
		T1.hour == T2.hour && T1.minute > T2.minute ||
		T1.hour == T2.hour && T1.minute == T2.minute && T1.second > T2.second;
}

bool operator <=(const Time& T1, const Time& T2)
{
	return !(T1 > T2);
}

bool operator >= (const Time& T1, const Time& T2)
{
	return !(T1 < T2);
}

bool operator != (const Time& T1, const Time& T2)
{
	return !(T1 == T2);
}

Time& Time::operator - (int substr)
{
	if (substr < 1)
		substr = 1;

	do {
		if (substr < second)
		{
			second = second - substr;
			substr = 0;
		}
		else {
			substr = substr - second;
			if (minute == 0)//1//60
			{
				minute = 60;//12//0//59
				hour--;
			}
			else {
				minute--;
				second = 60;
			}
		}
	} while (substr != 0);

	return *this;
}


Time& Time::operator + (int seconds)
{
	short SecondsLeft;
	do {
		SecondsLeft = 60 - second;
		if (seconds < SecondsLeft)
		{
			second = second + seconds;
			seconds = 0;
		}
		else
		{
			second = second + SecondsLeft;
			seconds = seconds - SecondsLeft;
			if (minute == 60)
			{
				minute = 0;//
				hour++;
			}
			else
			{
				second = 0;//
				minute++;
			}
		}
	} while (seconds != 0);
	return *this;
}

unsigned int Time::ToSeconds()
{
	unsigned int t;
	t = hour * 3600 + minute * 60 + second;
	return t;
}

unsigned int Time::ToMinutes()
{
	unsigned int t;
	if (second < 1)
	{
		t = hour * 60 + minute;
	}
	if (second > 0)
	{
		t = hour * 60 + minute + 1;
	}
	return t;
}

unsigned int Difference(Time T1, Time T2)
{
	return T2.ToSeconds() - T1.ToSeconds();
}

unsigned int DifferenceForT(Time T1, Time T2)
{
	int k;
	k = (T2.ToSeconds() - T1.ToSeconds()) / 60.;
	return k;
}

