// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#pragma once
#include <string>
#include "gwindow.h"
#include <error.h> 
#include <gevent.h>
#include <vector>
#include <string>
#include <random>
#include <cstdlib>

class Disk
{
    private:
        int mDiskX;
        int mDiskY;
        int mDiskH;
        int mDiskW;
        
        const std::string mDiskColor = "RED";

    public:
        Disk();
        Disk(int x, int y, int h, int w);
        void setX(int x);
        void setY(int y);
        int getHeight();
        void drawDisk(GWindow& gw);
        };