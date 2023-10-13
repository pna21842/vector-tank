#include "semi-circle-vertexarray.h"

//
// Packed arrays for modelling semi-circle position and colour data
//

static GLfloat positions[] = {

	-0.25f, 0.0f,
	- 0.75f, 0.0f,
	- 0.216506351f, 0.125f,
	- 0.649519053f, 0.375f,
	- 0.125, 0.216506351f,
	- 0.375f, 0.649519053f,
	0.0f, 0.25f,
	0.0f, 0.75f,
	0.125f, 0.216506351f,
	0.375f, 0.649519053f,
	0.216506351f, 0.125f,
	0.649519053f, 0.375f,
	0.25f, 0.0f,
	0.75f, 0.0f
};

static GLubyte colours[] = {

	255, 0, 0,
	255, 0, 0,
	255, 0, 0,
	255, 0, 0,
	255, 255, 0,
	255, 255, 0,
	0, 255, 0,
	0, 255, 0,
	112, 231, 243,
	112, 231, 243,
	0, 0, 255,
	0, 0, 255,
	234, 53, 230,
	234, 53, 230
};


void drawSemiCircleVertexArray() {

	glShadeModel(GL_FLAT);

	// Declare the data type of the array
	glVertexPointer(2, GL_FLOAT, 0, positions);
	glColorPointer(3, GL_UNSIGNED_BYTE, 0, colours);

	// Declare which arrays are needed for the semi-circle object
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	// Draw the object
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 14);
}
