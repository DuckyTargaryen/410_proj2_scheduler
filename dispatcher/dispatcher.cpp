/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/dispatcher.h"

/**
 * Pulls a process off the CPU and returns it.
 * If nothing is on the CPU, it returns an uninitialized PCB.
 * @return PCB - The process on the CPU or the uninitialized process.
 */
PCB Dispatcher::get_from_CPU(){
	PCB currJob = cpu->get_process_off_core();
	return currJob;
}

/**
 * Puts a process on the CPU.
 * @param process - The process being placed on the CPU.
 */
void Dispatcher::put_on_CPU(PCB &process){
	cpu->put_process_on_core(process);
}

/**
 * Determines if the CPU is idle or is currently running a process.
 * @return bool - Whether the CPU is running a process or not.
 */
bool Dispatcher::isValidJobOnCPU(){
	PCB currJob = cpu->get_COPY_of_Current_Process();
	if(currJob.isEmpty()){
		is_valid_job_on_cpu = false;
	}
	else{
		is_valid_job_on_cpu = true;
	}
	return is_valid_job_on_cpu;
}
