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
	/*if(preemptive){
		p.remaining_cpu_time = p.remaining_cpu_time - 1;
		if(p.remaining_cpu_time < 0){
			p.remaining_cpu_time = 0;
		}
		//ready_q->pop();
		return (tick_count % time_slice) == 0;
	}*/
	//p.remaining_cpu_time = p.remaining_cpu_time - 1;
	if(p.remaining_cpu_time < 0){
		p.remaining_cpu_time = 0;
	}
		//ready_q->pop();
	return p.remaining_cpu_time == 0;
}

void Scheduler_FIFO::sort(){
}
