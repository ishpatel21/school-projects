#include "OGLTexturedFlatSurface.h"
#include "ObjectGenerator.h"

OGLTexturedFlatSurface::OGLTexturedFlatSurface(
	const string& name,
	float width, float height,
	unsigned int numberOfWidthSegments, unsigned int numberOfDepthSegments,
	RGBA surfaceColor) : OGL3DObject(name)
{
	this->width = width;
	this->height = height;
	this->numberOfDepthSegments = numberOfDepthSegments;
	this->numberOfWidthSegments = numberOfWidthSegments;
	this->surfaceColor = surfaceColor;
	this->generate();
}

OGLTexturedFlatSurface::~OGLTexturedFlatSurface()
{
}

void OGLTexturedFlatSurface::generate()
{
	this->setIndexedArrayType();
	ElementArray arr = ObjectGenerator::generateTextureFlatSurface(
		this->numberOfWidthSegments, 
		this->numberOfDepthSegments, 
		this->width, 
		this->height,
		this->surfaceColor
	);
	this->setVertexData(arr.vertexData);
	this->setIndexData(arr.indexData);
	VBOObject* vboObject = OGLObject::createTextureVBOObject(
		"triangles", arr.vertexData, arr.indexData, GL_TRIANGLES);
	this->addVBOObject(vboObject);
}
