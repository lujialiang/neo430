// #################################################################################################
// #  < neo430.h - MAIN NEO430 INCLUDE FILE >                                                      #
// # ********************************************************************************************* #
// #  This file is crucial for all NEO430 software projects!                                       #
// #  You only need to include this file into your project code (all sub-libraries are included    #
// #  in this library file).                                                                       #
// # ********************************************************************************************* #
// # This file is part of the NEO430 Processor project: https://github.com/stnolting/neo430        #
// # Copyright by Stephan Nolting: stnolting@gmail.com                                             #
// #                                                                                               #
// # This source file may be used and distributed without restriction provided that this copyright #
// # statement is not removed from the file and that any derivative work contains the original     #
// # copyright notice and the associated disclaimer.                                               #
// #                                                                                               #
// # This source file is free software; you can redistribute it and/or modify it under the terms   #
// # of the GNU Lesser General Public License as published by the Free Software Foundation,        #
// # either version 3 of the License, or (at your option) any later version.                       #
// #                                                                                               #
// # This source is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;      #
// # without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.     #
// # See the GNU Lesser General Public License for more details.                                   #
// #                                                                                               #
// # You should have received a copy of the GNU Lesser General Public License along with this      #
// # source; if not, download it from https://www.gnu.org/licenses/lgpl-3.0.en.html                #
// # ********************************************************************************************* #
// #  Stephan Nolting, Hannover, Germany                                               19.07.2017  #
// #################################################################################################

#ifndef neo430_h
#define neo430_h

// STD libraries
#include <stdint.h>
#include <stdlib.h>

// ----------------------------------------------------------------------------
// CPU Status Register (r2) Flags
// ----------------------------------------------------------------------------
#define C_FLAG 0  // carry
#define Z_FLAG 1  // zero
#define N_FLAG 2  // negative
#define I_FLAG 3  // global interrupt enable
#define S_FLAG 4  // sleep
#define V_FLAG 8  // overflow
#define R_FLAG 15 // allow write-access to IMEM


// ----------------------------------------------------------------------------
// Processor peripheral/IO devices
// Beginning of IO area: 0xFF80
// Size of IO area: 128 bytes
// ----------------------------------------------------------------------------
#define REG8  (volatile uint8_t*)
#define REG16 (volatile uint16_t*)
#define REG32 (volatile uint32_t*)

/* --- Custom Function Unit - CFU --- */
#define CFU_REG0    (*(REG16 0xFF80)) // ?/? user defined
#define CFU_REG0_LO (*(REG8  0xFF80)) // ?/? user defined
#define CFU_REG0_HI (*(REG8  0xFF81)) // ?/? user defined
#define CFU_REG1    (*(REG16 0xFF82)) // ?/? user defined
#define CFU_REG1_LO (*(REG8  0xFF82)) // ?/? user defined
#define CFU_REG1_HI (*(REG8  0xFF83)) // ?/? user defined
#define CFU_REG2    (*(REG16 0xFF84)) // ?/? user defined
#define CFU_REG2_LO (*(REG8  0xFF84)) // ?/? user defined
#define CFU_REG2_HI (*(REG8  0xFF85)) // ?/? user defined
#define CFU_REG3    (*(REG16 0xFF86)) // ?/? user defined
#define CFU_REG3_LO (*(REG8  0xFF86)) // ?/? user defined
#define CFU_REG3_HI (*(REG8  0xFF87)) // ?/? user defined
#define CFU_REG4    (*(REG16 0xFF88)) // ?/? user defined
#define CFU_REG4_LO (*(REG8  0xFF88)) // ?/? user defined
#define CFU_REG4_HI (*(REG8  0xFF89)) // ?/? user defined
#define CFU_REG5    (*(REG16 0xFF8A)) // ?/? user defined
#define CFU_REG5_LO (*(REG8  0xFF8A)) // ?/? user defined
#define CFU_REG5_HI (*(REG8  0xFF8B)) // ?/? user defined
#define CFU_REG6    (*(REG16 0xFF8C)) // ?/? user defined
#define CFU_REG6_LO (*(REG8  0xFF8C)) // ?/? user defined
#define CFU_REG6_HI (*(REG8  0xFF8D)) // ?/? user defined
#define CFU_REG7    (*(REG16 0xFF8E)) // ?/? user defined
#define CFU_REG7_LO (*(REG8  0xFF8E)) // ?/? user defined
#define CFU_REG7_HI (*(REG8  0xFF8F)) // ?/? user defined


/* --- Wishbone Bus Adapter - WB32 --- */
#define WB32_LRA (*(REG16 0xFF90)) // -/w: low address for read transfer
#define WB32_HRA (*(REG16 0xFF92)) // -/w: high address for read transfer (+trigger)
#define WB32_LWA (*(REG16 0xFF94)) // -/w: low address for write transfer
#define WB32_HWA (*(REG16 0xFF96)) // -/w: high address for write transfer (+trigger)
#define WB32_LD  (*(REG16 0xFF98)) // r/w: low data
#define WB32_HD  (*(REG16 0xFF9A)) // r/w: high data
#define WB32_xxx (*(REG16 0xFF9C)) // -/-: reserved
#define WB32_CT  (*(REG16 0xFF9E)) // r/w: control register

