#pragma once
#ifndef UNIFORM
#define UNIFORM

enum UniformDataType {
	Integer, Float, FloatArray, Matrix4, Vector3, Vector3Array, Vector4,
	Sampler2D
};

struct Uniform {
	unsigned int location;
	UniformDataType type;
	void *data;
};

#endif
