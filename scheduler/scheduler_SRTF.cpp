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
#include <vector>
#include "../includes/scheduler_SRTF.h"


bool compareCpuTime(PCB a, PCB b){
	return a.remaining_cpu_time < b.remaining_cpu_time;
}

bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
	if(preemptive){
		sort();
		return tick_count == time_slice;
	}
	else{
		sort();
		return tick_count == p.finish_time;
	}
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort(){
	std::vector<PCB> pcbVector;
	while(!ready_q->empty()){
		pcbVector.push_back(ready_q[0].front());
		ready_q->pop();
	}
	std::sort(pcbVector.begin(), pcbVector.end(), compareCpuTime);
	while(!pcbVector.empty()){
		ready_q->push(pcbVector.back());
		pcbVector.pop_back();
	}
}
