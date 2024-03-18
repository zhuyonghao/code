#ifndef TIME_H
#define TIME_H

class Time
{
public:
	explicit Time(int = 0, int = 0, int = 0);
	Time& setTime(int, int, int);
	Time& setHour(int);
	Time& setMinute(int);
	Time& setSecond(int);

	unsigned int getHour() const;
	unsigned int getMinute() const;
	unsigned int getSecond() const;

	void printUniversal() const;
	void printStandard() const;

private:
	unsigned int hour;
	unsigned int minute;
	unsigned int second;
};

#endif