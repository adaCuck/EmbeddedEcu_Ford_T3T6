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
 *              File: Os_Link.ld
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

/*******  CODE sections  *********************************************************************************************/

#if defined ( OS_LINK_CODE )
.OS_CODE ALIGN(4) :> .
_OS_CODE_START = ADDR(.OS_CODE);
_OS_CODE_END = ENDADDR(.OS_CODE);
#endif

#if defined ( OS_LINK_INTVEC_CODE )
.OS_INTVEC_CODE ALIGN(512) :> .
_OS_INTVEC_CODE_START = ADDR(.OS_INTVEC_CODE);
_OS_INTVEC_CODE_END = ENDADDR(.OS_INTVEC_CODE);
#endif

#if defined ( OS_LINK_CALLOUT_CODE )
.OS_ERRORHOOK_CODE ALIGN(4) :> .
_OS_ERRORHOOK_CODE_START = ADDR(.OS_ERRORHOOK_CODE);
_OS_ERRORHOOK_CODE_END = ENDADDR(.OS_ERRORHOOK_CODE);
.OS_OS_COREINITHOOK_CODE ALIGN(4) :> .
_OS_OS_COREINITHOOK_CODE_START = ADDR(.OS_OS_COREINITHOOK_CODE);
_OS_OS_COREINITHOOK_CODE_END = ENDADDR(.OS_OS_COREINITHOOK_CODE);
.OS_PROTECTIONHOOK_CODE ALIGN(4) :> .
_OS_PROTECTIONHOOK_CODE_START = ADDR(.OS_PROTECTIONHOOK_CODE);
_OS_PROTECTIONHOOK_CODE_END = ENDADDR(.OS_PROTECTIONHOOK_CODE);
.OS_SHUTDOWNHOOK_CODE ALIGN(4) :> .
_OS_SHUTDOWNHOOK_CODE_START = ADDR(.OS_SHUTDOWNHOOK_CODE);
_OS_SHUTDOWNHOOK_CODE_END = ENDADDR(.OS_SHUTDOWNHOOK_CODE);
.OS_STARTUPHOOK_CODE ALIGN(4) :> .
_OS_STARTUPHOOK_CODE_START = ADDR(.OS_STARTUPHOOK_CODE);
_OS_STARTUPHOOK_CODE_END = ENDADDR(.OS_STARTUPHOOK_CODE);
#endif

#ifdef OS_LINK_CODE
# undef OS_LINK_CODE
#endif

#ifdef OS_LINK_INTVEC_CODE
# undef OS_LINK_INTVEC_CODE
#endif

#ifdef OS_LINK_CALLOUT_CODE
# undef OS_LINK_CALLOUT_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_FAR )
.OS_CONST ALIGN(4) :> .
_OS_CONST_START = ADDR(.OS_CONST);
_OS_CONST_END = ENDADDR(.OS_CONST);
.OS_GLOBALSHARED_CONST ALIGN(4) :> .
_OS_GLOBALSHARED_CONST_START = ADDR(.OS_GLOBALSHARED_CONST);
_OS_GLOBALSHARED_CONST_END = ENDADDR(.OS_GLOBALSHARED_CONST);
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_NEAR )
.OS_CONST_FAST ALIGN(4) :> .
_OS_CONST_FAST_START = ADDR(.OS_CONST_FAST);
_OS_CONST_FAST_END = ENDADDR(.OS_CONST_FAST);
.OS_GLOBALSHARED_CONST_FAST ALIGN(4) :> .
_OS_GLOBALSHARED_CONST_FAST_START = ADDR(.OS_GLOBALSHARED_CONST_FAST);
_OS_GLOBALSHARED_CONST_FAST_END = ENDADDR(.OS_GLOBALSHARED_CONST_FAST);
#endif

#if defined ( OS_LINK_INTVEC_CONST )
.OS_INTVEC_CONST ALIGN(4) :> .
_OS_INTVEC_CONST_START = ADDR(.OS_INTVEC_CONST);
_OS_INTVEC_CONST_END = ENDADDR(.OS_INTVEC_CONST);
#endif

#ifdef OS_LINK_CONST
# undef OS_LINK_CONST
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED
# undef OS_LINK_CONST_GLOBALSHARED
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_NEAR
# undef OS_LINK_CONST_GLOBALSHARED_NEAR
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_FAR
# undef OS_LINK_CONST_GLOBALSHARED_FAR
#endif

