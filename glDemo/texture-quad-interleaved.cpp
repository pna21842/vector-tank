
#include "texture-quad-interleaved.h"

struct TexturedVertex {

	GLfloat		x, y;		// position
	GLubyte		r, g, b;	// colour
	GLfloat		s, t;		// texture coords

	TexturedVertex(GLfloat x, GLfloat y, GLubyte r, GLubyte g, GLubyte b, GLfloat s, GLfloat t) {

		this->x = x;
		this->y = y;

		this->r = r;
		this->g = g;
		this->b = b;

		this->s = s;
		this->t = t;
	}
};

static TexturedVertex vertices[] = {

	TexturedVertex(-0.9f, 0.9f, 255, 255, 255, 0.0f, 1.0f),
	TexturedVertex(0.9f, 0.9f, 80, 80, 80, 1.0f, 1.0f),
	TexturedVertex(0.9f, -0.9f, 30, 30, 30, 1.0f, 0.0f),
	TexturedVertex(-0.9f, -0.9f, 30, 30, 30, 0.0f, 0.0f)
};



void drawTextureQuadInterleaved(GLuint texture) {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	// Declare the data type of the array
	glVertexPointer(2, GL_FLOAT, sizeof(TexturedVertex), &(vertices[0].x));
	glColorPointer(3, GL_UNSIGNED_BYTE, sizeof(TexturedVertex), &(vertices[0].r));
	glTexCoordPointer(2, GL_FLOAT, sizeof(TexturedVertex), &(vertices[0].s));

	// Declare which arrays are needed for the semi-circle object
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	// Draw the object
	glDrawArrays(GL_QUADS, 0, 4);
}
