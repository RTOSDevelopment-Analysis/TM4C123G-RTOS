#ifndef MIROS_H
#define MIROS_H

/* Thread Control Block (TCB) */
typedef struct {
	void *sp; /* stack pointer */
	uint32_t timeout; /* timeout delay down-counter */
	uint8_t prio; /* thread priority */
	/* ...other attributes associated with a thread */
} OSThread;

typedef void (*OSThreadHandler)();

void OS_init(void *stkSto, uint32_t stkSize);

/* callback to handle the idle condition */
void OS_onIdle(void);

/* This function must be called with interrupts DISABLED */ 
void OS_sched(void);

/* transfer control to the RTOS to run the threads */
void OS_run(void);

/* blocking delay */
void OS_delay(uint32_t ticks);

/* process all timeouts */
void OS_tick(void);

/* callback to configure and start interrupts */
void OS_onStartup(void);

void OSThread_start(
	OSThread *me,
	uint8_t  prio, /* thread priority */
	OSThreadHandler threadHandler,
	void *stkSto, uint32_t stkSize);

#endif /* MIROS_H */
