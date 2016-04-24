#include "dobject.h"

void dFacesConnected::addFace(unsigned int Id) {
	faceIds.push_back(Id);
}


dFacesConnected::dFacesConnected(){}


dFacesConnected::dFacesConnected(unsigned int vertexId,
	std::vector<unsigned int> elements,
	std::vector<dFace>& faces,
	std::vector<glm::vec3> normals) {
	
	// get references from faces by elements and vertexId
	for (int i = 0; i < elements.size(); i++) {
		if (elements[i] == vertexId) {
			faceIds.push_back(i / 3);
		}
	}
}


glm::vec3 dFacesConnected::calculateVertexNormal(std::vector<dFace>& allFaces) {
	glm::vec3 sum = glm::vec3(0, 0, 0);

	for (int i = 0; i < faceIds.size(); i++)
		sum += allFaces[faceIds[i]].faceNormal;

	return glm::normalize(sum);
}



dObject::dObject(std::string path)

{
	dClock c;
	oLoader::loadOBJ(path, vertices, elements, faces);
	normals = vertices;
	std::cout << "took " << c.get() << " s\n";

	//makeFaces();

	//M��rit� facejen sijainnit avaruudessa
	for (int i = 0; i < faces.size(); i++) {
		glm::vec3 facePosition = (1.0f / 3)*vertices[faces[i].vertsIds[0]] + (1.0f / 3)*vertices[faces[i].vertsIds[1]] + (1.0f / 3)*vertices[faces[i].vertsIds[2]];
		facePositions.push_back(facePosition);
	}

	makeFacesConnected();

	calculateAllNormals();

}


dObject::dObject(std::vector<glm::vec3> _vertices, std::vector<unsigned int> _elements) :
vertices(_vertices),
normals(_vertices),
elements(_elements)

{
	makeFaces();
	makeFacesConnected();

	calculateAllNormals();

}

void dObject::changeVertices(std::vector<glm::vec3>& new_vertices)
{
	vertices = new_vertices;
	calculateAllNormals();
}

void dObject::makeFaces() //t�t� pit�isi optimoida!
{
	dClock c;
	std::cout << "makeFaces...";

	for (std::vector<unsigned int>::iterator it = elements.begin();
		it != elements.end();
		it += 3) {

		std::vector<unsigned int> ids(it, it + 3);
		faces.push_back(dFace(ids));

		//Facen keskipisteen sijainti avaruudessa:
		glm::vec3 facePosition = (1.0f / 3)*vertices[ids[0]] + (1.0f / 3)*vertices[ids[1]] + (1.0f / 3)*vertices[ids[2]];
		facePositions.push_back(facePosition);

	}

	std::cout << " ok (" << c.get() << " s)\n";
}

void dObject::makeFacesConnected()
{
	dClock c;

	std::cout << "makeFacesConnected... ";
	vFacesConnected.resize(vertices.size());

	for (int i = 0; i < elements.size(); i++) {
		vFacesConnected[elements[i]].addFace(i / 3);
	}
	std::cout << "ok (" << c.get() << " s)\n";
}


void dObject::calculateAllNormals()
{
	//std::cout << "calculateAllNormals: vFacesConnected.size = " << vFacesConnected.size() << "\n";
	dClock c;
	for (int i = 0; i < faces.size(); i++) {
		faces[i].calculateFaceNormal(vertices);
	}

	//std::cout << "face normals done (took "<< c.get() <<" s)\n";
	c.reset();
	for (int i = 0; i < vFacesConnected.size() && i < normals.size(); i++) {
		normals[i] = vFacesConnected[i].calculateVertexNormal(faces);
	}

	//std::cout << "vertex normals done (took " << c.get() << " s)\n";
}

void dObject::changeVerticesTowards(std::vector<glm::vec3>& aim_vertices, float multi)
{
	if (multi > 1) multi = 1;
	if (multi < 0) multi = 0;

	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i] = glm::mix(vertices[i], aim_vertices[i], multi);
	}
}


void dObject::sortElementsByDistance(glm::vec3 cameraPos) {
	cameraPosition = cameraPos;
	sortElementsByDistance();
}


struct sortT{
	int value;
	float key;
};


bool compare(sortT l, sortT r) {
	if (l.key > r.key) return true;
	else return false;
}


void dObject::sortElementsByDistance() {

	dClock t;

	//J�rjest� facet v�liaikaiseen vektoriin siten ett� l�hin on ensin
	std::vector<sortT> sortedFaces;
	sortedFaces.resize(faces.size());

	for (int i = 0; i < faces.size(); i++) {

		sortedFaces[i].value = i;
		sortedFaces[i].key = length(facePositions[i] - cameraPosition);
	}
	std::sort(sortedFaces.begin(), sortedFaces.end(), compare);

	//j�rjest� sitten elementit: L�hin face on viimeisen�. Kun piirret��n, aloitetaan siis kauimmasta.
	for (int f_i = 0; f_i < sortedFaces.size(); f_i++) {
		int e_i = f_i * 3;
		elements[e_i] = faces[sortedFaces[f_i].value].vertsIds[0];
		elements[e_i + 1] = faces[sortedFaces[f_i].value].vertsIds[1];
		elements[e_i + 2] = faces[sortedFaces[f_i].value].vertsIds[2];
	}

	std::cout << "ok (" << t.get() << " s)\n";

}
