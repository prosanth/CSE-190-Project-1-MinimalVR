#include "MoleculeSystem.h"
#include "Window.h"

MoleculeSystem::MoleculeSystem()
{
	co2 = new Model("../assets/co2/co2.obj");
	o2 = new Model("../assets/o2/o2.obj");
}

MoleculeSystem::~MoleculeSystem()
{
	for (Molecule * m : molecules) {
		delete(m);
	}

	delete(co2);
	delete(o2);
}

void MoleculeSystem::drawParticles(float time, GLuint shaderProgram)
{
	//std::cout << molecules.size() << std::endl;
	for (Molecule * m : molecules) {
		m->draw(time, shaderProgram);
	}
}

bool MoleculeSystem::spawnMolecule()
{
	if (!gameOver) {
		molecules.push_back(new Molecule(co2, false));
		particleCount++;
	}

	if (particleCount > 10) {
		gameOver = true;
		molecules.clear();
		for (int i = 0; i < 100; i++) {
			molecules.push_back(new Molecule(co2, true));
		}

		particleCount = 0;
	}

	return gameOver;
}

void MoleculeSystem::removeMolecule()
{
}