#include "OGLReferenceFrame.h"
#include "MathUtil.h"

OGLReferenceFrame::OGLReferenceFrame() : orientation(1.0f)
{
}

OGLReferenceFrame::~OGLReferenceFrame()
{
}

void OGLReferenceFrame::setPosition(const glm::vec3& position)
{
	this->orientation[3] = glm::vec4(position, 1.0f);
}

void OGLReferenceFrame::setPosition(float x, float y, float z)
{
	this->orientation[3] = glm::vec4(x, y, z, 1.0f);
}

void OGLReferenceFrame::rotateZ(float degrees)
{
	float radians = DegToRad(degrees);

	float cosTheta = cosf(radians);
	float sinTheta = sinf(radians);

	glm::mat4 rotZMat(1.0f);
	rotZMat[0] = glm::vec4(cosTheta, sinTheta, 0.0f, 0.0f);
	rotZMat[1] = glm::vec4(-sinTheta, cosTheta, 0.0f, 0.0f);

	this->orientation *= rotZMat;
}

void OGLReferenceFrame::rotateY(float degrees)
{
	float radians = DegToRad(degrees);

	float cosTheta = cosf(radians);
	float sinTheta = sinf(radians);

	glm::mat4 rotYMat(1.0f);
	rotYMat[0] = glm::vec4(cosTheta, 0.0f, -sinTheta, 0.0f);
	rotYMat[2] = glm::vec4(sinTheta, 0.0f, cosTheta, 0.0f);

	this->orientation *= rotYMat;
}

void OGLReferenceFrame::rotateX(float degrees)
{
	float radians = DegToRad(degrees);

	float cosTheta = cosf(radians);
	float sinTheta = sinf(radians);

	glm::mat4 rotXMat(1.0f);
	rotXMat[1] = glm::vec4(0.0f, cosTheta, sinTheta, 0.0f);
	rotXMat[2] = glm::vec4(0.0f, -sinTheta, cosTheta, 0.0f);

	this->orientation *= rotXMat;
}

void OGLReferenceFrame::move(const glm::vec3& direction, float speed)
{
	glm::mat4 translateMat(0.0f);
	translateMat[3] = glm::vec4(direction * speed, 0.0f);

	this->orientation += translateMat;
}

void OGLReferenceFrame::moveForward(float speed)
{
	// The 3rd column is the z-axis
	this->move(glm::vec3(this->orientation[2]), speed);
}

void OGLReferenceFrame::ForwardRotate(float speed)
{
	// The 3rd column is the z-axis
	this->move(glm::vec3(this->orientation[2]), speed);
	this->rotateY(180);
}

void OGLReferenceFrame::BackwardRotate(float speed)
{
	// The 3rd column is the z-axis
	this->move(glm::vec3(this->orientation[2]), speed);
	this->rotateY(180);
}
void OGLReferenceFrame::moveBackward(float speed)
{
	// The 3rd column is the z-axis
	this->move(glm::vec3(-this->orientation[2]), speed);
}

void OGLReferenceFrame::moveLeft(float speed)
{
	// The 3rd column is the z-axis
	this->move(glm::vec3(this->orientation[0]), speed);
}

void OGLReferenceFrame::moveRight(float speed)
{
	// The 3rd column is the z-axis
	this->move(glm::vec3(-this->orientation[0]), speed);
}