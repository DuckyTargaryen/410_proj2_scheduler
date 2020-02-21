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
	return a.remaining_cpu_time > b.remaining_cpu_time;
}

bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
	//p.remaining_cpu_time = p.remaining_cpu_time - 1;
	sort();
	if(p.remaining_cpu_time <= 0){
		p.remaining_cpu_time = 0;
		return (p.remaining_cpu_time == 0);
	}
		//ready_q->pop();
	return (!ready_q->empty()) && (p.remaining_cpu_time > ready_q->front().remaining_cpu_time);
	/*else{
		p.remaining_cpu_time = p.remaining_cpu_time - 1;
		if(p.remaining_cpu_time < 0){
			p.remaining_cpu_time = 0;
		}
		//ready_q->pop();
		sort();
		return p.remaining_cpu_time == 0;
	}*/
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
