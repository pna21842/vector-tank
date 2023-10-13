
#include "texture-quad-vertexarray.h"

static float positions[] = {

	-0.9f, 0.9f,
	0.9f, 0.9f,
	0.9f, -0.9f,
	-0.9f, -0.9f
};

static GLubyte colours[] = {

	255, 255, 255,
	80, 80, 80,
	30, 30, 30,
	30, 30, 30
};

static float texCoords[] = {

	0.0f, 1.0f,
	1.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 0.0f
};


void drawTextureQuadVertexArray(GLuint texture) {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	// Declare the data type of the array
	glVertexPointer(2, GL_FLOAT, 0, positions);
	glColorPointer(3, GL_UNSIGNED_BYTE, 0, colours);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);

	// Declare which arrays are needed for the semi-circle object
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	// Draw the object
	glDrawArrays(GL_QUADS, 0, 4);
}
