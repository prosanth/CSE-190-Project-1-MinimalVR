#include "Molecule.h"
#include "Window.h"

Molecule::Molecule(Model * model, bool over)
{
	this->model = model;
	this->over = over;
	toWorld = glm::mat4(1.0f);

	if (!over) {
		position = glm::vec3(0.0f, 1.0f, 0.0f);
		velocity = glm::vec3(RandomNumber(-1.0f, 1.0f) + 0.05f, RandomNumber(0.0f, 1.0f) + 0.05f, 0.0f);

		spinAmount = (float)(RandomNumber(-1.0f, 1.0f));
		spinAxis = glm::vec3(RandomNumber(-1.0f, 1.0f), RandomNumber(-1.0f, 1.0f), RandomNumber(-1.0f, 1.0f));
	}
	else {
		position = glm::vec3(RandomNumber(-20.0f, 20.0f), RandomNumber(-20.0f, 20.0f), RandomNumber(-20.0f, 20.0f));
		velocity = glm::vec3(0.0f, 0.0f, 0.0f);
		spinAmount = 0.0f;
		spinAxis = glm::vec3(0.0f, 0.0f, 0.0f);
	}

	// If you haven't figured it out from the last project, this is how you fix spin's behavior
	toWorld = toWorld * glm::rotate(glm::mat4(1.0f), -90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	toWorld = toWorld * glm::translate(glm::mat4(1.0f), position);
}

Molecule::~Molecule()
{
}

void Molecule::draw(float time, GLuint shaderProgram)
{
	if (!over) {
		updatePosition(time);
		spin();
	}

	model->Draw(toWorld, shaderProgram);
}

void Molecule::updatePosition(float time)
{
	// x_new = x_old + vt
	position = position + (time * velocity);
	toWorld = glm::mat4(1.0f);
	toWorld = toWorld * glm::translate(glm::mat4(1.0f), position) * rotate;
	if (position.x > 3.0f || position.x < -3.0f) {
		velocity.x = -velocity.x;
		if (position.x > 3.0f) {
			position.x = 3.0f;
		}
		else {
			position.x = -3.0f;
		}
	}

	if (position.y > 3.0f || position.y < -3.0f) {
		velocity.y = -velocity.y;
		if (position.y > 3.0f) {
			position.y = 3.0f;
		}
		else {
			position.y = -3.0f;
		}
	}

	if (position.z > 3.0f || position.z < -3.0f) {
		velocity.z = -velocity.z;
		if (position.z > 3.0f) {
			position.z = 3.0f;
		}
		else {
			position.z = -3.0f;
		}
	}
	std::cout << position.x << " " << position.y << " " << position.z << std::endl;
}

void Molecule::spin()
{
	// If you haven't figured it out from the last project, this is how you fix spin's behavior
	rotate = rotate * glm::rotate(glm::mat4(1.0f), spinAmount / 180.0f * glm::pi<float>(), spinAxis);
}

float Molecule::RandomNumber(float Min, float Max)
{
	return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}