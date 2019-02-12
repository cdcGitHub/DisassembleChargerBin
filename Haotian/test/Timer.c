/*
*******************************************************************************
**
**  This device driver was created by Applilet2 for 78K0/Kx2
**  8-Bit Single-Chip Microcontrollers
**
**  Copyright(C) NEC Electronics Corporation 2002 - 2018
**  All rights reserved by NEC Electronics Corporation.
**
**  This program should be used on your own responsibility.
**  NEC Electronics Corporation assumes no responsibility for any losses
**  incurred by customers or third parties arising from the use of this file.
**
**  Filename :	Timer.c
**  Abstract :	This file implements device driver for Timer module.
**  APIlib :	Applilet2 for 78K0/Kx2 V2.42 [12 Jun 2009]
**
**  Device :	uPD78F0500_30
**
**  Compiler :	CC78K0
**
**  Creation date:	2018/12/8
**  
*******************************************************************************
*/

/*
*******************************************************************************
**  Include files
*******************************************************************************
*/
#include "macrodriver.h"
#include "Timer.h"
/* Start user code for include definition. Do not edit comment generated here */
/* End user code for include definition. Do not edit comment generated here */
#include "user_define.h"

/*
*******************************************************************************
**  Global define
*******************************************************************************
*/
/* Start user code for global definition. Do not edit comment generated here */
/* End user code for global definition. Do not edit comment generated here */


/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function initializes TM00.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void TM00_Init( void )
{
	TMC00 = TM0_OPERATE_DISABLE;
	TMMK000 = 1;			/* INTTM000 disabled */
	TMIF000 = 0;			/* INTTM000 interrupt flag clear */
	TMMK010 = 1;			/* INTTM010 disabled */
	TMIF010 = 0;			/* INTTM010 interrupt flag clear */
	TMPR000 = 1;			/* set INTTM000 low priority */
	PRM00 = TM0_PRM0_INITIALVALUE | TM0_INTER_CLOCK_2;
	/* TM00 interval */
	CRC00 = TM0_CRC0_INITIALVALUE | TM0_CR00_COMPARE;
	TOC00 = TM0_TOC0_INITIALVALUE;
	CR000 = TM00_CR000_VALUE;
	CR010 = TM00_CR010_VALUE;
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function starts TM00 counter.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void TM00_Start( void )
{
	TMMK000 = 0;			/* INTTM000 enabled */
	TMC00 &= (UCHAR)~TM0_OPERATE;
	TMC00 |= TM0_CLEAR_BY_MATCH_CR00;
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function stops TM00 counter.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void TM00_Stop( void )
{
	TMC00 = TM0_OPERATE_DISABLE;
	TMMK000 = 1;			/* INTTM000 disabled */
	TMIF000 = 0;			/* INTTM000 interrupt flag clear */
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function changes TM00 interval value.
**
**	Parameters:
**		*array_reg :	array_reg values in the compare registers
**		array_num :	value number
**
**	Returns:
**		MD_OK
**		MD_ERROR
**
**-----------------------------------------------------------------------------
*/
MD_STATUS TM00_ChangeTimerCondition( USHORT* array_reg, USHORT array_num )
{
	switch (array_num){
		case 1:
			CR000 = array_reg[0];
			break;
		case 2:
			CR000 = array_reg[0];
			CR010 = array_reg[1];
			break;
		default:
			return MD_ERROR;
	}
	
	return MD_OK;
}

/* Start adding user code. Do not edit comment generated here */
/* End user code adding. Do not edit comment generated here */


