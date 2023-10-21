#include "VectorTank.h"

using namespace std;
using namespace glm;


// From the stored position and rotation angle derive the matrices needed to perform the transformations
void VectorTank::calculateDerivedMatices(void) {

	T = translate(identity<mat4>(), vec3(pos.x, pos.y, 0.0f));
	R = glm::rotate(identity<mat4>(), tankTheta, vec3(0.0f, 0.0f, 1.0f));
	TR = T * R;

	mat4 S = scale(identity<mat4>(), vec3(1.0f, 1.0f, 1.0f));
}


VectorTank::VectorTank() {
}

// Initialise the tank variables and VBOs for rendering
void VectorTank::initialise(float tankX, float tankY, float tankTheta) {

	pos = vec2(tankX, tankY);
	tankTheta = tankTheta;

	localAxes.initialise(1.0f, 0.3f);

	calculateDerivedMatices();

	// Setup VAO and VBOs

	GLfloat vertexPos[] = {

		// Main body
		-0.1f, 0.05f,
		0.1f, 0.05f,
		0.1f, -0.05f,
		-0.1f, -0.05f,

		// Turret
		-0.05f, 0.04f,
		0.075f, 0.0f,
		-0.05f, -0.04f
	};

	GLfloat vertexColours[] = {

		// Main body
		0.2f, 0.8f, 0.2f,
		0.2f, 0.8f, 0.2f,
		0.2f, 0.8f, 0.2f,
		0.2f, 0.8f, 0.2f,

		// Turret
		0.2f, 0.8f, 0.2f,
		0.2f, 0.8f, 0.2f,
		0.2f, 0.8f, 0.2f
	};

	GLuint indices[] = {

		// Main body
		0, 1, 2, 3,

		// Turret
		4, 5, 6
	};

	// Setup VBO
	glGenBuffers(1, &tankPosVBO);
	glBindBuffer(GL_ARRAY_BUFFER, tankPosVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPos), vertexPos, GL_STATIC_DRAW);

	glGenBuffers(1, &tankColourVBO);
	glBindBuffer(GL_ARRAY_BUFFER, tankColourVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexColours), vertexColours, GL_STATIC_DRAW);
	
	glGenBuffers(1, &tankIndexVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, tankIndexVBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Unbind buffers once done
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

#pragma region Accessor methods

vec2 VectorTank::getPosition(void) {

	return pos;
}

float VectorTank::getAngleRadians(void) {

	return tankTheta;
}

float VectorTank::getAngleDegrees(void) {

	return tankTheta * (1.0f / glm::radians(1.0f));
}

mat4 VectorTank::getRotationMatrix(void) {

	return R;
}

mat4 VectorTank::getModelTransformMatrix(void) {

	return TR;
}


#pragma endregion


#pragma region Interaction methods

// Move forward (direction = 1) or backward (direction = -1)
void VectorTank::move(float direction, float tDelta) {

	pos += vec2(

		cosf(tankTheta) * direction * velocity * tDelta,
		sinf(tankTheta) * direction * velocity * tDelta
	);

	calculateDerivedMatices();
}

// Rotate by constant rate (30 degrees per second) in direction determined by direction = 1 (counter-clockwise - following convention) or -1 (clockwise)
void VectorTank::rotate(float direction, float tDelta) {

	tankTheta = std::fmodf(tankTheta + (glm::radians(1.0f) * 50.0f) * direction * tDelta, glm::pi<float>() * 2.0f);

	calculateDerivedMatices();
}

#pragma endregion


#pragma region Rendering methods

void VectorTank::render(mat4 currentTransform) {
	
	mat4 tankTransform = currentTransform * TR;
	
	// Apply transform for tank
	glLoadMatrixf((GLfloat*)&tankTransform);

	// Declare the data type of the array
	glBindBuffer(GL_ARRAY_BUFFER, tankPosVBO);
	glVertexPointer(2, GL_FLOAT, 0, (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER, tankColourVBO);
	glColorPointer(3, GL_FLOAT, 0, (GLvoid*)0);

	// Enable the relevant arrays
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	// Draw the axes
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, tankIndexVBO);
	glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_INT, (GLvoid*)0); // VBO bound so last parameter refers to start of VBO (0 offset)
	glDrawElements(GL_LINE_LOOP, 3, GL_UNSIGNED_INT, (GLvoid*)(sizeof(GLuint)<<2)); // last parameter offset into VBO

	// Unbind buffers once done
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// Render local axes to show local coordinate frame based on current rotation
	localAxes.render(tankTransform);
}

#pragma endregion

