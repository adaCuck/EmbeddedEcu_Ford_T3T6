/***********************************************************************************************************************
* Copyright 2015 Nexteer
* Nexteer Confidential
*
* Module File Name: SrvFDBC.c
* Module Description: Handwheel Torque Sensor 4 Trim Performed Service processing
* Project           : Common Manufacturing Services
* Author            : Jared Julien
************************************************************************************************************************
* Version Control:
* %version:         1 %
* %derived_by:      kzdyfh %
* ---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                           SCR #
* --------  -------  --------  ---------------------------------------------------------------------------  ----------
* 12/13/16  1        JWJ       Initial file creation                                                        EA4#8626
***********************************************************************************************************************/

/* ================================================================================================================== */
/* Includes */
/* ------------------------------------------------------------------------------------------------------------------ */
#include "Rte_CmnMfgSrv.h"
#include "CmnMfgSrv.h"
#include "CmnMfgSrvTyp.h"
#include "MfgSrvCfg.h"


/* ================================================================================================================== */
/* Service Function Definitions */
/* ------------------------------------------------------------------------------------------------------------------ */

/* ---------------------------------------------------------------------------------------------------------------------
 *        Name:  CmnMfgSrv_SrvFDBCRd
 * Description:  0xFDBC: Handwheel Torque Sensor 4 Trim Performed Read
 *          ID:  0xFDBC
 *        Type:  0x22 (Read)
 *    Sub-Func:  N/A
 *    Req. Len:  0 bytes
 *   Resp. Len:  1 byte
 * ------------------------------------------------------------------------------------------------------------------ */
#if (CMNMFGSRV_FDBCENA_CNT_LGC == CMNMFGSRV_ENAD_CNT_LGC)
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDBCRd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[])
{
	VAR(NegRespCodEnum, AUTOMATIC) RespCod_Cnt_T_enum = MFGSRVNRCPOSRSP;
	VAR(boolean, AUTOMATIC) TrimPrfmdSts_Cnt_T_logl;

	if (Rte_Call_HwTq4TrimPrfmdSts_Oper(&TrimPrfmdSts_Cnt_T_logl) == E_OK)
	{
		DataBuf_Uls_T_u08[0] = (uint8)TrimPrfmdSts_Cnt_T_logl;
	}
	else
	{
		RespCod_Cnt_T_enum = MFGSRVNRCCONDITIONSNOTCORRECT;
	}

	return RespCod_Cnt_T_enum;
}
#endif



/* End of File: SrvFDBC.c */
