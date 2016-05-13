//
//  oModificators.h
//  opengltest
//
//  Created by Ismo Torvinen on 8.4.2016.
//  Copyright (c) 2016 Ismo Torvinen. All rights reserved.
//

#ifndef opengltest_oModificators_h
#define opengltest_oModificators_h

#include <vector>

#include "oMeshBundle.h"
#include "glm/glm.hpp"
#include "oDirectory.h"
#include <iostream>

struct oModificators {
    oMeshBundle* archtypes;
    std::vector<oMeshBundle> mods;
    
    oModificators();
    void initialize(std::string path, std::string _archtype, std::vector<std::string> modificators);
    
    std::vector<glm::vec3> getShape(std::vector<float>& values);
    
    //making easier and more intuitive to get data from mods vector
    oMeshBundle& operator[](std::size_t idx)       { return mods[idx]; };
    const oMeshBundle& operator[](std::size_t idx) const { return mods[idx]; };
    
};


#endif
