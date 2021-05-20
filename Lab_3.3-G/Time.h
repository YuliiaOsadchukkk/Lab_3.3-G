//Time.h

#pragma once
#include "Object.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Time : public Object
{
protected:
	unsigned int hour, minute, second;

public:
	unsigned int GetHour() const { return hour; };
	unsigned int GetMinute() const { return minute; };
	unsigned int GetSecond() const { return second; };

	void SetHour(unsigned int);
	void SetMinute(unsigned int);
	void SetSecond(unsigned int);

	Time();
	Time(unsigned int, unsigned int, unsigned int);
	Time(const Time& v);

	Time& operator = (const Time&);
	operator string () const;
	~Time();

	Time& operator ++ ();
	Time& operator -- ();
	Time operator ++ (int);
	Time operator -- (int);

	friend ostream& operator << (ostream& out, const Time& p);
	friend istream& operator >> (istream& in, Time& p);


	//////////////////////////////////////////////////////////////////////
	// Порівняння моментів часу
	friend bool operator <(const Time&, const Time&);
	friend bool operator == (const Time&, const Time&);
	friend bool operator > (const Time&, const Time&);
	friend bool operator <=(const Time&, const Time&);
	friend bool operator >= (const Time&, const Time&);
	friend bool operator != (const Time&, const Time&);

	Time& operator - (int);//відніманняння з часу заданої кількості секунд
	Time& operator + (int);//додавання до часу задану кількість секунд

	friend unsigned int Difference(Time T1, Time T2);//seconds
	friend unsigned int DifferenceForT(Time T1, Time T2);//minutes
	unsigned int ToSeconds();// Переведення в секунди
	unsigned int ToMinutes();// Переведення у хвилини (з округленням до цілої хвилини)
};


