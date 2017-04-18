#ifndef _MOLECULESYSTEM_H_
#define _MOLECULESYSTEM_H_

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
#include <vector>
#include "Molecule.h"
#include "Model.h"

class MoleculeSystem
{
public:
	MoleculeSystem();
	~MoleculeSystem();

	int particleCount = 0;

	std::vector<Molecule *> molecules;
	
	Model * co2;
	Model * o2;

	bool gameOver = false;

	void drawParticles(float time, GLuint shaderProgram);
	bool spawnMolecule();
	void removeMolecule();
};
#endif
