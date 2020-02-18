/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include <algorithm>
#include "../includes/scheduler_SRTF.h"


bool compareCpuTime(PCB a, PCB b){
	return a.remaining_cpu_time < b.remaining_cpu_time;
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort(){
	std::sort(ready_q[0].front(), ready_q[0].back(), compareCpuTime);
}
