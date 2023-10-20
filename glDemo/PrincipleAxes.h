#pragma once

#include "core.h"

class PrincipleAxes {

	GLuint		posVBO = 0;
	GLuint		coloursVBO = 0;
	GLuint		indicesVBO = 0;

	float		lineWidth = 1.0f;
	bool		enableStipple = false;
	GLushort	stipplePattern = 0xFFFF;

public:

	PrincipleAxes();
	void initialise(float lineWidth = 1.0f, float lineLength = 1.0f, bool enableStipple = false, GLushort stipplePattern = 0xFFFF);

	void render();
};
