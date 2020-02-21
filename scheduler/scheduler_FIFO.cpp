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

/**
 * Determines whether or not it is time to switch processes.
 * @param tick_count - Number of CPU ticks.
 * @param p - Process on the CPU.
 * @return bool - Whether or not to switch processes.
 */
bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p){
	if(p.remaining_cpu_time < 0){
		p.remaining_cpu_time = 0;
	}
	return p.remaining_cpu_time == 0;
}

/**
 * Sorts the ready_q based on the algorithm used.
 * FIFO does not sort the ready_q.
 */
void Scheduler_FIFO::sort(){
}
