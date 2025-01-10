// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#include "towers.h"

int promptForDisks()
{
    
    int input;
    //will prompt user until they enter a value in the corrct range
    do
    {
        std::cout<<"ENTER NUMBER OF DISKS (2-10):"<<std::endl;
        std::cin>>input;
    }
    while(input < 2 || input > 10);
    
    return input;
}

void promptForPegs(int& start, int& end)
{
    //prompts user for start and target peg
    do
    {
        std::cout<<"ENTER STARTING PEG(1-3):"<<std::endl;
        std::cin>> start;
    }
    while(start<1|| start>3);

    do
    {
        std::cout<<"ENTER ENDING PEG (1-3):"<<std::endl;
        std::cin>> end;
    }
    //makes sure that start cannot equal end
    while(end<1 || end>3 || start == end);
    //no return, start and end are accessed by reference and manipulated later
}

int promptForPause()
{
    int input;
    //repeats until user enters value within range
    do
    {
        std::cout<<"ENTER PAUSE LENGTH (<100000):"<<std::endl;
        std::cin>>input;
    }
    while(input < 0 || input > 100000);
    
    return input;
}

void promptForWindow(int& width, int& height)
{
    //prompt until range is satisfied
    do
    {
        std::cout<<"ENTER WINDOW WIDTH(800-4096):"<<std::endl;
        std::cin>> width;
    }
    while(width < 800 || width > 4096);

    do
    {
    std::cout<<"ENTER WINDOW HEIGHT (600-2160):"<<std::endl;
    std::cin>> height;    
    } 
    while (height < 600 ||height > 2160);
    //no return again, need to do arithmatic with height and width later

}

void draw(GWindow& gw, std::vector<Peg>& pegVector, int& start)
{
    //clear revious slide
    gw.clear();

    //draw all 3 pegs (will draw their disks)
    for(int i = 0; i < 3; i++)
    {
        pegVector[i].drawPeg(gw);
    }
}
    
void moveDisk(GWindow& gw, std::vector<Peg>& pegVector,int& start, int& end, int temppause)
{
    //initialize a disk and it from the starting peg
    Disk tempDisk = pegVector[start-1].removeDisk();
    //add the same disk to the end peg
    pegVector[end-1].addDisk(tempDisk);
    //draw the new configuration
    draw(gw, pegVector, start);
    //hold for x amount of time
    pause(temppause);
}

void towerSolver(GWindow& gw, std::vector<Peg>& pegVector,int& start, int& end, int temppause, int n)
{
    //continuously redefine the temp peg each time
    //start and end are all decremented by 1 in the previous functions so sub from 6 is correct
    int temp = 6 - start- end;

    //recursion
    if(n>0){
    //Transfer N−1 Disks from “start” to “temp”. This leaves Disk 0 alone on “start”
    towerSolver(gw, pegVector, start, temp, temppause, n-1);
    //Move Disk 0 from “start” to “end”
    moveDisk(gw, pegVector, start, end, temppause);
    //Transfer N−1 Disks from “temp” to “end” so they sit on Disk 0
    towerSolver(gw, pegVector, temp, end, temppause, n-1);
}
}

void towerRun(GWindow& gw, std::vector<Peg>& pegVector,int& start, int& end, int temppause, int diskNum)
{
    //open window (mac glitch thing)
    pause(500);

    //call recursion
    //diskNum becomes n
    towerSolver(gw, pegVector, start, end, temppause, diskNum);
    //let last slide sit
    pause(1000);
}
