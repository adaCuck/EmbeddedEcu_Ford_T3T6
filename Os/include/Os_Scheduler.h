/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup Os_Scheduler
 *
 * \{
 * \file
 * \brief       Interface implementation of \ref Os_Scheduler.
 * \details     --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/


#if !defined (OS_SCHEDULER_H)                                                                                           /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_SCHEDULER_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Scheduler_Types.h"
# include "Os_SchedulerInt.h"
# include "Os_Scheduler_Lcfg.h"

/* Os module dependencies */
# include "Os_Task.h"
# include "Os_BitArray.h"
# include "Os_Deque.h"
# include "Os_Common.h"
# include "Os_PriorityQueue.h"

/* Os HAL dependencies */
# include "Os_Hal_Compiler.h"


#if !defined(OS_VCAST_INSTRUMENTATION_OS_SCHEDULER)
/*VCAST_DONT_INSTRUMENT_START*/
#endif

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_SchedulerPriorityIsHigher()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_SchedulerPriorityIsHigher,
(
  Os_TaskPrioType PrioX,
  Os_TaskPrioType PrioY
))
{
   return ((PrioX) < (PrioY));
}


/***********************************************************************************************************************
 *  Os_SchedulerPriorityIsHigherOrEqual()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE,  Os_SchedulerPriorityIsHigherOrEqual,
(
  Os_TaskPrioType PrioX,
  Os_TaskPrioType PrioY
))
{
  return (Os_StdReturnType)((PrioX) <= (PrioY));
}


/***********************************************************************************************************************
 *  Os_SchedulerPriorityIsLower()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_SchedulerPriorityIsLower,
(
  Os_TaskPrioType PrioX,
  Os_TaskPrioType PrioY
))
{
  return (!Os_SchedulerPriorityIsHigherOrEqual(PrioX, PrioY));
}


/***********************************************************************************************************************
 *  Os_SchedulerGetCurrentTask()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_3219 */
P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_SchedulerGetCurrentTask,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler
))
{
  return Scheduler->Dyn->CurrentTask;
}


/***********************************************************************************************************************
 *  Os_SchedulerTaskSwitchIsNeeded()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType,                                                          /* PRQA S 3219 */ /* MD_Os_3219 */
OS_CODE, OS_ALWAYS_INLINE, Os_SchedulerTaskSwitchIsNeeded,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler
))
{
  return (Os_StdReturnType)(Scheduler->Dyn->CurrentTask != Scheduler->Dyn->NextTask);
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if !defined(OS_VCAST_INSTRUMENTATION_OS_SCHEDULER)
/*VCAST_DONT_INSTRUMENT_END*/
#endif

#endif /* OS_SCHEDULERINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_SchedulerInt.h
 **********************************************************************************************************************/

