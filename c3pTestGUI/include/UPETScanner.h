/********************************************************************

Copyright (C), 2019, All rights reserved

File Name     :    UPETScanner.h
Description   :
History       :

<author>            <time>            <desc>
Ang Li             2019/6/8           create
405                2020/3/27          modify
********************************************************************/

/************************************************************************************
* PETScanner������PET̽�����ṹ����
* ʹ�÷�����1.����Ԥ�ó�ʼ��������2.�̳и��ಢ��дInit()������ʼ��̽�����ṹ��Ϣ
* Ԥ�����ú�����InitD80Scanner()InitD180Scanner()InitE80Scanner()
* ע��UVolume3D<double>��ģ���࣬��Ҫ����xyz�������Ϣ������ͬGATE�µ�����ϵ��
**************************************************************************************/

#ifndef __PET_SCANNER_H
#define __PET_SCANNER_H
#include "libOSEM_global.h"
#include "UVolume.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

class LIBOSEM_EXPORT UPETScanner
{
public:
	UPETScanner(void) {};//inline
	~UPETScanner(void) {};
	//set&get
	int GetCrystalNumOneRing()const;
	int GetRingNum()const;
	int GetBinNum()const;//20190612Updated
	int GetViewNum()const;
	int GetSliceNum()const;
	int GetLORNum()const;
	int GetCrystalNum()const;//20190612Updated
	int GetCrystalNumZInPanel()const;
	int GetCrystalNumYInPanel()const;
	int GetCrystalNumZInModule()const;
	int GetCrystalNumYInModule()const;
	int GetCrystalNumZInBlock()const;
	int GetCrystalNumYInBlock()const;
	int GetPanelNum()const;
	double GetLengthZ()const;
	double GetPanelSizeZ()const;
	double GetPanelSizeY()const;
	double GetModulePitchZ()const;
	double GetModulePitchY()const;
	double GetModuleSizeZ()const;//20190616Updated
	double GetModuleSizeY()const;
	double GetBlockPitchZ()const;
	double GetBlockPitchY()const;
	double GetBlockSizeZ()const;
	double GetBlockSizeY()const;
	double GetCrystalPitchY()const;
	double GetCrystalPitchZ()const;
	double GetCrystalSizeY()const;
	double GetCrystalSizeZ()const;
	double GetRadius()const;
	int GetCrystalClockwiseOffset()const;
	//���ݾ������ڵĻ��;����ڻ��ϵı��0-GetCrystalNumOneRing()-1�������꣬�����ĸ����˳��Ϊ0,1,2,3
	/**********************************************************
	Description:		Get the 4 vertices positions of one crystal.
	Arguments:
	{
	crystalInRing:	Crystal index in ring. At the range of [0,crystalNumOneRing-1]
	ring:			Ring index of this crystal. At the range of [0,ringNum-1]
	crystalPos:		get the crystal position which has 4 element: UVolume3D<double> crystalPos[4];
	}
	Return:				Status.
	**********************************************************/
	void GetCrystalPosition(int crystalInRing, int ring, UVolume3D<double> *crystal)const;
	//��û�����Сz������
	/**********************************************************
	Description:		Get the minimum z coordinate of one ring.
	Arguments:
	{
	ring:			Ring index of this crystal. At the range of [0,ringNum-1]
	}
	Return:				Status.
	**********************************************************/
	double GetRingMinCoordinateZ(int ring)const;
	//����LOR��ŵõ�LOR�����������ȫ�־�����
	/**********************************************************
	Description:		LORID to global crystal ID.
	Arguments:
	{
	LORID:			LOR index. At the range of [0,LORNum-1]
	crystalID1:		Get the global crystal1 index. At the range of [0,crystalNum-1]
	crystalID2:		Get the global crystal2 index. At the range of [0,crystalNum-1]
	}
	Return:				void.
	**********************************************************/
	void GetCrystalIDFromLORID(int LORID, int &crystalID1, int &crystalID2)const;
	//����LOR�����������ȫ�ֱ�ŵõ�LOR���
	/**********************************************************
	Description:		global crystal ID to LOR ID.
	Arguments:
	{
	crystalID1:		Get the global crystal1 index. At the range of [0,crystalNum-1]
	crystalID2:		Get the global crystal2 index. At the range of [0,crystalNum-1]
	LORID:			Get the LOR index. At the range of [0,LORNum-1]
	}
	Return:				void.
	**********************************************************/
	void GetLORIDFromCrystalID(int crystalID1, int crystalID2, int &LORID)const;
	//����slice�õ�ring1��ring2
	/**********************************************************
	Description:		LORID to crystal ID. Slice to ring1 and ring2
	Arguments:
	{
	slice:			slice index of this LOR.
	ring1:			Get the ring1 index. At the range of [0,ringNum-1]
	ring2:			Get the ring2 index. At the range of [0,ringNum-1]
	}
	Return:				Status.
	**********************************************************/
	void GetRing1Ring2FromSlice(int slice, int & ring1, int & ring2)const;
	//����view��bin�����ring1�ϵľ���cry1��ring2�ϵľ���cry2
	/**********************************************************
	Description:		LORID to crystal ID. view,bin to crystal1,crystal2
	Arguments:
	{
	view:			view index of this LOR.
	bin:			bin index of this LOR
	cry1:			Get the index of crystal1 on the ring. At the range of [0,crystalOneRing-1]
	cry2:			Get the index of crystal2 on the ring. At the range of [0,crystalOneRing-1]
	}
	Return:				Status.
	**********************************************************/
	void GetCrystalIDInRingFromViewBin(int view, int bin, int & cry1, int & cry2)const;
	//�������������ڵĻ�ring�;�����һ�����ϵľ����cry�õ�LORID
	/**********************************************************
	Description:		Crystal ID to LOR ID.
	Arguments:
	{
	ring1:			The ring1 index. At the range of [0,ringNum-1]
	cry1:			The index of crystal1 on the ring. At the range of [0,crystalOneRing-1]
	ring2:			The ring2 index. At the range of [0,ringNum-1]
	cry2:			The index of crystal2 on the ring. At the range of [0,crystalOneRing-1]
	LORID:			Get the LOR index.
	}
	Return:				Status.
	**********************************************************/
	void GetLORIDFromRingAndCrystalInRing(int ring1, int cry1, int ring2, int cry2, int & LORID)const;
	//�ж��Ƿ�Ϊ���ʷ���20180723
	/**********************************************************
	Description:		Determine if the 2 panel has a large distance.
	Arguments:
	{
	panel1:			The panel1 index.
	panel2:			The panel2 index.
	minSectorDifference:	The minimum difference between the 2 panel.
	}
	Return:				1 when get true. 0 when get false.
	**********************************************************/
	int IsGoodPair(int panel1, int panel2, int minSectorDifference)const;

public://�ṩ��̽�����ṹ���ýӿ�
	void InitD80Scanner();
	void InitD180Scanner();
	void InitE180Scanner();
	void InitTest();
	virtual void Init(){};

