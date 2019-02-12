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
**  Filename :	System.h
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
#ifndef _MDSYSTEM_
#define _MDSYSTEM_
/*
*******************************************************************************
**	Register bit define
*******************************************************************************
*/
/*
	Clock Operation Mode Select Register (OSCCTL)
*/
/* High-speed system clock pin operation mode (EXCLK, OSCSEL) */
#define	CG_HISYSTEM_EXTCLK		0x80	/* external clock bit */
#define	CG_HISYSTEM_OSCSEL		0x40	/* clock/port bit */
#define	CG_HISYSTEM_PIN			0xc0
#define	CG_HISYSTEM_PORT		0x00	/* X1, X2 as I/O port */
#define	CG_HISYSTEM_OSC			0x40	/* X1, X2 as crystal/ceramic resonator connection */
#define	CG_HISYSTEM_PORT1		0x80	/* X1, X2 as I/O port */
#define	CG_HISYSTEM_EXT			0xc0	/* X1 as External clock input, X2 as I/O port */
/* Subsystem clock pin operation mode (EXCLKS, OSCSELS) */
/** Note: valid when PCC.6 = 0 **/
#define	CG_SUBCLOCK_OSCSELS		0x10	/* sub clock/port bit */
#define	CG_SUBCLOCK				0x30
#define	CG_SUBCLOCK_PORT		0x00	/* XT1, XT2 as I/O port	*/
#define	CG_SUBCLOCK_OSC			0x10	/* XT1, XT2 as crystal resonator connection	*/
#define	CG_SUBCLOCK_PORT1		0x20	/* XT1, XT2 as I/O port mode */
#define	CG_SUBCLOCK_EXT			0x30	/* XT1 as External clock input, X2 as I/O port */
/* Operating frequency control (AMPH) */
#define	CG_OPERATING_FREQ		0x01
#define	CG_OPERATING_UNDER10M	0x00	/* 1 MHz <=fxh <= 10 MHz */
#define	CG_OPERATING_OVER10M	0x01	/* 10 MHz < fxh <= 20 MHz */

/*
	Processor Clock Control Register (PCC)
*/
/* System clock status *read only (CLS) */
#define	CG_CPUCLOCK_STATUS		0x20
#define	CG_CPUCLOCK_MAINSTATUS	0x00	/* main system clock status */
#define	CG_CPUCLOCK_SUBSTATUS	0x20	/* sub system clock status */
/* CPU clock (fcpu) selection source (CSS) */
#define	CG_CPUCLOCK_SOURCE		0x10
#define	CG_CPUCLOCK_MAIN		0x00	/* main system clock */
#define	CG_CPUCLOCK_SUB			0x10	/* sub system clock */
/* CPU clock (fcpu) selection (PCC0, PCC1, PCC2) */
/** Note: valid when PCC.CSS = 0 **/
#define	CG_CPUCLOCK				0x07
#define	CG_CPUCLOCK_FXP			0x00	/* fcpu = fxp */
#define	CG_CPUCLOCK_FXP2		0x01	/* fcpu = fxp/2 (default) */
#define	CG_CPUCLOCK_FXP4		0x02	/* fcpu = fxp/4 */
#define	CG_CPUCLOCK_FXP8		0x03	/* fcpu = fxp/8 */
#define	CG_CPUCLOCK_FXP16		0x04	/* fcpu = fxp/16 */

/*
	Internal Oscillation Mode Register (RCM)
*/
/* Status of internal high-speed oscillator *read only (RSTS) */
#define	CG_HIGHINTERNAL_STATUS	0x80
#define	CG_HIGHINTERNAL_WAIT	0x00	/* wait for ready */
#define	CG_HIGHINTERNAL_READY	0x80	/* ready for operation */
/* Internal low-speed oscillator oscillating/stopped (LSRSTOP) */
#define	CG_LOWINTERNAL			0x02
#define	CG_LOWINTERNAL_RUN		0x00	/* internal low-speed oscillator oscillating */
#define	CG_LOWINTERNAL_STOP		0x02	/* internal low-speed oscillator stopped */
/* Internal high-speed oscillator oscillating/stopped (RSTOP) */
#define	CG_HIGHINTERNAL			0x01
#define	CG_HIGHINTERNAL_RUN		0x00	/* internal high-speed oscillator oscillating */
#define	CG_HIGHINTERNAL_STOP	0x01	/* internal high-speed oscillator stopped */

