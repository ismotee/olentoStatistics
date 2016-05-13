//
//  oDirectory.h
//  opengltest
//
//  Created by Ismo Torvinen on 28.3.2016.
//  Copyright (c) 2016 Ismo Torvinen. All rights reserved.
//

#ifndef opengltest_oDirectory_h
#define opengltest_oDirectory_h

#include <vector>


#ifdef __APPLE__
#include <dirent.h>
#else
#include "direntwin.h"
#endif


#include <string.h>
#include <stdio.h>
#include <iostream>

class oDirectory {
public:
    std::string path;
    std::vector<std::string> files;
    //std::vector<oDirectory> directories;
    
    oDirectory (std::string path);
    
    

};


#endif
