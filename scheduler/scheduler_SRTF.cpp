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

/**
 * Used to sort the ready_q. Helps compare the processes by their remaining time.
 * @param a - A process in the queue.
 * @param b - A process in the queue.
 * @return bool - Whether process a has more remaining time then process b.
 */
bool compareCpuTime(PCB a, PCB b){
	return a.remaining_cpu_time > b.remaining_cpu_time;
}

/**
 * Determines if it is time to switch processes on the CPU based on SRTF.
 * @param tick_count - Number of CPU ticks.
 * @param p - The current process on the CPU.
 * @return bool - Whether or not to switch processes.
 */
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
	sort();
	if(p.remaining_cpu_time <= 0){
		p.remaining_cpu_time = 0;
		return (p.remaining_cpu_time == 0);
	}
	return (!ready_q->empty()) && (p.remaining_cpu_time > ready_q->front().remaining_cpu_time);
}

/**
 * SRTF-preemptive
 * Sorts the ready_q whenever add(PCB p) or time_to_switch_processes is called.
 */
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
