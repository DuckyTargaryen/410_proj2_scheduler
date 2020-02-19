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

using namespace std;


bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p){
	if(preemptive){
		p.remaining_cpu_time = p.remaining_cpu_time - 1;
		if(p.remaining_cpu_time < 0){
			p.remaining_cpu_time = 0;
		}
		//ready_q->pop();
		//std::cout << p.remaining_cpu_time << std::endl;
		return (tick_count % time_slice) == 0;
	}
	else{
		p.remaining_cpu_time--;
		if(p.remaining_cpu_time < 0){
			p.remaining_cpu_time = 0;
		}
		//ready_q->pop();
		return p.remaining_cpu_time == 0;
	}
}

void Scheduler_RR::sort(){
}
