 /*********************************************************************
 *
 *	Hardware specific definitions for:
 *    - Explorer 16
 *    - PIC24F, PIC24H, dsPIC33F
 *    - Fast 100Mbps Ethernet PICtail Plus (ENC624J600)
 *
 *********************************************************************
 * FileName:        HardwareProfile.h
 * Dependencies:    Compiler.h
 * Processor:       PIC24F, PIC24H, dsPIC30F, dsPIC33F
 * Compiler:        Microchip C30 v3.24 or higher
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright (C) 2002-2010 Microchip Technology Inc.  All rights
 * reserved.
 *
 * Microchip licenses to you the right to use, modify, copy, and
 * distribute:
 * (i)  the Software when embedded on a Microchip microcontroller or
 *      digital signal controller product ("Device") which is
 *      integrated into Licensee's product; or
 * (ii) ONLY the Software driver source files ENC28J60.c, ENC28J60.h,
 *		ENCX24J600.c and ENCX24J600.h ported to a non-Microchip device
 *		used in conjunction with a Microchip ethernet controller for
 *		the sole purpose of interfacing with the ethernet controller.
 *
 * You should refer to the license agreement accompanying this
 * Software for additional information regarding your rights and
 * obligations.
 *
 * THE SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT
 * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 * LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * MICROCHIP BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF
 * PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
 * BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE
 * THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER
 * SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF CONTRACT, TORT
 * (INCLUDING NEGLIGENCE), BREACH OF WARRANTY, OR OTHERWISE.
 *
 *
 * Author               Date		Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Howard Schlunder		09/16/2010	Regenerated for specific boards
 ********************************************************************/
#ifndef HARDWARE_PROFILE_H
#define HARDWARE_PROFILE_H

#include <xc.h>

// Define a macro describing this hardware set up (used in other files)
#define ETM_ENCX24J600

// Clock frequency values
#define MAXIMUM_PIC_FREQ		(40000000ul)

// These directly influence timed events using the Tick module.  They also are used for UART and SPI baud rate generation.
#define GetSystemClock()		(MAXIMUM_PIC_FREQ)	// Hz
#define GetInstructionClock()	        (GetSystemClock()/4)	// Normally GetSystemClock()/4 for PIC18, GetSystemClock()/2 for PIC24/dsPIC, and GetSystemClock()/1 for PIC32.  Might need changing if using Doze modes.
#define GetPeripheralClock()	        (GetSystemClock()/4)	// Normally GetSystemClock()/4 for PIC18, GetSystemClock()/2 for PIC24/dsPIC, and GetSystemClock()/1 for PIC32.  Divisor may be different if using a PIC32 since it's configurable.

// Hardware I/O pin mappings

//// ENC28J60 I/O pins
//#if defined(__PIC24FJ256GA110__) || defined(__dsPIC33E__)|| defined(__PIC24E__)	// PIC24FJ256GA110 must place the ENC28J60 on SPI2 because PIC rev A3 SCK1 output pin is a PPS input only (fixed on A5, but demos use SPI2 for simplicity)
//	#define ENC_CS_TRIS			(TRISFbits.TRISF12)	// Comment this line out if you are using the ENC424J600/624J600, MRF24WB0M, or other network controller.
//	#define ENC_CS_IO			(LATFbits.LATF12)
//	// SPI SCK, SDI, SDO pins are automatically controlled by the 
//	// PIC24/dsPIC SPI module 
//	#define ENC_SPI_IF			(IFS2bits.SPI2IF)
//	#define ENC_SSPBUF			(SPI2BUF)
//	#define ENC_SPISTAT			(SPI2STAT)
//	#define ENC_SPISTATbits		(SPI2STATbits)
//	#define ENC_SPICON1			(SPI2CON1)
//	#define ENC_SPICON1bits		(SPI2CON1bits)
//	#define ENC_SPICON2			(SPI2CON2)
//#else	// SPI1 for all other processors
//	#define ENC_CS_TRIS			(TRISDbits.TRISD14)	// Comment this line out if you are using the ENC424J600/624J600, MRF24WB0M, or other network controller.
//	#define ENC_CS_IO			(LATDbits.LATD14)
//	// SPI SCK, SDI, SDO pins are automatically controlled by the 
//	// PIC24/dsPIC SPI module 
//	#define ENC_SPI_IF			(IFS0bits.SPI1IF)
//	#define ENC_SSPBUF			(SPI1BUF)
//	#define ENC_SPISTAT			(SPI1STAT)
//	#define ENC_SPISTATbits		(SPI1STATbits)
//	#define ENC_SPICON1			(SPI1CON1)
//	#define ENC_SPICON1bits		(SPI1CON1bits)
//	#define ENC_SPICON2			(SPI1CON2)
//#endif


