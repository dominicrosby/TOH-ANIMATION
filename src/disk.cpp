// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#include "disk.h"

//constructors
Disk::Disk(){}

Disk::Disk(int x, int y, int w, int h) 
{
    mDiskX = x;
    mDiskY = y;
    mDiskW = w;
    mDiskH = h;
}

//getters & setters
void Disk::setX(int x)
{
    mDiskX = x;
}

void Disk::setY(int y)
{
    mDiskY = y;
}

int Disk::getHeight()
{
    return mDiskH;
}

//draw function
void Disk::drawDisk(GWindow& gw)
{   
    int x, y;
    //adjust x and y to be at the bottom center
    x = mDiskX - mDiskW/2;
    y = mDiskY - mDiskH;
    
    //set to red
    gw.setColor(mDiskColor);

    //couldn't get this to work unforturnately, would change each color every frame
    //would ove to find out how to fix it
    std::vector<std::string>colorVector = 
    {"BLACK", "BLUE", "CYAN", "GREEN","MAGENTA", "ORANGE", "PINK", "RED", "YELLOW"};
    int upper = colorVector.size() - 1;
    int colorIndex = rand() % upper;
    //gw.setColor(colorVector[colorIndex]);
    
    //draw the disk
    gw.fillRect(x, y, mDiskW, mDiskH);
}