/********************************************************************

Copyright (C), 2019, All rights reserved

File Name     :    UOneLor.h
Description   :
History       :

<author>            <time>            <desc>
Ang Li             2019/6/8           create

********************************************************************/
#ifndef __ONE_LOR_H
#define __ONE_LOR_H
#include "libOSEM_global.h"

/*********************************************************************************
* ��¼һ�����ߴ���ͼ������ص������ͳ���
* 20190125�Ż���ʵ����ʱ��ʼ��������󳤶ȣ�ʹ��ʱ����󳤶Ȳ������Զ���չ
**********************************************************************************/
class LIBOSEM_EXPORT UOneLor
{
public:
	UOneLor(int nVoxelNumMax);		//��ʼ������һ����ʼ������鳤��
	~UOneLor();
	UOneLor(const UOneLor& lor);		//�������캯��

public:
	/**********************************************************
	Description:		Set the number of pixel on a LOR. It will automatically expand the memory when memory are not enough.
	Arguments:
	{
	nVoxelNum:		The number of voxel in LOR will be set.
	}
	Return:				Status.
	**********************************************************/
	bool SetVoxelNum(int nVoxelNum);
	/**********************************************************
	Description:		Add a voxel and its weight in this LOR.
	Arguments:
	{
	nVoxelID:		Voxel index
	fWeight:		System response weight of the voxel in this LOR
	}
	Return:				Status.
	**********************************************************/
	bool AddVoxel(int nVoxelID, float weight);
	/**********************************************************
	Description:		Clear all the voxels and weights in this LOR.
	Arguments:
	{

	}
	Return:				void.
	**********************************************************/
	void Clear();
	/**********************************************************
	Description:		Get the number of voxels in this LOR.
	Arguments:
	{

	}
	Return:				The number of voxels in this LOR.
	**********************************************************/
	int GetVoxelNum()const;

public:
	//Ϊ�˷���ʹ��public��������[m_]ǰ׺
	float *pWeight;					//��ʾϵͳ��Ӧ����ĸ���ֵ����raytracing�б�ʾ���ߴ������صĳ��ȣ���λ��Ϊmm���ټ�����
	int *pVoxelID;
private:
	UOneLor& operator=(const UOneLor& lor){};
private:
	int m_nVoxelNum;
	int m_nVoxelNumMax;
};

#endif
