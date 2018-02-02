/*
 * OS.c
 *
 *  Created on: Jan 12, 2018
 *      Author: offou
 */

#include "OS.h"

T_process process[NB_PROCESS]; /* tableau de process */
T_process *running_process=NULL; /*Pointeur sur le processus actif  */
T_process_list stopped; /* process non démarrer */
T_process_list waiting; /*process en attente */
T_process_list process_by_prio[NB_PRIORITY]; /* tableau de liste de priorité */ 
T_process_list ready; /*process en attente d'election*/

void toto (void){
}

void process_init(T_process *process,const unsigned char *name,const void (*fonction)(void)){
	unsigned char i;
	
	for(i=0; i<PROC_NAME_LENGTH; i++)
		process->name[i]=name[i];
	
	process->priority=0;
	process->fonction = fonction;
	process->execution_time=0;
	process->timer=0;
}

void os_init (void) {
	unsigned char i;

	
	for(i=0; i < NB_PROCESS; i++){
		process[i].fonction=NULL;
	}
	
	ready = NULL;
	stopped = NULL;
	waiting = NULL;
	
	for(i=0; i<NB_PRIORITY; i++){
		process_by_prio[i] = NULL;
	}
}

void os_sleep(unsigned long time){
	unsigned long i;
	for(i=0; i<time;i++);
}

void process_start(T_process *process){
	chained_list_append(ready, process);
}

void os_start(){
	T_process *process = ready->process;
	while(1){
		process->fonction();
		chained_list_pop_first(ready);
		chained_list_append(process);
		process = ready->process
	}
}
