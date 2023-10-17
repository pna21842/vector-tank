
#include "star-vbo.h"


// Array data

static GLfloat starVertices[] = { 0.0, 0.25f,
								0.1f, 0.1f,
								0.25f, 0.08f,
								0.15f, -0.05f,
								0.25f, -0.25f,
								0.0, -0.125f,
								-0.25f, -0.25f,
								-0.15f, -0.05f,
								-0.25f, 0.08f,
								-0.1f, 0.1f };

static GLubyte starColors[] = { 255, 0, 0,
								255, 255, 0,
								0, 255, 0,
								0, 255, 255,
								0, 0, 255,
								128, 45, 200,
								0, 255, 0,
								255, 0, 255,
								255, 128, 255,
								255, 128, 128 };

static float starTextureCoords[] = { 0.5f, 1.0f,
									0.6f, 0.7f,
									1.0f, 0.7f,
									0.8f, 0.4f,
									0.95f, 0.0f,
									0.0f, 0.3f,
									-0.95f, 0.0f,
									-0.8f, 0.4f,
									-1.0f, 0.7f,
									-0.6f, 0.7f };

static GLuint starIndices[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

// Variables to store VBO id numbers created by OpenGL
static GLuint starPosVBO;
static GLuint starColourVBO;
static GLuint starTexCoordVBO;
static GLuint starIndicesVBO;



void setupStarVBO() {

	glGenBuffers(1, &starPosVBO);
	glBindBuffer(GL_ARRAY_BUFFER, starPosVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(starVertices), starVertices, GL_STATIC_DRAW);

	glGenBuffers(1, &starColourVBO);
	glBindBuffer(GL_ARRAY_BUFFER, starColourVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(starColors), starColors, GL_STATIC_DRAW);

	glGenBuffers(1, &starTexCoordVBO);
	glBindBuffer(GL_ARRAY_BUFFER, starTexCoordVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(starTextureCoords), starTextureCoords, GL_STATIC_DRAW);

	glGenBuffers(1, &starIndicesVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, starIndicesVBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(starIndices), starIndices, GL_STATIC_DRAW);
}

void drawStarVBO() {

	// Declare the data type of the array
	glBindBuffer(GL_ARRAY_BUFFER, starPosVBO);
	glVertexPointer(2, GL_FLOAT, 0, (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER, starColourVBO);
	glColorPointer(3, GL_UNSIGNED_BYTE, 0, (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER, starTexCoordVBO);
	glTexCoordPointer(2, GL_FLOAT, 0, (GLvoid*)0);

	// Declare which arrays are needed for the semi-circle object
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	// Draw the object
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, starIndicesVBO);
	glDrawElements(GL_LINE_LOOP, 10, GL_UNSIGNED_INT, (GLvoid*)0);
}