/*
	Main OSC control register (MOC)
*/
/* Control of high-speed system clock operation (MSTOP) */
#define	CG_HISYSTEM				0x80
#define	CG_HISYSTEM_RUN			0x00	/* X1 oscillator/external clock enable */
#define	CG_HISYSTEM_STOP		0x80	/* X1 oscillator/external clock disable	*/

/*
	Main Clock Mode Register (MCM)
*/
/* Selection of clock supplied to main system clock and peripheral hardware (XSEL, MCM0) */
#define	CG_MAINPERI_CLOCK		0x05
#define	CG_MAINPERI_INTER		0x00	/* fxp = frh,fprs = frh */
#define	CG_MAINPERI_INTER1		0x01	/* fxp = frh,fprs = frh */
#define	CG_MAINPERI_INTER_SYS	0x04	/* fxp = frh,fprs = fxh */
#define	CG_MAINPERI_SYS		0x05	/* fxp = fxh,fprs = fxh */
/* Main system clock status *read only (MCS) */
#define	CG_MAINSYSTEM_STATUS	0x02
#define	CG_MAINSYSTEM_INTER		0x00	/* Operates with internal high-speed oscillation clock */
#define	CG_MAINSYSTEM_SYS		0x02	/* Operates with high-speed system clock */

/*
	Oscillation Stabilization Time Counter Status Register (OSTC)
*/
/* Oscillation stabilization time status ( MOST11-16) */
#define	CG_OSCSTAB_STATUS		0x1f
#define	CG_OSCSTAB_STATUS11		0x10	/* 2^11/fx */
#define	CG_OSCSTAB_STATUS13		0x18	/* 2^13/fx */
#define	CG_OSCSTAB_STATUS14		0x1c	/* 2^14/fx */
#define	CG_OSCSTAB_STATUS15		0x1e	/* 2^15/fx */
#define	CG_OSCSTAB_STATUS16		0x1f	/* 2^16/fx */

/*
	Oscillation Stabilization Time Select Register (OSTS)
*/
/* Oscillation stabilization time selection (OSTS2-0) */
#define	CG_OSCSTAB_SELECT		0x07
#define	CG_OSCSTAB_SELECT11		0x01	/* 2^11/fx */
#define	CG_OSCSTAB_SELECT13		0x02	/* 2^13/fx */
#define	CG_OSCSTAB_SELECT14		0x03	/* 2^14/fx */
#define	CG_OSCSTAB_SELECT15		0x04	/* 2^15/fx */
#define	CG_OSCSTAB_SELECT16		0x05	/* 2^16/fx */

/*
*******************************************************************************
**  Macro define
*******************************************************************************
*/
#define CG_FRHWAITTIME 40
enum ClockMode { HIOCLK, SYSX1CLK, SYSEXTCLK, HIOSYSCLK };
enum CPUClock { SYSTEMCLOCK, SYSONEHALF, SYSONEFOURTH, SYSONEEIGHTH, SYSONESIXTEENTH };
enum PSLevel { PSSTOP, PSHALT };
enum StabTime { STLEVEL0, STLEVEL1, STLEVEL2, STLEVEL3,	STLEVEL4 };

/*
*******************************************************************************
**  Function define
*******************************************************************************
*/
void Clock_Init( void );
void CG_ReadResetSource( void );
/* Start user code for definition. Do not edit comment generated here */
/* End user code for definition. Do not edit comment generated here */
#endif
