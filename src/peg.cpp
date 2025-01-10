// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#include "peg.h"

//constructors
Peg::Peg(){}

Peg::Peg(int x, int y, int w, int h)
{
    mPegX = x;
    mPegY = y;
    mPegW = w;
    mPegH = h;
}

//draw function
void Peg::drawPeg(GWindow& gw)
{
    //center coordinates to bottom center
    int x = mPegX - mPegW/2;
    gw.setColor(mPegColor);

    //draw
    gw.fillRect(x, mPegY, mPegW, mPegH);

    //draw each peg on the disk
    int n = mPegDisks.size();
    for(int i = 0; i<n ; i++)
    {
        mPegDisks[i].drawDisk(gw);
    }
}

void Peg::addDisk(Disk& inDisk)
{
    //center each disk on the peg
    inDisk.setX(mPegX); 
    //put each disk on the bottom of each peg, count how many disks on peg to get the height
    //multiplied height by 1.2 to create a gap between disks for style points 
    inDisk.setY(mPegY+mPegH-mPegDisks.size()*inDisk.getHeight()*1.2);
    //add each disk to the peg vector
    mPegDisks.push_back(inDisk);
}

Disk Peg::removeDisk()
{
    //create a temp int to access the deleted index
    int val = mPegDisks.size()-1;
    //return value is disk to be removed
    Disk retval = mPegDisks[val];
    //delete top(smallest) disk
    mPegDisks.pop_back();
    //return deleted disk
    return retval;
}