// ENC624J600 Interface Configuration
// Comment out ENC100_INTERFACE_MODE if you don't have an ENC624J600 or 
// ENC424J600.  Otherwise, choose the correct setting for the interface you 
// are using.  Legal values are:
//  - Commented out: No ENC424J600/624J600 present or used.  All other 
//                   ENC100_* macros are ignored.
//	- 0: SPI mode using CS, SCK, SI, and SO pins
//  - 1: 8-bit demultiplexed PSP Mode 1 with RD and WR pins
//  - 2: *8-bit demultiplexed PSP Mode 2 with R/Wbar and EN pins
//  - 3: *16-bit demultiplexed PSP Mode 3 with RD, WRL, and WRH pins
//  - 4: *16-bit demultiplexed PSP Mode 4 with R/Wbar, B0SEL, and B1SEL pins
//  - 5: 8-bit multiplexed PSP Mode 5 with RD and WR pins
//  - 6: *8-bit multiplexed PSP Mode 6 with R/Wbar and EN pins
//  - 9: 16-bit multiplexed PSP Mode 9 with AL, RD, WRL, and WRH pins
//  - 10: *16-bit multiplexed PSP Mode 10 with AL, R/Wbar, B0SEL, and B1SEL 
//        pins
// *IMPORTANT NOTE: DO NOT USE PSP MODE 2, 4, 6, OR 10 ON EXPLORER 16! 
// Attempting to do so will cause bus contention with the LCD module which 
// shares the PMP.  Also, PSP Mode 3 is risky on the Explorer 16 since it 
// can randomly cause bus contention with the 25LC256 EEPROM.
#define ENC100_INTERFACE_MODE			0

#if 0
	// Auto-crossover pins on Fast 100Mbps Ethernet PICtail/PICtail Plus.  If 
	// your circuit doesn't have such a feature, delete these two defines.
	#if defined(__dsPIC33E__)|| defined (__PIC24E__)
		#define ENC100_MDIX_TRIS				(TRISAbits.TRISA9)
		#define ENC100_MDIX_IO					(LATAbits.LATA9)
	#else
		#define ENC100_MDIX_TRIS				(TRISBbits.TRISB3)
		#define ENC100_MDIX_IO					(LATBbits.LATB3)
	#endif
		// ENC624J600 I/O control and status pins
	// If a pin is not required for your selected ENC100_INTERFACE_MODE 
	// interface selection (ex: WRH/B1SEL for PSP modes 1, 2, 5, and 6), then 
	// you can ignore, delete, or put anything for the pin definition.  Also, 
	// the INT and POR pins are entirely optional.  If not connected, comment 
	// them out.
	#if defined(__dsPIC33FJ256GP710__) || defined(__PIC24HJ256GP610__)
		#define ENC100_INT_TRIS				(TRISAbits.TRISA13)		// INT signal is optional and currently unused in the Microchip TCP/IP Stack.  Leave this pin disconnected and comment out this pin definition if you don't want it.
		#define ENC100_INT_IO				(PORTAbits.RA13)
	#else
		#define ENC100_INT_TRIS				(TRISEbits.TRISE9)		// INT signal is optional and currently unused in the Microchip TCP/IP Stack.  Leave this pin disconnected and comment out this pin definition if you don't want it.
		#define ENC100_INT_IO				(PORTEbits.RE9)
	#endif
#endif

#define ENC100_CS_TRIS			(TRISDbits.TRISD0)	
#define ENC100_CS_IO			(LATDbits.LATD0)

//#define ENC100_RST_TRIS		    (TRISCbits.TRISC1)
//#define ENC100_RST_IO		    (LATCbits.LATC1)

// SPI SCK, SDI, SDO pins are automatically controlled by the 
// PIC24/dsPIC SPI module 
#define ENC100_SPI_IF			(IFS0bits.SPI1IF)
#define ENC100_SSPBUF			(SPI1BUF)
#define ENC100_SPISTAT			(SPI1STAT)
#define ENC100_SPISTATbits      (SPI1STATbits)
#define ENC100_SPICON			(SPI1CON)
#define ENC100_SPICONbits       (SPI1CONbits)
//#define ENC100_SPICON2			(SPI2CON)

