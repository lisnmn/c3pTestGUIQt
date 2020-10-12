#ifndef LIBOSEM_H
#define LIBOSEM_H

#include "libOSEM_global.h"

#ifdef _WIN32//define something for Windows (32-bit and 64-bit, this part is common)
#include <Windows.h>
#elif __linux__//linux
#include <unistd.h>
#define Sleep(x) sleep(x)
#endif
#include "UPETScanner.h"
#include "UReconPETOSEMAlgor.h"
#include "UProgressNotify.h"
#include "UVolume.h"
#include "UImage.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <time.h>
#include <math.h>

using namespace std;

/*
int imgWidth, int imgHeight, int imgDepth,
float voxelSizeXY, float voxelSizeZ,
int iterNum, int subsetNum, int ringDifference,
float timeBeforeScan, float timeDuringScan, float sourceHalfLife, float sourceBranchingRatio, float wellCounterSlope, float wellCounterIntercept,
std::string strMichPath, std::string strSenMapPath,
std::string strNormFactorPath, std::string strAttnFactorPath, std::string strRandEstimatePath,
std::string strSavePath,
bool calcSenMap, bool randomCorr, bool attnCorr, bool scatterCorr, bool normCorr, bool wellCounterCorr, bool decayCorr, bool deadTimeCorr
*/

class LIBOSEM_EXPORT LibOSEM
{
public:
    LibOSEM();
    void static printNotify(UProgressNotify *pNotify);
    void OSEM(UReconPETOSEMPara *para, UProgressNotify *notify);
    
};

#endif // LIBOSEM_H
