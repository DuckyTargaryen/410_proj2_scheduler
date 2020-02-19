/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */
#include "../includes/scheduler_FIFO.h"


bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p){
	if(preemptive){
		return tick_count >= time_slice;
	}
	else{
		return tick_count >= p.finish_time;
	}
}

void Scheduler_FIFO::sort(){
}