#if 0	// orignal 
	// SPI pinout
	#if defined(__PIC24FJ256GA110__) || defined(__dsPIC33E__)|| defined (__PIC24E__)
		// Some processors must use SPI2 slot on Explorer 16.  
		//If you don't have one of the specified processors but want to use SPI2 for some reason, you can use these definitions.
		#define ENC100_CS_TRIS					(TRISFbits.TRISF12)	// CS is mandatory when using the SPI interface
		#define ENC100_CS_IO					(LATFbits.LATF12)
		#define ENC100_POR_TRIS					(TRISFbits.TRISF13)	// POR signal is optional.  If your application doesn't have a power disconnect feature, comment out this pin definition.
		#define ENC100_POR_IO					(LATFbits.LATF13)
	#else	// All other PIC24s, dsPICs, and PIC32s use SPI1 slot (top most closest to LCD)
		#define ENC100_CS_TRIS					(TRISDbits.TRISD14)	// CS is mandatory when using the SPI interface
		#define ENC100_CS_IO					(LATDbits.LATD14)
		#define ENC100_POR_TRIS					(TRISDbits.TRISD15)	// POR signal is optional.  If your application doesn't have a power disconnect feature, comment out this pin definition.
		#define ENC100_POR_IO					(LATDbits.LATD15)
	#endif

	// ENC624J600 SPI SFR register selection (controls which SPI peripheral to 
	// use on PICs with multiple SPI peripherals).  If a parallel interface is 
	// used (ENC100_INTERFACE_MODE is >= 1), then the SPI is not used and this 
	// section can be ignored or deleted.
	#if defined(__PIC24FJ256GA110__)	// The PIC24FJ256GA110 must use SPI2 slot on Explorer 16.  If you don't have a PIC24FJ256GA110 but want to use SPI2 for some reason, you can use these definitions.
		#define ENC100_ISR_ENABLE		(IEC3bits.INT4IE)
		#define ENC100_ISR_FLAG			(IFS3bits.INT4IF)
		#define ENC100_ISR_POLARITY		(INTCON2bits.INT4EP)
		#define ENC100_ISR_PRIORITY		(IPC13bits.INT4IP)
		#define ENC100_SPI_ENABLE		(ENC100_SPISTATbits.SPIEN)
		#define ENC100_SPI_IF			(IFS1bits.SPI2IF)
		#define ENC100_SSPBUF			(SPI2BUF)
		#define ENC100_SPISTAT			(SPI2STAT)
		#define ENC100_SPISTATbits		(SPI2STATbits)
		#define ENC100_SPICON1			(SPI2CON1)
		#define ENC100_SPICON1bits		(SPI2CON1bits)
		#define ENC100_SPICON2			(SPI2CON2)
	#elif defined (__dsPIC33E__) || defined (__PIC24E__)	
		#define ENC100_ISR_ENABLE		(IEC1bits.INT2IE)
		#define ENC100_ISR_FLAG			(IFS1bits.INT2IF)
		#define ENC100_ISR_POLARITY		(INTCON2bits.INT2EP)
		#define ENC100_ISR_PRIORITY		(IPC7bits.INT2IP)
		#define ENC100_SPI_ENABLE		(ENC100_SPISTATbits.SPIEN)
		#define ENC100_SPI_IF			(IFS0bits.SPI2IF)
		#define ENC100_SSPBUF			(SPI2BUF)
		#define ENC100_SPISTAT			(SPI2STAT)
		#define ENC100_SPISTATbits		(SPI2STATbits)
		#define ENC100_SPICON1			(SPI2CON1)
		#define ENC100_SPICON1bits		(SPI2CON1bits)
		#define ENC100_SPICON2			(SPI2CON2)
	#else	// All other PIC24s and dsPICs use SPI1 slot (top most closest to LCD)
		#define ENC100_ISR_ENABLE		(IEC1bits.INT2IE)
		#define ENC100_ISR_FLAG			(IFS1bits.INT2IF)
		#define ENC100_ISR_POLARITY		(INTCON2bits.INT2EP)
		#define ENC100_ISR_PRIORITY		(IPC7bits.INT2IP)
		#define ENC100_SPI_ENABLE		(ENC100_SPISTATbits.SPIEN)
		#define ENC100_SPI_IF			(IFS0bits.SPI1IF)
		#define ENC100_SSPBUF			(SPI1BUF)
		#define ENC100_SPISTAT			(SPI1STAT)
		#define ENC100_SPISTATbits		(SPI1STATbits)
		#define ENC100_SPICON1			(SPI1CON1)
		#define ENC100_SPICON1bits		(SPI1CON1bits)
		#define ENC100_SPICON2			(SPI1CON2)
	#endif

	// Select which UART the STACK_USE_UART and STACK_USE_UART2TCP_BRIDGE 
	// options will use.  You can change these to U1BRG, U1MODE, etc. if you 
	// want to use the UART1 module instead of UART2.
	#define UBRG				U2BRG
	#define UMODE				U2MODE
	#define USTA				U2STA
	#define BusyUART()			BusyUART2()
	#define CloseUART()			CloseUART2()
	#define ConfigIntUART(a)	ConfigIntUART2(a)
	#define DataRdyUART()		DataRdyUART2()
	#define OpenUART(a,b,c)		OpenUART2(a,b,c)
	#define ReadUART()			ReadUART2()
	#define WriteUART(a)		WriteUART2(a)
	#define getsUART(a,b,c)		getsUART2(a,b,c)
	#define putsUART(a)			putsUART2((unsigned int*)a)
	#define getcUART()			getcUART2()
	#define putcUART(a)			do{while(BusyUART()); WriteUART(a); while(BusyUART()); }while(0)
	#define putrsUART(a)		putrsUART2(a)



#endif



#endif // #ifndef HARDWARE_PROFILE_H
