#ifndef _MOLECULE_H_
#define _MOLECULE_H_

#define GLFW_INCLUDE_GLEXT
#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#else
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>
// Use of degrees is deprecated. Use radians instead.
#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Model.h"

class Molecule
{
public:
	Molecule(Model * model, bool over);
	~Molecule();

	bool over;

	glm::mat4 toWorld;
	glm::mat4 rotate;
	//Cube * cube;
	Model * model;

	glm::vec3 position;
	glm::vec3 velocity;
	glm::vec3 spinAxis;
	float spinAmount;

	void draw(float time, GLuint shaderProgram);
	void updatePosition(float time);
	void spin();
	float RandomNumber(float Min, float Max);

	// These variables are needed for the shader program
	GLuint VBO, VAO, EBO;
	GLuint uProjection, uModelview;
};
#endif