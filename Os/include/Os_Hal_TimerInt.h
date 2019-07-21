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
 *  \ingroup     Os_Hal
 *  \defgroup    Os_Hal_Timer HAL Timer
 *  \brief       Primitives to work with timer hardware.
 *  \details
 *  MICROSAR OS supports the following timer hardware:
 *  - free running timer (FRT)
 *  - programmable interval timer (PIT)
 *
 *  Often hardware timers can be configured to behave either as a FRT or as a PIT.
 *
 *  If the platform does not support high resolution, check this by an error directive:
 *
 *  ~~~~~~~~~{.c}
 *  #  if OS_CFG_TIMER_HIGH_RESOLUTION == STD_ON
 *  #   error "High resolution is not supported!"
 *  #  endif
 *  ~~~~~~~~~
 *
 *
 *  Free Running Timer (FRT) {#Os_Hal_Timer_FRT}
 *  ========================
 *  This kind of timer keeps repeatedly running from end to end without being reloaded or stopped at intermediate states.
 *  The kernel uses this kind of timer to implement high resolution systems.
 *
 *  MICROSAR OS assumes that this kind of timer has:
 *  - Counter register
 *  - Compare registers
 *  - The ability to generate interrupts.
 *
 *  Counter Register
 *  ----------------
 *  The counter register (sometimes called timer register) is most typically a n-bit up or down counter, with the
 *  ability to read and write the current count value.
 *
 *  Compare Registers
 *  -----------------
 *  Compare registers (sometimes called match registers) hold a value against which the current counter value
 *  is automatically and continuously compared. A compare register is used to trigger an interrupt when the value in
 *  the counter register matches the value in the compare register.
 *
 *  FRT Interrupt
 *  -------------
 *  A FRT uses a compare match to generate an interrupt, but does not configure the timer to clear when
 *  the match occurs. Thus the interrupt is triggered but the timer continues to run. It will eventually overflow,
 *  going from 2<sup>n</sup>-1 to 0, but that overflow will not stop the timer either. So the timer register counts
 *  indefinitely, going from 0 to 2<sup>n</sup>-1 and repeating that cycle endlessly.
 *
 *
 *  Programmable Interval Timer (PIT) {#Os_Hal_Timer_PIT}
 *  =================================
 *  This kind of timer generates an output signal when it reaches a programmed count and performs a reset in hardware.
 *
 *  A PIT does not necessarily need a compare register. It may use the counter overflow to generate an interrupt.
 *  Therefore MICROSAR OS assumes that this kind of timer has:
 *  - Counter register
 *  - The ability to generate interrupts.
 *
 *  PIT Interrupt
 *  -------------
 *  The interrupt is generated by match between the counter register and a compare register (or overflow).
 *
 *  The compare event which triggers the interrupt also automatically reloads the counter register,
 *  so we have a configuration that can generate repetitive timing intervals.
 *
 *  Using a FRT as a PIT
 *  --------------------
 *  The FRT can be used to implement a PIT in software. The compare register must be modified on each interrupt.
 *  The modification just involves adding a constant (the timer period, in ticks) to the compare register
 *  (ignoring any overflow).
 *
 *
 *  \see [Timers/Counters](http://www.scriptoriumdesigns.com/embedded/timers.php)
 *  \see [Counter](http://en.wikipedia.org/wiki/Counter_%28digital%29)
 *  \see [PIT](http://en.wikipedia.org/wiki/Programmable_interval_timer)
 *  \see \ref GlossaryHighResolutionTimer
 *  \see \ref JobScheduling
 *  \see Os_Counter
 *
 *  \{
 *
 *  \file         Os_Hal_TimerInt.h
 *  \brief        HAL interface to work with timer hardware.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#if !defined(OS_HAL_TIMERINT_H)                                                                                         /* PRQA S 0883 */ /* MD_Os_Hal_0883 */
# define OS_HAL_TIMERINT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Timer_Types.h"

/* Os kernel module dependencies */
# include "Os_Common_Types.h"

/* Os HAL dependencies */
# include "Os_Hal_CompilerInt.h"
# include "Os_Hal_Interrupt_Types.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/*! Programmable interval timer configuration information. */
struct Os_Hal_TimerConfigType_Tag
{
  /*! The timers base address. */
  uint32 TimerBaseAddr;
  /*! The concrete timer class. */
  uint32 TimerType;
  /*! The assigned timer channel. */
  uint32 TimerChannel;
  /*! The timer's compare value. */
  uint32 CompareValue;


  /*! High resolution timer configuration information. */
  Os_Hal_IntIsrConfigRefType IsrConfig;
};


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  Os_Hal_TimerPitInit()
 **********************************************************************************************************************/
/*! \brief          Initialize a programmable interval timer hardware using the given configuration.
 *  \details
 *  The kernel uses this function during OS initialization to initialize hardware timers.
 *  Enable the interrupt source of the hardware timer.
 *
 *  \param[in]      TimerConfig     Timer hardware configuration.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerPitInit,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
));


/***********************************************************************************************************************
 *  Os_Hal_TimerPitAckAndReload()
 **********************************************************************************************************************/
/*! \brief          Acknowledge the timer interrupt and reload the compare value of the PIT.
 *  \details
 *  The kernel uses this function to implement the PIT ISR. It is used to clear the pending timer interrupt flag.
 *  This function should reload the compare value, if the timer hardware doesn't perform this automatically.
 *
 *  \param[in]      TimerConfig     Timer hardware configuration.
 *
 *  \context        ISR2|OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerPitAckAndReload,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
));


/***********************************************************************************************************************
 *  Os_Hal_TimerPitIsPending()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given timer hardware has a pending interrupt.
 *  \details
 *  The kernel uses this function to detect job overload.
 *
 *  \param[in]      TimerConfig     Timer hardware configuration.
 *
 *  \return         !0    Interrupt pending.
 *  \return         0     No interrupt pending.
 *
 *  \context        ISR2|OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerPitIsPending,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
));


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtInit()
 **********************************************************************************************************************/
/*! \brief          Initialize a free running timer using the given configuration.
 *  \details
 *  The kernel uses this function during OS initialization to initialize hardware timers.
 *  Enable the interrupt source of the hardware timer.
 *
 *  \param[in]      TimerConfig     Timer hardware configuration.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtInit,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
));


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtGetCounterValue()
 **********************************************************************************************************************/
/*! \brief          Return the current counter register value of the given free running timer.
 *  \details
 *  The kernel uses this function to implement the AUTOSAR counter interface in case of a free running timer.
 *
 *  \param[in]      TimerConfig     Timer hardware configuration.
 *
 *  \return         Current counter register value.
 *
 *  \context        OS_INTERNAL|ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *  \pre            Concurrent access prevented by caller.
 *  \trace          SPEC-63797
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_Hal_TimerFrtTickType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtGetCounterValue,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
));


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtSetCompareValue()
 **********************************************************************************************************************/
/*! \brief          Set the compare value of the given HRT.
 *  \details
 *  This function shall set the compare value of the given timer.
 *
 *  \param[in,out]  TimerConfig     Timer hardware configuration.
 *  \param[in]      ExpirationTime  The new compare value.
 *
 *  \context        ISR2|OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 *  \trace          SPEC-63797
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtSetCompareValue,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig,
  Os_Hal_TimerFrtTickType ExpirationTime
));


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtAcknowledge()
 **********************************************************************************************************************/
/*! \brief          Tell the timer hardware, that we are handling the interrupt request.
 *  \details
 *  The kernel uses this function to implement the FRT ISR. It is used to clear pending timer interrupt flags,
 *  to be able to configure the next timer interrupt.
 *
 *  \param[in]      TimerConfig     Timer hardware configuration.
 *
 *  \context        ISR2|OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtAcknowledge,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
));


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtTriggerIrq()
 **********************************************************************************************************************/
/*! \brief          Triggers a HRT timer interrupt.
 *  \details        The kernel uses this function, to trigger a timer ISR, if it detects that an expiration time stamp
 *                  has been missed.
 *
 *  \param[in]      TimerConfig     Timer hardware configuration.
 *
 *  \context        ISR2|OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtTriggerIrq,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
));


/***********************************************************************************************************************
 *  Os_Hal_TimerStmEnabled()
 **********************************************************************************************************************/
/*! \brief          Returns whether STM timers are enabled (!0) or not (0).
 *  \details        --no details--
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerStmEnabled, (void));


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* OS_HAL_TIMERINT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_TimerInt.h
 **********************************************************************************************************************/

