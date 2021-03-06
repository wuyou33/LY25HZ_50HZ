/*=============================================================================*
 *  			Copyright(c) 2010-2011, Convertergy Co., Ltd.
 *                          ALL RIGHTS RESERVED
 *
 *  FILENAME : 5KW_DataAcquisition.h
 *  PURPOSE  : header files 5KW_DataAcquisition.c 
 *			       define constant, struct declaration, extern varibles
 *				 
 *  HISTORY  :
 *    DATE            VERSION        AUTHOR            NOTE
 *    2011-02-24      V0.1           Ken      	    Created    
 ******************************************************************************/

#ifndef DATA_ACQUISITION_H
#define DATA_ACQUISITION_H

#include "IQmathLib.h"
//================= Global constants============================================
// -----------------------------------------------
// --- Grid Frequency Limits Specifications
// -----------------------------------------------
#define Value_2Pi	_IQ20(6.283185307)
#define Value_Pi 	_IQ20(3.141592654)

#define	Rated50HzGirdFrequecy		_IQ20(50)		// Unit, Hz
#define 	MaxGridFrequecy					_IQ20(51) 		//Rated50HzGirdFrequecy + RatedDeviationofGridFreq
#define 	MinGridFrequecy					_IQ20(49) 		//Rated50HzGirdFrequecy - RatedDeviationofGridFreq

// -----------------------------------------------
// define measure gain, the calculated values are ten times of real values
//	except for insulation resistor (1 time) and inductor DCoffset(100 times)
// -----------------------------------------------
#define IGridMeasureGain  		_IQ20(9.137e-3)
#define VGridMeasureGain    	_IQ20(0.124f)
#define VOutMeasureGain		_IQ20(0.124f)
#define TempAmbMeasureGain  _IQ20(0.0732f)
#define CoffStepToFre    _IQ15(3183.098861929)//20000/6.283185307

#define DC_FAN1_FB_Level			GpioDataRegs.GPADAT.bit.GPIO5
#define DC_FAN2_FB_Level			GpioDataRegs.GPADAT.bit.GPIO20

/*=================structure define====================*/
struct	AD_Sample_Reg0 
{
	int32		i32IGrid;
	int32		i32VGrid;
	int32		i32VOut;
	int32		i32TempAmb;
};
struct	AD_Sample_Reg1 
{
	_iq20		iq20IGrid;
	_iq20		iq20VGrid;
	_iq20		iq20VOut;
	_iq20		iq20TempAmb;
};
struct	AD_ACC_Reg1
{
	int16		i16Counter;

	_iq20		iq20IGrid_RMS;
	_iq20		iq20VGrid_RMS;
	_iq20		iq20VGrid_ave;
	_iq20		iq20VOut_ave;
	_iq20		iq20VOut_RMS;
	_iq20		iq20TempAmb;
	_iq20		iq20GridFreq;
};

struct	AD_ACC_Reg2
{
	int16		i16Counter;

	_iq10		iq10IGrid_RMS;
	_iq2		iq2VOut_RMS;
	_iq10		iq10TempAmb;
	_iq2		iq2VGrid_RMS;
	_iq10		iq10GridFreq;
	_iq20		iq20VGrid_ave;
	_iq20		iq20VOut_ave;
};

/*=================structure define====================*/

/*=================global variables declaration====================*/
extern	struct	AD_Sample_Reg1	GetRealValue, ADGain, ADChannelOffset, ADCalibration;
extern	struct	AD_Sample_Reg0	GeneralADbuffer;
extern	struct	AD_ACC_Reg1	 Calc_Result;
extern	struct	AD_ACC_Reg2  AD_Acc, AD_Sum; 
extern	_iq20	i32SumCounterBypass;

/*=================global function declaration====================*/
extern void Get_ADC_Result(void);// functions called in ADC.c
extern void ADAccCalc(void);
extern void DcFanSpeedSense(void);
extern void DitherEliminate(void);

#endif


//--- end of file -----------------------------------------------------


