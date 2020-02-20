/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/scheduler.h"

//add a process, either a new one or one that
//had been running on the CPU and has been preempted
void Scheduler::add(PCB p){
	ready_q->push(p);
	sort();
}

//get next process
PCB Scheduler::getNext(){
	PCB nextProcess = ready_q->front();
	ready_q->pop();
	return nextProcess;
}

//returns true if there are no  jobs in the readyQ
//false otherwise
bool Scheduler::isEmpty(){
	return ready_q->empty();
}

//if process has completed (used all its remaining_cpu_time) or
//if we are using a preemptive scheduling algorithm and the
//timeslice is over then its time to switch processes
//returns:
//true - switch processes
//false - do not switch
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p){
	/*if(preemptive){
		p.remaining_cpu_time = p.remaining_cpu_time - 1;
		if(p.remaining_cpu_time < 0){
			p.remaining_cpu_time = 0;
		}
		//ready_q->pop();
		return (tick_count % time_slice) == 0;
	}
	else{
		p.remaining_cpu_time = p.remaining_cpu_time - 1;
		if(p.remaining_cpu_time < 0){
			p.remaining_cpu_time = 0;
		}
		//ready_q->pop();
		return p.remaining_cpu_time == 0;
	}*/
}

// sort  ready_q based on the scheduler algorithm used whenever add(PCB p) is called
void Scheduler::sort(){

}
