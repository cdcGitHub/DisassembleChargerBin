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
**  Filename :	Port.h
**  Abstract :	This file implements device driver for PORT module.
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
#ifndef _MDPORT_
#define _MDPORT_
/*
*******************************************************************************
**	Register bit define
*******************************************************************************
*/
/* Port mode register(PMn.0 to 7) */
#define PMn0_NOT_USE		0x01	/* not use Pn0 as digital I/O */
#define PMn1_NOT_USE		0x02	/* not use Pn1 as digital I/O */
#define PMn2_NOT_USE		0x04	/* not use Pn2 as digital I/O */
#define PMn3_NOT_USE		0x08	/* not use Pn3 as digital I/O */
#define PMn4_NOT_USE		0x10	/* not use Pn4 as digital I/O */
#define PMn5_NOT_USE		0x20	/* not use Pn5 as digital I/O */
#define PMn6_NOT_USE		0x40	/* not use Pn6 as digital I/O */
#define PMn7_NOT_USE		0x80	/* not use Pn7 as digital I/O */
#define PMn0_MODE_INPUT		0x01	/* Pn0 as input mode */
#define PMn0_MODE_OUTPUT	0x00	/* Pn0 as output mode */
#define PMn1_MODE_INPUT		0x02	/* Pn1 as input mode */
#define PMn1_MODE_OUTPUT	0x00	/* Pn1 as output mode */
#define PMn2_MODE_INPUT		0x04	/* Pn2 as input mode */
#define PMn2_MODE_OUTPUT	0x00	/* Pn2 as output mode */
#define PMn3_MODE_INPUT		0x08	/* Pn3 as input mode */
#define PMn3_MODE_OUTPUT	0x00	/* Pn3 as output mode */
#define PMn4_MODE_INPUT		0x10	/* Pn4 as input mode */
#define PMn4_MODE_OUTPUT	0x00	/* Pn4 as output mode */
#define PMn5_MODE_INPUT		0x20	/* Pn5 as input mode */
#define PMn5_MODE_OUTPUT	0x00	/* Pn5 as output mode */
#define PMn6_MODE_INPUT		0x40	/* Pn6 as input mode */
#define PMn6_MODE_OUTPUT	0x00	/* Pn6 as output mode */
#define PMn7_MODE_INPUT		0x80	/* Pn7 as input mode */
#define PMn7_MODE_OUTPUT	0x00	/* Pn7 as output mode */
#define PMn0_CHANGE_OUTPUT	0xFE	/* Change Pn0 to output mode */
#define PMn1_CHANGE_OUTPUT	0xFD	/* Change Pn1 to output mode */
#define PMn2_CHANGE_OUTPUT	0xFB	/* Change Pn2 to output mode */
#define PMn3_CHANGE_OUTPUT	0xF7	/* Change Pn3 to output mode */
#define PMn4_CHANGE_OUTPUT	0xEF	/* Change Pn4 to output mode */
#define PMn5_CHANGE_OUTPUT	0xDF	/* Change Pn5 to output mode */
#define PMn6_CHANGE_OUTPUT	0xBF	/* Change Pn6 to output mode */
#define PMn7_CHANGE_OUTPUT	0x7F	/* Change Pn7 to output mode */

/* ADPC define */
#define PORT_ADPC_0DIO		0
#define PORT_ADPC_1DIO		1
#define PORT_ADPC_2DIO		2
#define PORT_ADPC_3DIO		3
#define PORT_ADPC_4DIO		4/* Port register(Pn.0 to 7) */
#define Pn0_OUTPUT_0		0x00	/* Pn0 output 0 */
#define Pn0_OUTPUT_1		0x01	/* Pn0 output 1 */
#define Pn1_OUTPUT_0		0x00	/* Pn1 output 0 */
#define Pn1_OUTPUT_1		0x02	/* Pn1 output 1 */
#define Pn2_OUTPUT_0		0x00	/* Pn2 output 0 */
#define Pn2_OUTPUT_1		0x04	/* Pn2 output 1 */
#define Pn3_OUTPUT_0		0x00	/* Pn3 output 0 */
#define Pn3_OUTPUT_1		0x08	/* Pn3 output 1 */
#define Pn4_OUTPUT_0		0x00	/* Pn4 output 0 */
#define Pn4_OUTPUT_1		0x10	/* Pn4 output 1 */
#define Pn5_OUTPUT_0		0x00	/* Pn5 output 0 */
#define Pn5_OUTPUT_1		0x20	/* Pn5 output 1 */
#define Pn6_OUTPUT_0		0x00	/* Pn6 output 0 */
#define Pn6_OUTPUT_1		0x40	/* Pn6 output 1 */
#define Pn7_OUTPUT_0		0x00	/* Pn7 output 0 */
#define Pn7_OUTPUT_1		0x80	/* Pn7 output 1 */
/* Pull-up resistor option register(PUn.0 to 7) */
#define PUn0_PULLUP_OFF		0x00	/* Pn0 Pull-up not connected */
#define PUn0_PULLUP_ON		0x01	/* Pn0 pull-up connected */
#define PUn1_PULLUP_OFF		0x00	/* Pn1 Pull-up not connected */
#define PUn1_PULLUP_ON		0x02	/* Pn1 pull-up connected */
#define PUn2_PULLUP_OFF		0x00	/* Pn2 Pull-up not connected */
#define PUn2_PULLUP_ON		0x04	/* Pn2 pull-up connected */
#define PUn3_PULLUP_OFF		0x00	/* Pn3 Pull-up not connected */
#define PUn3_PULLUP_ON		0x08	/* Pn3 pull-up connected */
#define PUn4_PULLUP_OFF		0x00	/* Pn4 Pull-up not connected */
#define PUn4_PULLUP_ON		0x10	/* Pn4 pull-up connected */
#define PUn5_PULLUP_OFF		0x00	/* Pn5 Pull-up not connected */
#define PUn5_PULLUP_ON		0x20	/* Pn5 pull-up connected */
#define PUn6_PULLUP_OFF		0x00	/* Pn6 Pull-up not connected */
#define PUn6_PULLUP_ON		0x40	/* Pn6 pull-up connected */
#define PUn7_PULLUP_OFF		0x00	/* Pn7 Pull-up not connected */
#define PUn7_PULLUP_ON		0x80	/* Pn7 pull-up connected */
#define	PM0_DEFAULT			0xFC	/* PM0 default value */
#define	PM2_DEFAULT			0xF0	/* PM2 default value */
#define	PM3_DEFAULT			0xF0	/* PM3 default value */
#define	PM6_DEFAULT			0xFC	/* PM6 default value */
#define	PM12_DEFAULT		0xF8	/* PM12 default value */

/*
*******************************************************************************
**  Macro define
*******************************************************************************
*/

/*
*******************************************************************************
**  Function define
*******************************************************************************
*/
void PORT_Init ( void );

/* Start user code for definition. Do not edit comment generated here */
/* End user code for definition. Do not edit comment generated here */
#endif
