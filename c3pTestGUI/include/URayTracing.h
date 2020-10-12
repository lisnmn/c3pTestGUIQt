/********************************************************************

Copyright (C), 2019, All rights reserved

File Name     :    URayTracing.cpp
Description   :
History       :

<author>            <time>            <desc>
Ang Li             2019/6/8           create

********************************************************************/
/****************************************************************************************************
 * �˴�����㷽���Ĳο�����Ϊ:
 * "Fast calculation of the exact radiological path for a three-dimensional CT array"
*****************************************************************************************************/
#ifndef __RAYTRACING_H
#define __RAYTRACING_H
#include "libOSEM_global.h"
#include "UVolume.h"

class UImage;
class UOneLor;
/*********************************************************************************
 * �ṩ����һ�����ߴ���ͼ������ص������ͳ��ȵĺ���
 * 20190125�Ż����Ż������ڴ�ķѵ�ʱ��
 * ע�⣺������Ҫ��ֹ���߳�ʱ��������д��ʱ�ľ�������
 * ���飺ÿ���̷ֱ߳��������ʵ��
**********************************************************************************/
class LIBOSEM_EXPORT URayTracing
{
public:
	URayTracing();
	~URayTracing();
	/**********************************************************
	Description:		Calculate a 3D raytracing for one ray.
	Arguments:
	{
	ray:			Return the lenth of the ray across the each voxel.
	img:			The calculated image object.
	point1:			One end of the ray.
	point2:			Another end of the ray.
	}
	Return:				Status.
	**********************************************************/
	void GetOneLorResponse3D(UOneLor &ray, const UImage &img, UVolume3D<double> & point1, UVolume3D<double> &point2);
private:
	URayTracing(const URayTracing&){};
	URayTracing& operator=(const URayTracing&){};
private:
	//���ڴ����������ı���ϵ�������飬Ϊ�˼��ٿ����ͷŵ�ʱ�䣬�����ʼ���ͽ���ʱ���ٺ��ͷ���Щ������ڴ档
	double *m_ax;
	double *m_ay;
	double *m_az;
	double *m_aAll;
};

#endif
