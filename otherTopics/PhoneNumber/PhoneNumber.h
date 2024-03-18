#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include <string>

class PhoneNumber
{
	//友元函数 返回类型 函数名要加<< 两个参数 输出流对象和号码对象
	friend std::ostream& operator << (std::ostream&, const PhoneNumber&);
	friend std::istream& operator >> (std::istream&, PhoneNumber&);
private:
	std::string areaCode;
	std::string exchange;
	std::string line;
};

#endif