	UVolume3D<double>	crystalSize; //��������ʵ�ߴ�(mm)
	UVolume3D<double>	crystalPitch;//��������װ�ߴ�(mm)
	UVolume3D<int>   	crystalNum;  //һ��block�������еľ���������

	UVolume3D<double>	blockSize;   //block��ʵ�ߴ�(mm)�����ԴӾ����������Ϣ�������
	UVolume3D<double>	blockPitch;  //block��װ�ߴ�(mm)
	UVolume3D<int>		blockNum;    //һ��module�������е�block����

	UVolume3D<double>	moduleSize;  //module��ʵ�ߴ�(mm)�����Դ�block�����Ϣ�������
	UVolume3D<double>	modulePitch; //module��װ�ߴ�(mm)
	UVolume3D<int>   	moduleNum;   //һ��panel�������е�module����

	UVolume3D<double>	panelSize;   //panel��ʵ�ߴ�(mm)�����Դ�module�����Ϣ�������
	UVolume3D<double>	panelPitch;  //panel��װ�ߴ�(mm)
	int	   		panelNum;    //̽�⻷�������е�panel����
	int			crystalClockwiseOffset;		//����˳ʱ�뷽��ƫ����
	double 		scannerRadius; //����Ҫ���ڵ�����С����Բ�뾶

private:
	UPETScanner(const UPETScanner&){};
	UPETScanner& operator=(const UPETScanner&){};
};

#endif
