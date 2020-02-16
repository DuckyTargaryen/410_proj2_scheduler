/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector){
	vec = &finished_vector;
	av_wait_time = UNINITIALIZED;
	av_turnaround_time = UNINITIALIZED;
	av_response_time = UNINITIALIZED;
}

Stats::~Stats(){
	if(vec)
		delete[] vec;
}

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo(){

}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_response_time(){
	return av_response_time;
}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time(){
	return av_turnaround_time;
}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time(){
	return av_wait_time;
}

//does the work (only needs to run once)
void Stats::calcStats(){
	int totalNumProcess = 0;
	for(int i = 0; i < vec[0].size(); i++){
		av_response_time += vec[0][i].start_time - vec[0][i].arrival_time;
		av_turnaround_time += vec[0][i].finish_time - vec[0][i].arrival_time;
		av_wait_time += vec[0][i].finish_time - vec[0][i].arrival_time - vec[0][i].remaining_cpu_time;
		totalNumProcess++;
	}
	av_response_time = av_response_time/totalNumProcess;
	av_turnaround_time = av_turnaround_time/totalNumProcess;
	av_wait_time = av_wait_time/totalNumProcess;
}
