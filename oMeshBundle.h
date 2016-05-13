//
//  oMeshBundle.h
//  opengltest
//
//  Created by Ismo Torvinen on 27.3.2016.
//  Copyright (c) 2016 Ismo Torvinen. All rights reserved.
//

#ifndef opengltest_oMeshBundle_h
#define opengltest_oMeshBundle_h

#include "glm/glm.hpp"
#include <vector>
#include "oMesh.h"
#include "oDirectory.h"


class oMeshBundle {
public:
    std::vector<oMesh> meshes;
    
    oMeshBundle(oDirectory& dir);
    oMeshBundle(oDirectory& dir, oMeshBundle& archtypes);
    
    std::vector<glm::vec3> getShape(float value);
    std::vector<glm::vec3> getShape(float a_value,float m_value);
    
    //making easier and more intuitive to get data from vector
    oMesh& operator[](std::size_t idx)       { return meshes[idx]; };
    const oMesh& operator[](std::size_t idx) const { return meshes[idx]; };

};


#endif
