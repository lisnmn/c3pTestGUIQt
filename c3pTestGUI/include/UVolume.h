/********************************************************************

Copyright (C), 2019, All rights reserved

File Name     :    UVolume.h
Description   :
History       :

<author>            <time>            <desc>
Ang Li             2019/6/8           create

********************************************************************/
#ifndef __VOLUME_H
#define __VOLUME_H
#include "libOSEM_global.h"
#include <iostream>

//A template class for 3-dimension value
template <class T>
class LIBOSEM_EXPORT UVolume3D
{
public:
	T x;
	T y;
	T z;
public:
	UVolume3D() { x = 0; y = 0; z = 0; };
	UVolume3D(T xx, T yy, T zz)
	{
		x = xx; y = yy; z = zz;
	}
	UVolume3D(const UVolume3D & temp)
	{
		x = temp.x;
		y = temp.y;
		z = temp.z;
	}
	void set(T xx, T yy, T zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}
	void exchange(UVolume3D &src)//两变量进行交换
	{
		UVolume3D temp = src;
		src = *this;
		*this = temp;
	}
	UVolume3D crossMul(UVolume3D &vector)const//向量叉乘，慎用
	{
		UVolume3D result;
		result.x = y * vector.z - vector.y * z;
		result.y = z * vector.x - vector.z * x;
		result.z = x * vector.y - vector.x * y;
		return result;
	}
	//运算符重载
	UVolume3D &operator=(const UVolume3D & temp)
	{
		if (this != &temp)
		{
			x = temp.x;
			y = temp.y;
			z = temp.z;
		}
		return *this;
	}
	UVolume3D operator+(const UVolume3D &temp)const// '+'
	{
		return UVolume3D(x + temp.x, y + temp.y, z + temp.z);
	}
	UVolume3D operator-(const UVolume3D &temp)const// '-'
	{
		return UVolume3D(x - temp.x, y - temp.y, z - temp.z);
	}
	UVolume3D operator+(double k)const// '+'//20190604 updated
	{
		return UVolume3D(x + k, y + k, z + k);
	}
	UVolume3D operator-(double k)const// '-'
	{
		return UVolume3D(x - k, y - k, z - k);
	}
	T operator*(const UVolume3D &temp)const// '*'点乘
	{
		return x * temp.x + y * temp.y + z * temp.z;
	}
	UVolume3D operator*(double k)const// '*k'
	{
		return UVolume3D(x*k, y*k, z*k);
	}
	UVolume3D operator/(double k)const// '/k'
	{
		return UVolume3D(x / k, y / k, z / k);
	}
	//由于是模板类，不确定数据类型，无法使用标准输出，只能用cout
	friend std::ostream &operator<<(std::ostream &output, const UVolume3D &temp)//friend将<<运算符重载为友元函数
	{

		output << "( " << temp.x << " , " << temp.y << " , " << temp.z << " ) ";
		return output;
	}
};

template <class T>
class LIBOSEM_EXPORT UVolume2D
{
public:
	T x;
	T y;
public:
	UVolume2D() { x = 0; y = 0; };
	UVolume2D(T xx, T yy)
	{
		x = xx; y = yy;
	}
	UVolume2D(const UVolume2D & temp)
	{
		x = temp.x;
		y = temp.y;
	}
	void set(T xx, T yy)
	{
		x = xx;
		y = yy;
	}
	void exchange(UVolume2D &src)
	{
		UVolume2D temp = src;
		src = *this;
		*this = temp;
	}
	UVolume2D &operator=(const UVolume2D & temp)
	{
		if (this != &temp)
		{
			x = temp.x;
			y = temp.y;
		}
		return *this;
	}
	UVolume2D operator+(const UVolume2D &temp)const// '+'
	{
		return UVolume2D(x + temp.x, y + temp.y);
	}
	UVolume2D operator-(const UVolume2D &temp)const// '-'
	{
		return UVolume2D(x - temp.x, y - temp.y);
	}
	UVolume2D operator+(double k)const// '+'//20190604 updated
	{
		return UVolume2D(x + k, y + k);
	}
	UVolume2D operator-(double k)const// '-'
	{
		return UVolume2D(x - k, y - k);
	}
	T operator*(const UVolume2D &temp)const// '*'点乘
	{
		return x * temp.x + y * temp.y;
	}
	UVolume2D operator*(double k)const// '*k'
	{
		return UVolume2D(x*k, y*k);
	}
	UVolume2D operator/(double k)const// '/k'
	{
		return UVolume2D(x / k, y / k);
	}
	friend std::ostream &operator<<(std::ostream &output, const UVolume2D &temp)//friend将<<运算符重载为友元函数
	{

		output << "( " << temp.x << " , " << temp.y << " ) ";
		return output;
	}
};

#endif
