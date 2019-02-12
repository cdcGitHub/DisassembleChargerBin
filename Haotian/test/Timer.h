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
**  Filename :	Timer.h
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
#ifndef _MDTIMER_
#define _MDTIMER_
/*
*******************************************************************************
**	Register bit define
*******************************************************************************
*/
/*
	TM0n Mode Control Register(TMC0n)
*/
/* Initial Value */
#define TM0_TMC0_INITIALVALUE		0x00
/* Operating mode and clear mode selection(TMC0n.TMC0n3 & TMC0n.TMC0n2) */
#define TM0_OPERATE					0x0C	/* for clear the bits */
#define TM0_OPERATE_DISABLE			0x00	/* operation stop(TM0n cleared to 0) */
#define TM0_OPERATE_FREERUNNING		0x04	/* free-running mode */
#define TM0_CLEAR_BY_TI00_EDGE		0x08	/* clear & start occurs on TI00n pin valid edge */
#define TM0_CLEAR_BY_MATCH_CR00		0x0C	/* clear & start occurs on match between TM0n and CR00n */
/* Condition to reverse timer output (TO0n) TMC0n.TMC0n1 */
#define TM0_TO0n_MATCH_CR0n			0x00	/* match between TM0n and CR00n or match between TM0n and CR01n */
#define TM0_TO0n_MATCH_CR0n_TI00	0x02	/* match between TM0n and CR00n or match between TM0n and CR01n or trigger input of TI00n pin valid edge */
/* TM0n overflow detection(TMC0n.OVF0n) */
#define TM0_OVERFLOW_FLAG			0x01	/* overflow detected */

/*
	Capture/Compare Control Register(CRC0n)
*/
/* Initial Value */
#define TM0_CRC0_INITIALVALUE		0x00
/* CR00n operating mode selection(CRC0n.CRC0n0) */
#define TM0_CR00_MODE				0x01
#define TM0_CR00_COMPARE			0x00	/* operates as compare register */
#define TM0_CR00_CAPTURE			0x01	/* operates as capture register */
/* CR01n operating mode selection(CRC0n.CRC0n2) */
#define TM0_CR01_MODE				0x04
#define TM0_CR01_COMPARE			0x00	/* operates as compare register */
#define TM0_CR01_CAPTURE			0x04	/* operates as capture register */
/* CR00n capture trigger selection(CRC0n.CRC0n1) */
#define TM0_CR00_CAPTURE_MODE		0x02
#define TM0_CR00_CAPTURE_TI01		0x00	/* captures on valid edge of TI01n pin */
#define TM0_CR00_CAPTURE_TI00		0x02	/* captures on valid edge of TI00n pin by reverse phase */

/*
	Prescaler Mode Register(PRM0n)
*/
/* Initial Value */
#define TM0_PRM0_INITIALVALUE		0x00
/* Count clock selection(PRM0n.PRM0n1 & PRM0n.PRM0n0) */
#define TM0_COUNT_CLOCK				0x03	/* for clear the bits */
#define TM0_INTER_CLOCK_1			0x00	/* fprs */
#define TM0_INTER_CLOCK_2			0x01	/* fprs/2^2 */
#define TM0_INTER_CLOCK_3			0x02	/* fprs/2^8  */
#define TM0_EXTER_CLOCK				0x03	/* TI00n valid edge */
/* TI00n pin valid edge selection(PRM0n.ES0n1 & PRM0n.ES0n0) */
#define TM0_TI00_VALID_EDGE			0x30	/* for clear the bits */
#define TM0_TI00_VALID_EDGE_FALL	0x00	/* falling edge */
#define TM0_TI00_VALID_EDGE_RISE	0x10	/* rising edge */
#define TM0_TI00_VALID_EDGE_BOTH	0x30	/* both falling and rising edges */
/* TI01n pin valid edge selection(PRM0n.ES1n1 & PRM0n.ES1n0) */
#define TM0_TI01_VALID_EDGE			0xC0	/* for clear the bits */
#define TM0_TI01_VALID_EDGE_FALL	0x00	/* falling edge */
#define TM0_TI01_VALID_EDGE_RISE	0x40	/* rising edge */
#define TM0_TI01_VALID_EDGE_BOTH	0xC0	/* both falling and rising edges */

