/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include <string.h>
#include "../includes/stats.h"

/**
 * Constructor: Initializes the finished vector and the stat variables.
 * Also calls calcStats() to calculate the stats.
 * @param finished_vector - The vector containing all of the finished processes.
 */
Stats::Stats(std::vector<PCB> &finished_vector){
	vec = &finished_vector;
	av_wait_time = 0;
	av_turnaround_time = 0;
	av_response_time = 0;
	calcStats();
}

/**
 * Loops through the finished vector and prints the information
 * for each finished processes.
 */
void Stats::showAllProcessInfo(){
	int finVecSize = vec->size();
	for(int i = 0; i < finVecSize; i++){
		std::cout << "Process ";
		std::cout << (*vec)[i].process_number;
		std::cout << " Required CPU time:";
		std::cout << (*vec)[i].required_cpu_time;
		std::cout << " arrived:";
		std::cout << (*vec)[i].arrival_time;
		std::cout << " started:";
		std::cout << (*vec)[i].start_time;
		std::cout << " finished:";
		std::cout << (*vec)[i].finish_time << std::endl;
	}
}

/**
 * Gets the average time for a process to be placed on the CPU once it is on the ready_q.
 * @return float - The average response time.
 */
float Stats::get_av_response_time(){
	return av_response_time;
}

/**
 * Gets the average time for a process to be completed once it is on the ready_q.
 * @return float - The average turnaround time.
 */
float Stats::get_av_turnaround_time(){
	return av_turnaround_time;
}

/**
 * Determines how much time a process spends waiting for processor time when on the ready_q.
 * @return float - The average wait time.
 */
float Stats::get_av_wait_time(){
	return av_wait_time;
}

/**
 * Calculates the statistics of the job that ran on the processor.
 */
void Stats::calcStats(){
	int totalNumProcess = 0;
	int finVecSize = vec->size();
	for(int i = 0; i < finVecSize; i++){
		av_response_time += (*vec)[i].start_time - (*vec)[i].arrival_time;
		av_turnaround_time += (*vec)[i].finish_time - (*vec)[i].arrival_time;
		av_wait_time += ((*vec)[i].finish_time - (*vec)[i].arrival_time) - (*vec)[i].required_cpu_time;
		totalNumProcess = totalNumProcess + 1;
	}
	av_response_time = av_response_time/totalNumProcess;
	av_turnaround_time = av_turnaround_time/totalNumProcess;
	av_wait_time = av_wait_time/totalNumProcess;
}
