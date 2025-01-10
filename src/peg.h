// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#pragma once
#include <vector>
#include <string>
#include "disk.h"

class Peg{
    private:
        std::vector<Disk> mPegDisks;
        int mPegX;
        int mPegY;
        int mPegW;
        int mPegH;
        const std::string mPegColor = "BLACK";

    public:
        Peg();
        Peg(int x, int y, int w, int h);
        void drawPeg(GWindow& gw);
        void addDisk(Disk& inDisk);
        Disk removeDisk();
};