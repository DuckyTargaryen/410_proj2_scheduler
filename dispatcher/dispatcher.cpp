/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/dispatcher.h"

//Initializes the cpu pointer and sets the cpu to idle
Dispatcher::Dispatcher(CPU &cpu):cpu(&cpu),is_valid_job_on_cpu(false){

}

//Destructor: dereferences the cpu pointer
Dispatcher::~Dispatcher(){
	if(cpu)
		delete[] cpu;
}

//pull current process (if any) off CPU and return it
//if nothing on CPU returns an uninitialized PCB
PCB Dispatcher::get_from_CPU(){
	PCB currJob = cpu->get_process_off_core();
	if(currJob.process_number == UNINITIALIZED){
		is_valid_job_on_cpu = false;
	}
	return currJob;
}

//place the current process on the CPU for execution
void Dispatcher::put_on_CPU(PCB &process){
	cpu->put_process_on_core(process);
	is_valid_job_on_cpu = true;
}

//is CPU idle or working
bool Dispatcher::isValidJobOnCPU(){
	return is_valid_job_on_cpu;
}
