//
//  oMesh.h
//  opengltest
//
//  Created by Ismo Torvinen on 27.3.2016.
//  Copyright (c) 2016 Ismo Torvinen. All rights reserved.
//

#ifndef opengltest_oMesh_h
#define opengltest_oMesh_h

#include "glm/glm.hpp"
#include "oLoader.h"
#include <vector>
#include <iostream>

#endif

class oMesh : public oLoader {
public:
    
    std::vector<glm::vec3> vertices;

    oMesh (std::string path);
    oMesh (int size);
    
    oMesh& operator-=(const oMesh& rhs)
    {
        std::cout << "rhs: " << rhs.vertices.size() << " target: " << vertices.size() << "\n";
        for(int i = 0; i < rhs.vertices.size();i++){
            vertices[i] = vertices[i] - rhs.vertices[i];
        }
        
        return *this; // return the result by reference
    }

};



