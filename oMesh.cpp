#include "oMesh.h"

oMesh::oMesh(int size) {
    vertices.resize(size);


}

oMesh::oMesh (std::string path)
{
    oLoader::loadOBJ(path,vertices);
}
