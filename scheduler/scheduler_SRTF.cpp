/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include "../includes/scheduler_SRTF.h"

//this is a  preemptive scheduler, so set the preemptive member variable to true
//when calling the base class
Scheduler_SRTF::Scheduler_SRTF(std::queue<PCB> &queue):Scheduler(queue,true,UNINITIALIZED){
}

Scheduler_SRTF::~Scheduler_SRTF():~Scheduler(){
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort(){

}
