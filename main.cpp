// Copyright (c) 2024 Nathan Greenfield. All rights reserved
#include "towers.h"
#include "disk.h"
#include <iostream>
#include "gwindow.h"
#include "peg.h"

int main(){
    //couldn't find a way to clean up main without getting some bugs
    
    //peg prompt
    int start, end;
    promptForPegs(start, end);
    
    //disk prompt
    int n = promptForDisks();
    int temppause = promptForPause();
    
    //window prompt
    int width, height;
    promptForWindow(width, height);
    //create window
    GWindow gw(width, height);

    //create vector of pegs
    std::vector<Peg> pegVector;
    //manually did math for even peg spacing based on window size
    pegVector.push_back(Peg(width/4-width/16, 5*height/60, width/40, 5*height/6));
    pegVector.push_back(Peg(width/2, 5*height/60, width/40, 5*height/6));
    pegVector.push_back(Peg(3*width/4+width/16, 5*height/60, width/40, 5*height/6));

    //add disks to starting peg
    for(int i = 0; i < n; i++)
    {
        //tempDisk x and y are irrelevant (addDisk redefines them)
        //width and height of disks adjust to window size
        Disk tempDisk(150, 300, width/4-i*width/40, 2*height/30);
        int x = i%2;
        if(x == 0)
        {
            gw.setColor("CYAN");
        }
        else
        {
            gw.setColor("YELLOW");
        }
        //add all disks before starting to solve
        pegVector[start-1].addDisk(tempDisk);
    }

        //draw first frame and pause
    draw(gw, pegVector, start);
    pause(temppause);
    //call full recursive solution
    towerRun(gw, pegVector, start, end, temppause, n);
    
    return 0;
}
	