#ifdef OS_LINK_INTVEC_CONST
# undef OS_LINK_INTVEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_INIT )
.OS_VAR_NOCACHE ALIGN(4) :> .
_OS_VAR_NOCACHE_START = ADDR(.OS_VAR_NOCACHE);
_OS_VAR_NOCACHE_END = ENDADDR(.OS_VAR_NOCACHE);
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOINIT )
.OS_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_VAR_NOCACHE_NOINIT_START = ADDR(.OS_VAR_NOCACHE_NOINIT);
_OS_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_VAR_NOCACHE_NOINIT);
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_INIT )
.OS_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_VAR_FAST_NOCACHE_START = ADDR(.OS_VAR_FAST_NOCACHE);
_OS_VAR_FAST_NOCACHE_END = ENDADDR(.OS_VAR_FAST_NOCACHE);
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOINIT )
.OS_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_VAR_FAST_NOCACHE_NOINIT);
_OS_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_VAR_FAST_NOCACHE_NOINIT);
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_INIT )
.OS_GLOBALSHARED_VAR ALIGN(4) :> .
_OS_GLOBALSHARED_VAR_START = ADDR(.OS_GLOBALSHARED_VAR);
_OS_GLOBALSHARED_VAR_END = ENDADDR(.OS_GLOBALSHARED_VAR);
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOINIT )
.OS_GLOBALSHARED_VAR_NOINIT ALIGN(4) :> .
_OS_GLOBALSHARED_VAR_NOINIT_START = ADDR(.OS_GLOBALSHARED_VAR_NOINIT);
_OS_GLOBALSHARED_VAR_NOINIT_END = ENDADDR(.OS_GLOBALSHARED_VAR_NOINIT);
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_ZERO_INIT )
.OS_GLOBALSHARED_VAR_ZERO_INIT ALIGN(4) :> .
_OS_GLOBALSHARED_VAR_ZERO_INIT_START = ADDR(.OS_GLOBALSHARED_VAR_ZERO_INIT);
_OS_GLOBALSHARED_VAR_ZERO_INIT_END = ENDADDR(.OS_GLOBALSHARED_VAR_ZERO_INIT);
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_INIT )
.OS_GLOBALSHARED_VAR_FAST ALIGN(4) :> .
_OS_GLOBALSHARED_VAR_FAST_START = ADDR(.OS_GLOBALSHARED_VAR_FAST);
_OS_GLOBALSHARED_VAR_FAST_END = ENDADDR(.OS_GLOBALSHARED_VAR_FAST);
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOINIT )
.OS_GLOBALSHARED_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_GLOBALSHARED_VAR_FAST_NOINIT_START = ADDR(.OS_GLOBALSHARED_VAR_FAST_NOINIT);
_OS_GLOBALSHARED_VAR_FAST_NOINIT_END = ENDADDR(.OS_GLOBALSHARED_VAR_FAST_NOINIT);
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_ZERO_INIT )
.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT ALIGN(4) :> .
_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_START = ADDR(.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT);
_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_END = ENDADDR(.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT);
#endif

#ifdef OS_LINK_VAR
# undef OS_LINK_VAR
#endif

#ifdef OS_LINK_VAR_KERNEL
# undef OS_LINK_VAR_KERNEL
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR
# undef OS_LINK_VAR_KERNEL_FAR
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_INIT
# undef OS_LINK_VAR_KERNEL_FAR_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR
# undef OS_LINK_VAR_KERNEL_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOINIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED
# undef OS_LINK_VAR_GLOBALSHARED
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR
# undef OS_LINK_VAR_GLOBALSHARED_NEAR
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_INIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_NOINIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_NOINIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_ZERO_INIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR
# undef OS_LINK_VAR_GLOBALSHARED_FAR
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_INIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_NOINIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_NOINIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_ZERO_INIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_ZERO_INIT
#endif


/*******  SPINLOCK sections  *****************************************************************************************/

#if defined ( OS_LINK_SPINLOCKS ) || defined ( OS_LINK_SPINLOCKS_FAR )
#endif

#if defined ( OS_LINK_SPINLOCKS ) || defined ( OS_LINK_SPINLOCKS_NEAR )
#endif

#ifdef OS_LINK_SPINLOCKS
# undef OS_LINK_SPINLOCKS
#endif

#ifdef OS_LINK_SPINLOCKS_NEAR
# undef OS_LINK_SPINLOCKS_NEAR
#endif

#ifdef OS_LINK_SPINLOCKS_FAR
# undef OS_LINK_SPINLOCKS_FAR
#endif