/*
	Timer Output Control Register(TOC0n)
*/
/* Initial Value */
#define TM0_TOC0_INITIALVALUE		0x00
/* Timer output F/F status setting(TOC0n.LVSn1 & TOC0n.LVRn1) */
#define TM0_OUTPUT_INIT_LEVEL_CLR	0x0C	/* for clear the bits */
#define TM0_OUTPUT_INIT_LEVEL_LOW	0x04	/* timer output F/F reset (0) */
#define TM0_OUTPUT_INIT_LEVEL_HIGH	0x08	/* timer output F/F set (1) */
/* Timer output F/F control using match of CR00n and TM0n(TOC0n.TOC0n1) */
#define TM0_CR00_OUTPUT_FF_OFF_MODE	0x00	/* disables inversion operation */
#define TM0_CR00_OUTPUT_FF_ON_MODE	0x02	/* enables inversion operation */
/* Timer output F/F control using match of CR01n and TM0n(TOC0n.TOC0n4) */
#define TM0_CR01_OUTPUT_FF_OFF_MODE	0x00	/* disables inversion operation */
#define TM0_CR01_OUTPUT_FF_ON_MODE	0x10	/* enables inversion operation */
/* One-shot pulse output trigger control via software(TOC0n.OSPT0n) */
#define TM0_SOFTWARE_TRIGGER_OFF	0x00	/* no one-shot pulse output trigger */
#define TM0_SOFTWARE_TRIGGER_ON		0x40	/* one-shot pulse output trigger */
/* One-shot pulse output operation control(TOC0#n.OSPE0n) */
#define TM0_SUCCESSIVE_MODE			0x00	/* successive pulse output mode */
#define TM0_ONESHOT_MODE			0x20	/* one-shot pulse output mode */
/* Timer output control(TOC0n.TOE0n) */
#define TM0_OUTPUT_DISABLE_BIT		0x00	/* disables output (output fixed to level 0) */
#define TM0_OUTPUT_ENABLE_BIT		0x01	/* enables output */
/*
	Timer Clock Selection Register 5n (TCL5n)
*/
/* TM5 internal clock selection(TCL5n) */
#define	TM5_INTER_CLOCK_1			0x02	/* internal clock = fpsr */
#define	TM5_INTER_CLOCK_2			0x03	/* internal clock = fpsr/2 */
#define	TM5_INTER_CLOCK_3			0x04	/* when n=0, internal clock = fpsr/2^2;	when n=1, internal clock = fpsr/2^4	*/
#define	TM5_INTER_CLOCK_4			0x05	/* internal clock = fpsr/2^6 */
#define	TM5_INTER_CLOCK_5			0x06	/* interna clock = fpsr/2^8 */
#define	TM5_INTER_CLOCK_6			0x07	/* when n=0, internal clock = fpsr/2^13; when n=1, internal clock = fpsr/2^12 */
/* TM5 external clock selection(TCL5n) */
#define	TM5_EXTER_CLOCK_FALLING		0x00	/* TI5n pin falling edge */
#define	TM5_EXTER_CLOCK_RISING		0x01	/* TI5n pin rising edge */
/* TM5 count edge selection(in external	event counter)(TCL5n) */
#define	TM5_COUNT_EDGE_FALLING		0x00	/* TI5n pin falling edge */
#define	TM5_COUNT_EDGE_RISING		0x01	/* TI5n pin rising edge */

