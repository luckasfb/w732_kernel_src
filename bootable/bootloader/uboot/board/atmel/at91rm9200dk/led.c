/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/*
 * (C) Copyright 2006
 * Atmel Nordic AB <www.atmel.com>
 * Ulf Samuelsson <ulf@atmel.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <asm/arch/AT91RM9200.h>

#define	GREEN_LED	AT91C_PIO_PB0
#define	YELLOW_LED	AT91C_PIO_PB1
#define	RED_LED	AT91C_PIO_PB2

void	green_LED_on(void)
{
	AT91PS_PIO	PIOB	= AT91C_BASE_PIOB;
	PIOB->PIO_CODR		= GREEN_LED;
}

void	 yellow_LED_on(void)
{
	AT91PS_PIO	PIOB	= AT91C_BASE_PIOB;
	PIOB->PIO_CODR		= YELLOW_LED;
}

void	 red_LED_on(void)
{
	AT91PS_PIO	PIOB	= AT91C_BASE_PIOB;
	PIOB->PIO_CODR		= RED_LED;
}

void	green_LED_off(void)
{
	AT91PS_PIO	PIOB	= AT91C_BASE_PIOB;
	PIOB->PIO_SODR		= GREEN_LED;
}

void	yellow_LED_off(void)
{
	AT91PS_PIO	PIOB	= AT91C_BASE_PIOB;
	PIOB->PIO_SODR		= YELLOW_LED;
}

void	red_LED_off(void)
{
	AT91PS_PIO	PIOB	= AT91C_BASE_PIOB;
	PIOB->PIO_SODR		= RED_LED;
}


void coloured_LED_init (void)
{
	AT91PS_PIO	PIOB	= AT91C_BASE_PIOB;
	AT91PS_PMC	PMC	= AT91C_BASE_PMC;
	PMC->PMC_PCER		= (1 << AT91C_ID_PIOB);	/* Enable PIOB clock */
	/* Disable peripherals on LEDs */
	PIOB->PIO_PER		= AT91C_PIO_PB2 | AT91C_PIO_PB1 | AT91C_PIO_PB0;
	/* Enable pins as outputs */
	PIOB->PIO_OER		= AT91C_PIO_PB2 | AT91C_PIO_PB1 | AT91C_PIO_PB0;
	/* Turn all LEDs OFF */
	PIOB->PIO_SODR		= AT91C_PIO_PB2 | AT91C_PIO_PB1 | AT91C_PIO_PB0;
}
