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
**  Filename :	System.c
**  Abstract :	This file implements device driver for System module.
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
#include "System.h"
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
**		This function initializes the clock generator.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void Clock_Init( void )
{
	/* Set fxh */
	OSCCTL = CG_HISYSTEM_PORT;
	MSTOP = 1;
	/* Set frh */
	RSTOP = 0;
	/* Set fprs */
	MCM = CG_MAINPERI_INTER;
	/* Set fcpu */
	PCC &= (UCHAR)~(CG_CPUCLOCK | CG_CPUCLOCK_SOURCE);
	PCC |= CG_CPUCLOCK_FXP2;
	/* Set frl */
	LSRSTOP = 0;
}

/* Start adding user code. Do not edit comment generated here */
/* End user code adding. Do not edit comment generated here */


