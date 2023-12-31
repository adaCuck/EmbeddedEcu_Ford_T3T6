/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Ford_SLP1 (MSR_Ford_SLP1)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701373EABG
 *    License Scope : The usage is restricted to CBD1601056_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hook_Lcfg.h
 *   Generation Time: 2017-07-07 17:17:21
 *           Project: EPS - Version 1.0
 *          Delivery: CBD1601056_D00
 *      Tool Version: DaVinci Configurator (beta) 5.14.21 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

#if !defined (OS_HOOK_LCFG_H)                                                        /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_HOOK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hook_Cfg.h"
# include "Os_Hook_Types.h"

/* Os kernel module dependencies */

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Hook configuration data: Os_CoreInitHook_OsCore_CORE0 */
extern CONST(Os_HookInitHookConfigType, OS_CONST) OsCfg_Hook_Os_CoreInitHook_OsCore_CORE0;

/*! Hook configuration data: StartupHook_OsCore_CORE0 */
extern CONST(Os_HookCallbackConfigType, OS_CONST) OsCfg_Hook_StartupHook_OsCore_CORE0;

/*! Hook configuration data: ShutdownHook_OsCore_CORE0 */
extern CONST(Os_HookStatusHookConfigType, OS_CONST) OsCfg_Hook_ShutdownHook_OsCore_CORE0;

/*! Hook configuration data: ErrorHook_OsCore_CORE0 */
extern CONST(Os_HookStatusHookConfigType, OS_CONST) OsCfg_Hook_ErrorHook_OsCore_CORE0;

/*! Hook configuration data: ProtectionHook_OsCore_CORE0 */
extern CONST(Os_HookProtectionHookConfigType, OS_CONST) OsCfg_Hook_ProtectionHook_OsCore_CORE0;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for hook callbacks. */
extern CONSTP2CONST(Os_HookConfigType, OS_CONST, OS_CONST) OsCfg_HookRefs[OS_CFG_NUM_HOOKS + 1];

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HOOK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hook_Lcfg.h
 *********************************************************************************************************************/
