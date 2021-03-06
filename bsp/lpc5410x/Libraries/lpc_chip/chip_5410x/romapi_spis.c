/*
 * @brief SPI slave ROM API declarations and functions
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2014
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "romapi_5410x.h"

/* Get memory size in bytes needed for SPI slave driver context */
uint32_t ROM_SPIS_GetMemSize(void)
{
#if defined(ROMDRIVERSV2_PRESENT)
	return ROMAPI_SPIS_API->GetMemSize();
#else
	return spis_api.GetMemSize();
#endif
}

/* Initialize SPI slave peripheral */
ROM_SPIS_HANDLE_T ROM_SPIS_Init(void *mem, ROM_SPIS_INIT_T *pInit)
{
#if defined(ROMDRIVERSV2_PRESENT)
	return ROMAPI_SPIS_API->Init(mem, pInit);
#else
	return spis_api.Init(mem, pInit);
#endif
}

void ROM_SPIS_RegisterCallback(ROM_SPIS_HANDLE_T pHandle, ROM_SPIS_CALLBACK_T cbIndex, void *pCB)
{
#if defined(ROMDRIVERSV2_PRESENT)
	ROMAPI_SPIS_API->RegisterCallback(pHandle, cbIndex, pCB);
#else
	spis_api.RegisterCallback(pHandle, cbIndex, pCB);
#endif
}

ErrorCode_t ROM_SPIS_SetupSlave(ROM_SPIS_HANDLE_T pHandle, ROM_SPIS_SLAVE_T *pSlaveSetup)
{
#if defined(ROMDRIVERSV2_PRESENT)
	return ROMAPI_SPIS_API->SetupSlave(pHandle, pSlaveSetup);
#else
	return spis_api.SetupSlave(pHandle, pSlaveSetup);
#endif
}

ErrorCode_t ROM_SPIS_Transfer(ROM_SPIS_HANDLE_T pHandle, ROM_SPIS_XFER_T *pXfer)
{
#if defined(ROMDRIVERSV2_PRESENT)
	return ROMAPI_SPIS_API->Transfer(pHandle, pXfer);
#else
	return spis_api.Transfer(pHandle, pXfer);
#endif
}

void ROM_SPIS_TransferHandler(ROM_SPIS_HANDLE_T pHandle)
{
#if defined(ROMDRIVERSV2_PRESENT)
	ROMAPI_SPIS_API->TransferHandler(pHandle);
#else
	spis_api.TransferHandler(pHandle);
#endif
}

/* Return the SPI slave ROM driver version */
uint16_t ROM_SPIS_GetDriverVersion(void)
{
#if defined(ROMDRIVERSV2_PRESENT)
	return ROMAPI_SPIS_API->GetDriverVersion();
#else
	return spis_api.GetDriverVersion();
#endif
}
