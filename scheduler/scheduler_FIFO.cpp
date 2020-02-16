/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */
#include "../includes/scheduler_FIFO.h"

//this is a non - preemptive scheduler, set the preemptive member variable to false
//when calling the base class
Scheduler_FIFO::Scheduler_FIFO(std::queue<PCB> &queue):Scheduler(queue,false,UNINITIALIZED){;
}

Scheduler_FIFO::~Scheduler_FIFO():~Scheduler(){
}

