#pragma once

#include "core.h"
#include "PrincipleAxes.h"

class VectorTank {

	// Tank position
	glm::vec2			pos = glm::vec2(0.0f, 0.0f);

	// Tank velocity (scalar value - we'll use orientation to determine direction)
	// Distance per-second (constant for this demo)
	const float		velocity = 0.4f;

	// Tank orientation (in radians)
	float			tankTheta = 0.0f;

	// Vertex buffer object IDs
	GLuint			tankPosVBO = 0;
	GLuint			tankColourVBO = 0;
	GLuint			tankIndexVBO = 0;

	// Render axes - used to show local coordinate frame
	PrincipleAxes	localAxes = PrincipleAxes();


	// Derived values - matrices based on position and orientation - updated when tank moved or rotated
	glm::mat4		T, R, TR; // T (translation); R (rotation)


	// Private API

	void calculateDerivedMatices(void);


	// Public methods

public:

	VectorTank();
	void initialise(float tankX, float tankY, float tankTheta);

	// Accessor methods

	glm::vec2 getPosition(void);

	float getAngleRadians(void);

	float getAngleDegrees(void);

	glm::mat4 getRotationMatrix(void);

	glm::mat4 getModelTransformMatrix(void);


	// Interaction methods

	// Move forward (direction = 1) or backward (direction = -1)
	void move(float direction, float tDelta);

	// Rotate by constant rate (30 degrees per second) in direction determined by direction = 1 (counter-clockwise - following convention) or -1 (clockwise)
	void rotate(float direction, float tDelta);


	// Rendering methods

	void render(void);
};