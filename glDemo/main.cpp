
#include "core.h"
#include "PrincipleAxes.h"
#include "VectorTank.h"
#include "GUFont.h"

using namespace std;
using namespace glm;

// global variables

PrincipleAxes worldAxes = PrincipleAxes();
VectorTank tank = VectorTank();

// Variables to store text rendering properties and font
GUFont* font;
glm::mat4			fontViewMatrix;
glm::vec4			fontColour;


// Window size
const unsigned int initWidth = 512;
const unsigned int initHeight = 512;

// keyboard state
bool forwardPressed = false;
bool reversePressed = false;
bool rotateLeftPressed = false;
bool rotateRightPressed = false;


// Function prototypes
void renderScene();
void resizeWindow(GLFWwindow* window, int width, int height);
void keyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
void updateScene();


int main() {

	//
	// 1. Initialisation
	//
	

	// Initialise glfw and setup window
	glfwInit();

	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_TRUE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);

	GLFWwindow* window = glfwCreateWindow(initWidth, initHeight, "Real-Time Computer Graphics", NULL, NULL);

	// Check window was created successfully
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window!\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	

	// Set callback functions to handle different events
	glfwSetFramebufferSizeCallback(window, resizeWindow); // resize window callback
	glfwSetKeyCallback(window, keyboardHandler); // Keyboard input callback


	// Initialise glew
	glewInit();

	
	// Setup window's initial size
	resizeWindow(window, initWidth, initHeight);

	// Initialise scene - geometry and shaders etc
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f); // setup background colour to be black

	// Setup font
	font = new GUFont(wstring(L"Courier New"), 18);
	

	// Setup projection matrix
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);

	glMatrixMode(GL_MODELVIEW);
	
	
	worldAxes.initialise(2.0f, 1.0f, true, 0xFF00);
	tank.initialise(0.0f, 0.0f, 0.0f);

	//
	// 2. Main loop
	// 
	

	// Loop while program is not terminated.
	while (!glfwWindowShouldClose(window)) {

		updateScene();
		renderScene();						// Render into the current buffer
		glfwSwapBuffers(window);			// Displays what was just rendered (using double buffering).

		// Poll events (key presses, mouse events)
		// glfwWaitEvents();				// Use this if no animation.
		// glfwWaitEventsTimeout(1.0/60.0);	// Use this to animate at 60 frames/sec (timing is NOT reliable)
		glfwPollEvents();					// Use this version when animating as fast as possible
	}

	glfwTerminate();
	return 0;
}


// renderScene - function to render the current scene
void renderScene()
{
	// Clear the rendering window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Clear transformations for the scene
	mat4 I = identity<mat4>();
	glLoadMatrixf((GLfloat*)&I);

	worldAxes.render();

	tank.render();

	// Render text
	static mat4 fontViewMatrix = glm::ortho(-4.0f, 4.0f, -4.0f, 4.0f, -1.0f, 1.0f);
	mat4 T = tank.getModelTransformMatrix();

	font->renderText(-4.0f, 2.0f, fontViewMatrix, vec4(1.0f, 1.0f, 0.0f, 1.0f), "Tank Angle = % .3f", tank.getAngleDegrees());

	// Print x column vector (in red)
	font->renderText(-4.0f, 3.6f, fontViewMatrix, vec4(1.0f, 0.0f, 0.0f, 1.0f), "% .3f", T[0].x);
	font->renderText(-4.0f, 3.3f, fontViewMatrix, vec4(1.0f, 0.0f, 0.0f, 1.0f), "% .3f", T[0].y);
	font->renderText(-4.0f, 3.0f, fontViewMatrix, vec4(1.0f, 0.0f, 0.0f, 1.0f), "% .3f", T[0].z);
	font->renderText(-4.0f, 2.7f, fontViewMatrix, vec4(1.0f, 0.0f, 0.0f, 1.0f), "% .3f", T[0].w);

}


// Function to call when window resized
void resizeWindow(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);		// Draw into entire window
}


// Function to call to handle keyboard input
void keyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {

		// check which key was pressed...
		switch (key)
		{
			case GLFW_KEY_ESCAPE:
				glfwSetWindowShouldClose(window, true);
				break;

			case GLFW_KEY_UP:
				forwardPressed = true;
				break;

			case GLFW_KEY_DOWN:
				reversePressed = true;
				break;

			case GLFW_KEY_LEFT:
				rotateLeftPressed = true;
				break;

			case GLFW_KEY_RIGHT:
				rotateRightPressed = true;
				break;


			default:
			{
			}
		}
	}
	else if (action == GLFW_RELEASE) {
		
		// handle key release events

		// check which key was released...
		switch (key)
		{
			case GLFW_KEY_UP:
				forwardPressed = false;
				break;

			case GLFW_KEY_DOWN:
				reversePressed = false;
				break;

			case GLFW_KEY_LEFT:
				rotateLeftPressed = false;
				break;

			case GLFW_KEY_RIGHT:
				rotateRightPressed = false;
				break;

			default:
			{
			}
		}
	}
}


// Function called to animate elements in the scene
void updateScene() {

	const float tDelta = 0.0005f; // fixed for now - add game clock later!

	if (forwardPressed) {

		tank.move(1.0f, tDelta);
	}

	if (reversePressed) {

		tank.move(-1.0f, tDelta);
	}

	if (rotateLeftPressed) {

		tank.rotate(1.0f, tDelta);
	}

	if (rotateRightPressed) {

		tank.rotate(-1.0f, tDelta);
	}
}

