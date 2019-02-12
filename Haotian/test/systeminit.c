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
**  Filename :	systeminit.c
**  Abstract :	This file implements system initializing function.
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
#include "Port.h"
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
**		This function  initializes every macro.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void SystemInit( void )
{
	/*Process of reset*/
	CG_ReadResetSource();
	/*Initialize the clock generator*/
	Clock_Init();
	/*Initialize the I/O ports*/
	PORT_Init();
	/*Initialize TM00 function*/
	TM00_Init();
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function  initializes hardware setting.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void hdwinit( void )
{
	DI( );
	IMS = MEMORY_IMS_SET;
	SystemInit( );
	EI( );
}

/* Start adding user code. Do not edit comment generated here */
/* End user code adding. Do not edit comment generated here */


