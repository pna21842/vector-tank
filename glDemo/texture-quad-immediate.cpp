
#include "texture-quad-immediate.h"


void drawTexturedQuadImmediate(GLuint texture) {

	// Render objects here...
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_QUADS);

	glColor3ub(255, 255, 255);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(-0.9f, 0.9f);

	glColor3ub(80, 80, 80);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(0.9f, 0.9f);

	glColor3ub(30, 30, 30);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(0.9f, -0.9f);

	glColor3ub(30, 30, 30);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(-0.9f, -0.9f);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}