// WB32 - 32-bit register access
#define WB32_RA_32bit (*(REG32 (&WB32_LRA))) // -/w: address for read transfer (+trigger)
#define WB32_WA_32bit (*(REG32 (&WB32_LWA))) // -/w: address for write transfer (+trigger)
#define WB32_D_32bit  (*(REG32 (&WB32_LD)))  // r/w: read/write data (for 32-bit access)
#define WB32_D_8bit   (*(REG8  (&WB32_LD)))  // r/w: read/write data (for 8-bit access)

// WB32 control register
#define WB32_CT_WBSEL0   0 // -/w: wishbone data byte enable bit 0
#define WB32_CT_WBSEL1   1 // -/w: wishbone data byte enable bit 1
#define WB32_CT_WBSEL2   2 // -/w: wishbone data byte enable bit 2
#define WB32_CT_WBSEL3   3 // -/w: wishbone data byte enable bit 3
#define WB32_CT_PMODE    4 // -/w: 0: standard transfers, 1: pipelined transfers
#define WB32_CT_PENDING 15 // r/-: pending transfer


/* --- Universal Serial Transceiver - USART/USI --- */
#define USI_SPIRTX  (*(REG16 0xFFA0)) // r/w: spi receive/transmit register
#define USI_UARTRTX (*(REG16 0xFFA2)) // r/w: uart receive/transmit register
#define USI_BAUD    (*(REG16 0xFFA4)) // r/w: uart baud rate generator value
#define USI_CT      (*(REG16 0xFFA6)) // r/w: control register

// UART USI_BAUD[7:0]:  baud rate value
// UART USI_BAUD[10:8]: baud prescaler select:
// 0: CLK/2
// 1: CLK/4
// 2: CLK/8
// 3: CLK/64
// 4: CLK/128
// 5: CLK/1024
// 6: CLK/2048
// 7: CLK/4096

// USART UART RTX register
#define USI_UARTRTX_UARTRXAVAIL 15 // r/-: uart receiver data available

// USART control register
#define USI_CT_EN         0 // r/w: USART enable
#define USI_CT_UARTRXIRQ  1 // r/w: uart rx done interrupt enable
#define USI_CT_UARTTXIRQ  2 // r/w: uart tx done interrupt enable
#define USI_CT_UARTTXBSY  3 // r/-: uart transmitter is busy
#define USI_CT_SPICPHA    4 // r/w: spi clock phase (idle polarity = '0')
#define USI_CT_SPIIRQ     5 // r/w: spi transmission done interrupt enable
#define USI_CT_SPIBSY     6 // r/-: spi transceiver is busy
#define USI_CT_SPIPRSC0   7 // r/w: spi prescaler select bit 0
#define USI_CT_SPIPRSC1   8 // r/w: spi prescaler select bit 1
#define USI_CT_SPIPRSC2   9 // r/w: spi prescaler select bit 2
#define USI_CT_SPICS0    10 // r/w: spi direct CS 0, CS is low (active) when bit is set
#define USI_CT_SPICS1    11 // r/w: spi direct CS 1, CS is low (active) when bit is set
#define USI_CT_SPICS2    12 // r/w: spi direct CS 2, CS is low (active) when bit is set
#define USI_CT_SPICS3    13 // r/w: spi direct CS 3, CS is low (active) when bit is set
#define USI_CT_SPICS4    14 // r/w: spi direct CS 4, CS is low (active) when bit is set
#define USI_CT_SPICS5    15 // r/w: spi direct CS 5, CS is low (active) when bit is set

// SPI clock prescaler select:
// 0: CLK/2
// 1: CLK/4
// 2: CLK/8
// 3: CLK/64
// 4: CLK/128
// 5: CLK/1024
// 6: CLK/2048
// 7: CLK/4096


/* --- Genearl Purpose Inputs/Outputs - GPIO --- */
#define GPIO_IN      (*(REG16 0xFFB0)) // r/-: parallel input
#define GPIO_OUT     (*(REG16 0xFFB2)) // r/w: parallel output
#define GPIO_CTRL    (*(REG16 0xFFB4)) // -/w: control register
#define GPIO_IRQMASK (*(REG16 0xFFB6)) // -/w: irq mask register

// bits 1:0 of GPIO CTRL reg: Trigger
// 00: low level
// 01: high level
// 10: falling edge
// 11: rising edge
// bit 2: General interrupt enable flag


/* --- High-Precision Timer - TIMER --- */
#define TMR_CNT   (*(REG16 0xFFC0)) // r/w: counter register
#define TMR_THRES (*(REG16 0xFFC2)) // r/w: threshold register
#define TMR_CT    (*(REG16 0xFFC4)) // r/w: control register

