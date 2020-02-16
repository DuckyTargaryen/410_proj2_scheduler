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

//this is a preemptive scheduler,set the preemptive member variable to true
//when calling the base class
Scheduler_RR::Scheduler_RR(queue<PCB> &queue, int time_slice):Scheduler(queue,true,time_slice){
}

Scheduler_RR::~Scheduler_RR():~Scheduler(){
}
