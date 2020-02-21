/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/scheduler.h"

/**
 * Adds a new process to the ready_q or an old process that has already been
 * on the CPU and was preempted.
 * @param p - The process to add.
 */
void Scheduler::add(PCB p){
	ready_q->push(p);
	sort();
}

/**
 * Grabs the next process and removes it from the ready_q.
 * @return PCB - The next process on the ready_q.
 */
PCB Scheduler::getNext(){
	PCB nextProcess = ready_q->front();
	ready_q->pop();
	return nextProcess;
}

/**
 * Returns whether there are no more jobs left on the ready_q.
 * @return bool - Whether the ready_q has no more jobs left on the ready_q.
 */
bool Scheduler::isEmpty(){
	return ready_q->empty();
}

/**
 * Determines whether to switch processes on the CPU.
 * Based on the remaining time of a process or a complete time slice.
 * @param tick_count - Number of CPU ticks.
 * @param p - Process currently on the CPU.
 * @return bool - Whether to switch processes or not.
 */
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p){
	p.remaining_cpu_time = p.remaining_cpu_time - 1;
	if(p.remaining_cpu_time < 0){
		p.remaining_cpu_time = 0;
	}
	return p.remaining_cpu_time == 0;
}

/**
 * Sorts the ready_q based on the algorithm used.
 */
void Scheduler::sort(){
}
