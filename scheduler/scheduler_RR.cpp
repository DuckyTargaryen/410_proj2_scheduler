/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

#include "../includes/scheduler_RR.h"

/**
 * Determines whether it is time to switch processes.
 * @param tick_count - Number of CPU ticks.
 * @param p - Process on the CPU.
 * @return bool - Whether or not a process is complete or its time slice is finished.
 */
bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p){
	if(p.remaining_cpu_time <= 0){
		p.remaining_cpu_time = 0;
		return p.remaining_cpu_time == 0;
	}
	return ((p.required_cpu_time - p.remaining_cpu_time) % time_slice) == 0;
}

/**
 * Sorts the ready_q based on the algorithm used.
 * The RR algorithm does not sort the ready_q.
 */
void Scheduler_RR::sort(){
}