// Timer control register
#define TMR_CT_EN    0 // r/w: timer enable
#define TMR_CT_ARST  1 // r/w: auto reset on match
#define TMR_CT_IRQ   2 // r/w: interrupt enable
#define TMR_CT_PRSC0 3 // r/w: prescaler select bit 0
#define TMR_CT_PRSC1 4 // r/w: prescaler select bit 1
#define TMR_CT_PRSC2 5 // r/w: prescaler select bit 2

// timer clock prescaler select:
// 0: CLK/2
// 1: CLK/4
// 2: CLK/8
// 3: CLK/64
// 4: CLK/128
// 5: CLK/1024
// 6: CLK/2048
// 7: CLK/4096


/* --- Watchdog Timer - WTD --- */
#define WDT_CTRL (*(REG16 0xFFD0)) // r/w: Watchdog control register

// Watchdog control register
#define WDT_PASSWORD 0x47 // must be set in the upper 8 bits of the WDT CTRL register
#define WDT_CLKSEL0  0 // r/w: prescaler select bit 0
#define WDT_CLKSEL1  1 // r/w: prescaler select bit 1
#define WDT_CLKSEL2  2 // r/w: prescaler select bit 2
#define WDT_ENABLE   3 // r/w: WDT enable
#define WDT_RCAUSE   4 // r/-: reset cause (0: external, 1: watchdog timeout)
#define WDT_SYSRST   5 // -/w: set one to generate system hardware reset

// watchdog clock prescaler select:
// 0: CLK/2
// 1: CLK/4
// 2: CLK/8
// 3: CLK/64
// 4: CLK/128
// 5: CLK/1024
// 6: CLK/2048
// 7: CLK/4096


/* --- System Configuration - SYSCONFIG --- */
#define CPUID0 (*(REG16 0xFFE0)) // r/-: HW version
#define CPUID1 (*(REG16 0xFFE2)) // r/-: system configuration
#define CPUID2 (*(REG16 0xFFE4)) // r/-: CPU identifier
#define CPUID3 (*(REG16 0xFFE6)) // r/-: IMEM/ROM size in bytes
#define CPUID4 (*(REG16 0xFFE8)) // r/-: DMEM/RAM base address
#define CPUID5 (*(REG16 0xFFEA)) // r/-: DMEM/RAM size in bytes
#define CPUID6 (*(REG16 0xFFEC)) // r/-: clock speed lo
#define CPUID7 (*(REG16 0xFFEE)) // r/-: clock speed hi
// Aliases
#define HW_VERSION    CPUID0 // r/-: HW verison number
#define SYS_FEATURES  CPUID1 // r/-: synthesized system features
#define USER_CODE     CPUID2 // r/-: custom user code
#define IMEM_SIZE     CPUID3 // r/-: IMEM/ROM size in bytes
#define DMEM_BASE     CPUID4 // r/-: DMEM/RAM base address
#define DMEM_SIZE     CPUID5 // r/-: DMEM/RAM size in bytes
#define CLOCKSPEED_LO CPUID6 // r/-: clock speed (in Hz) low part
#define CLOCKSPEED_HI CPUID7 // r/-: clock speed (in Hz) high part

// SysConfig - 32-bit register access
#define CLOCKSPEED_32bit (*(REG32 (&CLOCKSPEED_LO))) // r/-: clock speed (in Hz)

// SYS features
#define SYS_CFU_EN    0 // CFU synthesized
#define SYS_WB32_EN   1 // WB32 synthesized
#define SYS_WDT_EN    2 // WDT synthesized
#define SYS_GPIO_EN   3 // GPIO synthesized
#define SYS_TIMER_EN  4 // timer synthesized
#define SYS_USART_EN  5 // USART synthesized
#define SYS_DADD_EN   6 // DADD instruction synthesized
#define SYS_BTLD_EN   7 // Bootloader installed and enabled?
#define SYS_IROM_EN   8 // Implement IMEM as true ROM?

// Interrupt vectors (mirrored 2x times)
//#define IRQVEC_TIMER (*(REG16 0xFFF0)) // r/w: mirrored IRQ vector register
//#define IRQVEC_USART (*(REG16 0xFFF2)) // r/w: mirrored IRQ vector register
//#define IRQVEC_GPIO  (*(REG16 0xFFF4)) // r/w: mirrored IRQ vector register
//#define IRQVEC_EXT   (*(REG16 0xFFF6)) // r/w: mirrored IRQ vector register
#define IRQVEC_TIMER (*(REG16 0xFFF8)) // r/w: timer match
#define IRQVEC_USART (*(REG16 0xFFFA)) // r/w: uart rx avail / uart tx done / spi rtx done
#define IRQVEC_GPIO  (*(REG16 0xFFFC)) // r/w: gpio pin change
#define IRQVEC_EXT   (*(REG16 0xFFFE)) // r/w: external IRQ


// ----------------------------------------------------------------------------
// Include IO libraries
// ----------------------------------------------------------------------------
#include "neo430_cpu.h"
#include "neo430_gpio.h"
#include "neo430_usart.h"
#include "neo430_wdt.h"
#include "neo430_wishbone.h"


#endif // neo430_h
