
#include "PrincipleAxes.h"

using namespace std;
using namespace glm;


PrincipleAxes::PrincipleAxes() {
}

void PrincipleAxes::initialise(float lineWidth, float lineLength, bool enableStipple, GLushort stipplePattern) {

	float pos[] = {
		0.0f, 0.0f,
		lineLength, 0.0f,
		0.0f, 0.0f,
		0.0f, lineLength
	};

	GLubyte colours[] = {

		255, 0, 0,
		255, 0, 0,
		0, 255, 0,
		0, 255, 0
	};

	GLubyte indices[] = {
		0, 1,
		2, 3
	};

	glGenBuffers(1, &posVBO);
	glBindBuffer(GL_ARRAY_BUFFER, posVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(pos), pos, GL_STATIC_DRAW);

	glGenBuffers(1, &coloursVBO);
	glBindBuffer(GL_ARRAY_BUFFER, coloursVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colours), colours, GL_STATIC_DRAW);

	glGenBuffers(1, &indicesVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesVBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Unbind buffers once done
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	// Setup line rendering properties
	this->lineWidth = lineWidth;
	this->enableStipple = enableStipple;
	this->stipplePattern = stipplePattern;
}

void PrincipleAxes::render(mat4 currentTransform) {

	// Enable line rendering state
	glLineWidth(lineWidth);

	if (enableStipple) {

		glEnable(GL_LINE_STIPPLE);
		glLineStipple(1, stipplePattern);
	}
	
	
	// Declare the data type of the array
	glBindBuffer(GL_ARRAY_BUFFER, posVBO);
	glVertexPointer(2, GL_FLOAT, 0, (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER, coloursVBO);
	glColorPointer(3, GL_UNSIGNED_BYTE, 0, (GLvoid*)0);

	// Enable the relevant arrays
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	// Draw the axes
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesVBO);

	glLoadMatrixf((GLfloat*)&currentTransform);
	glDrawElements(GL_LINES, 4, GL_UNSIGNED_BYTE, (GLvoid*)0);

	// Unbind buffers once done
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// Reset OpenGL state
	if (enableStipple) {

		glDisable(GL_LINE_STIPPLE);
	}
}