/*
	Timer Mode Control Register 5n (TMC5n)
*/
#define TM5_TMC5_INITIALVALUE		0x00
/* TM5 operating mode selection	(TMC5n.TMC5n6)*/
#define	TM5_OPT_MODE_OTHER			0x00	/* mode in which clear & start occurs on a match between TM5n and CR5n */
#define	TM5_OPT_MODE_PWM			0x40	/* PWM (free-running) mode */
/* TM5 F/F control (in other than PWM mode)(TMC5n.TMC5n1)*/
#define	TM5_OUTPUT_FF_ENABLE		0x02	/* inversion operation enabled */
#define	TM5_OUTPUT_FF_DISABLE		0x00	/* inversion operation disabled */
/* TM5 active level selection (in PWM mode)(TMC5n.TMC5n1) */
#define	TM5_OUTPUT_ACTIVE_HIGH		0x00	/* active-high */
#define	TM5_OUTPUT_ACTIVE_LOW		0x02	/* active-low */
/* TM5 output F/F status setting (in other than PWM mode) (TMC5n.LVS5n & TMC5n.LVR5n) */
#define	TM5_OUTPUT_INIT_CLR			0x0C	/* for clear bits */
#define	TM5_OUTPUT_INIT_HIGH		0x08	/* TM5 output F/F set (1) */
#define	TM5_OUTPUT_INIT_LOW			0x04	/* TM5 output F/F clear	(0)	*/
/* TM5 output control (TMC5n.TOE5n)	*/
#define	TM5_OUTPUT_ENABLE_BIT		0x01	/* output enabled */
#define	TM5_OUTPUT_DISABLE_BIT		0x00	/* output disabled (TM5n output is low level) */
/* TM5 count operation control (TMC5n.TCE5n) */
#define	TM5_COUNTER_ENABLE_BIT		0x80	/* count operation start */
#define	TM5_COUNTER_DISABLE_BIT		0x00	/* after clearing to 0, count operation disabled (counter stopped) */
/*
 8-bit timer H mode register n (TMHMDn)
*/
#define TMH_TMHMDn_INITIALVALUE		0x00  /* TMHMDn initial value */
/* Count clock selection(TMHMDn.CKSn2~CKSn0) */
#define TMH_INTER_CLOCK_1			0x00  /* TMH0: fPRS, TMH1: fPRS */
#define TMH_INTER_CLOCK_2			0x10  /* TMH0: fPRS/2, TMH1: fPRS/2^2 */
#define TMH_INTER_CLOCK_3			0x20  /* TMH0: fPRS/2^2, TMH1: fPRS/2^4 */
#define TMH_INTER_CLOCK_4			0x30  /* TMH0: fPRS/2^6, TMH1: fPRS/2^6 */
#define TMH_INTER_CLOCK_5			0x40  /* TMH0: fPRS/2^10, TMH1: fPRS/2^12 */
#define TMH_INTER_CLOCK_6			0x50  /* TMH0: TM50 output, TMH1: fRL/2^7 */
#define TMH_INTER_CLOCK_7			0x60  /* TMH1: fRL/2^9 */
#define TMH_INTER_CLOCK_8			0x70  /* TMH1: fRL */
/* Timer operation mode(TMHMD#n.TMMDn1~TMMDn0) */
#define TMH_INTERVAL_SQUARE_MODE	0x00  /* interval/square-wave timer mode */
#define TMH_PWM_MODE				0x08  /* PWM output mode */
#define TMH1_CARRIER_MODE			0x04  /* Carrier generator mode */
/* Timer output level control (in default mode)(TMHMD#n.TOLEVn) */
#define TMH_OUTPUT_LVL_LOW			0x00  /* low level */
#define TMH_OUTPUT_LVL_HIGH			0x02  /* high level */

/*
 8-bit timer H carrier control register 1 (TMCYC1)
*/
/* Remote control output in carrier mode(TMCYC1.RMC1 & NRZB1) */
#define TMH_REMOTE_LOW_LEVEL		0x00  /* low-level output */
#define TMH_REMOTE_HIGH_LEVEL		0x02  /* high-level output */
#define TMH_REMOTE_CARRIER			0x06  /* carrier pulse output */
/* Carrier pulse output status flag(TMCYC1.NRZ1) */
#define TMH1_CARRIER_OUTPUT_DISABLE	0x00   /* Carrier output disabled status (low-level status) */

/*
*******************************************************************************
**  Macro define
*******************************************************************************
*/
/* 16-bit timer compare register 000 (CR000)*/
#define TM00_CR000_VALUE	0x9c3f
/* 16-bit timer compare register 010 (CR010)*/
#define TM00_CR010_VALUE	0xFFFF
enum TMChannel { TMCHANNEL0, TMCHANNEL1 };

/*
*******************************************************************************
**  Function define
*******************************************************************************
*/
void TM00_Init( void );
void TM00_Start( void );
void TM00_Stop( void );
MD_STATUS TM00_ChangeTimerCondition( USHORT* array_reg, USHORT array_num );
__interrupt void MD_INTTM000( void );
/* Start user code for definition. Do not edit comment generated here */
/* End user code for definition. Do not edit comment generated here */
#endif
