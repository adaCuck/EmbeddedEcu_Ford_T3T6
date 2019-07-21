/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_MotVelCtrl_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  PSCM_FD
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1601056 for Nexteer Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <MotVelCtrl>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MOTVELCTRL_TYPE_H
# define _RTE_MOTVELCTRL_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  define Tq1_LowerLimit (-8.8F)
#  define Tq1_UpperLimit (8.8F)

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MOTVELCTRL_TYPE_H */