// Copyright (c) 2024 Nathan Greenfield. All rights reserved
#include <iostream>
#include "gwindow.h"
#include <vector>
#include "disk.h"
#include "peg.h"
#pragma once


int promptForDisks();

void promptForPegs(int& start, int& end);

int promptForPause();

void promptForWindow(int& width, int& height);

void draw(GWindow& gw, std::vector<Peg>& pegVector, int& start);

void moveDisk(GWindow& gw, std::vector<Peg>& pegVector,int& start, int& end, int pause);

void towerSolver(GWindow& gw, std::vector<Peg>& pegVector,int& start, int& end, int temppause, int diskNum);

void towerRun(GWindow& gw, std::vector<Peg>& pegVector,int& start, int& end, int pause, int diskNum);


//where do I create the pegs and the vector of the pegs
//how where do create n disks based on the user input
//what is the purpose of get height
//where do we do the arithmatic to plot objects in the animation
//what do you mean by label the pegs start, temp and end?
