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
		return tick_count == time_slice;
	}
	else{
		return tick_count == p.finish_time;
	}
}

void Scheduler_RR::sort(){
}
