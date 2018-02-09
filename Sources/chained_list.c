/*
 * chained_list.c
 *
 *  Created on: Feb 9, 2018
 *      Author: cocasticox
 */

#include "chained_list.h"

#define NB_ELEMS (10)

static T_elem_list_process elems[NB_ELEMS];
static unsigned char elem_index = 0;

void chained_list_pop_first(T_elem_list_process **list){
	
	(*list) = (*list)->next;
	
}

void chained_list_append(T_elem_list_process *list, T_elem_list_process *elem ){
	
	while (list->next){
		list = list->next; 	//On va à la fin de la liste
	}
		
	list->next = elem;		//On ajoute elem à la fin
	elem->next = NULL;
	
}

void *chained_list_create_element(T_process *process){
	
	T_elem_list_process *elem = &elems[elem_index++];
	elem->process = process;
	elem->next = NULL;
	return elem;
	
}
