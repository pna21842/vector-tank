
#include "arwing.h"

void drawArwingImmediate() {

	glShadeModel(GL_FLAT);

	glBegin(GL_TRIANGLES);

#pragma region main body

	glColor3ub(230, 232, 247);
	glVertex2f(0.0f, 9.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(-0.184f, 0.0f);

	glColor3ub(166, 167, 179);
	glVertex2f(0.0f, 9.0f);
	glVertex2f(0.184f, 0.0f);
	glVertex2f(1.0f, 1.0f);

	glColor3ub(190, 191, 204);
	glVertex2f(0.0f, 9.0f);
	glVertex2f(-0.184f, 0.0f);
	glVertex2f(0.184f, 0.0f);


	glColor3ub(200, 201, 214);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(-0.656f, -0.876f);
	glVertex2f(-0.184f, 0.0f);

	glColor3ub(166, 167, 179);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(0.184f, 0.0f);
	glVertex2f(0.656f, -0.876f);
	

	glColor3ub(230, 232, 247);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(-1.720f, -0.426f);
	glVertex2f(-0.656f, -0.876f);
	
	glColor3ub(157, 158, 168);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(0.656f, -0.876f);
	glVertex2f(1.720f, -0.426f);
	

	glColor3ub(204, 206, 219);
	glVertex2f(-1.720f, -0.426f);
	glVertex2f(-1.623f, -2.097f);
	glVertex2f(-0.656f, -0.876f);

	glColor3ub(138, 139, 148);
	glVertex2f(1.720f, -0.426f);
	glVertex2f(1.623f, -2.097f);
	glVertex2f(0.656f, -0.876f);


	glColor3ub(176, 177, 189);
	glVertex2f(-0.184f, 0.0f);	
	glVertex2f(-0.656f, -0.876f);
	glVertex2f(-0.262f, -1.394f);

	glColor3ub(121, 127, 135);
	glVertex2f(0.184f, 0.0f);
	glVertex2f(0.262f, -1.394f);
	glVertex2f(0.656f, -0.876f);
	
	glColor3ub(164, 165, 176);
	glVertex2f(-0.656f, -0.876f);
	glVertex2f(-1.623f, -2.097f);
	glVertex2f(-1.169f, -3.0f);

	glColor3ub(112, 113, 120);
	glVertex2f(0.656f, -0.876f);
	glVertex2f(1.169f, -3.0f);
	glVertex2f(1.623f, -2.097f);
	

	glColor3ub(154, 156, 166);
	glVertex2f(-0.656f, -0.876f);
	glVertex2f(-1.169f, -3.0f);
	glVertex2f(-0.421f, -1.940f);
	
	glColor3ub(102, 103, 110);
	glVertex2f(0.656f, -0.876f);
	glVertex2f(0.421f, -1.940f);
	glVertex2f(1.169f, -3.0f);
	

	glColor3ub(130, 128, 200);
	glVertex2f(-0.656f, -0.876f);
	glVertex2f(-0.421f, -1.940f);
	glVertex2f(-0.262f, -1.394f);

	glColor3ub(130, 128, 200);
	glVertex2f(0.656f, -0.876f);
	glVertex2f(0.262f, -1.394f);
	glVertex2f(0.421f, -1.940f);
	

	glColor3ub(138, 139, 148);
	glVertex2f(-0.421f, -1.940f);
	glVertex2f(-1.169f, -3.0f);
	glVertex2f(0.0f, -5.5f);
	
	glColor3ub(91, 91, 97);
	glVertex2f(0.421f, -1.940f);
	glVertex2f(0.0f, -5.5f);
	glVertex2f(1.169f, -3.0f);


	glColor3ub(129, 130, 138);
	glVertex2f(-0.421f, -1.940f);
	glVertex2f(0.0f, -5.5f);
	glVertex2f(0.421f, -1.940f);


	glColor3ub(0, 128, 255);
	glVertex2f(-0.184f, 0.0f);
	glVertex2f(-0.262f, -1.394f);
	glVertex2f(0.184f, 0.0f);

	glColor3ub(0, 128, 255);
	glVertex2f(0.184f, 0.0f);
	glVertex2f(-0.262f, -1.394f);
	glVertex2f(0.262f, -1.394f);

	glColor3ub(0, 118, 245);
	glVertex2f(0.262f, -1.394f);
	glVertex2f(-0.262f, -1.394f);
	glVertex2f(-0.421f, -1.940f);

	glColor3ub(0, 118, 245);
	glVertex2f(0.262f, -1.394f);
	glVertex2f(-0.421f, -1.940f);
	glVertex2f(0.421f, -1.940f);

#pragma endregion

#pragma region Left Engine

	glColor3ub(59, 93, 195);
	glVertex2f(-1.720f, -0.426f);
	glVertex2f(-2.099f, -0.540f);
	glVertex2f(-2.094, -2.083);

	glVertex2f(-1.720f, -0.426f);
	glVertex2f(-2.094, -2.083);
	glVertex2f(-1.623f, -2.097f);

	glColor3ub(76, 115, 229);
	glVertex2f(-2.099f, -0.540f);
	glVertex2f(-2.440f, -0.540f);
	glVertex2f(-2.471f, -2.096f);

	glVertex2f(-2.099f, -0.540f);
	glVertex2f(-2.471f, -2.096f);
	glVertex2f(-2.094f, -2.083f);

	glColor3ub(86, 131, 252);

	glVertex2f(-2.805f, -0.211f);
	glVertex2f(-2.926f, -1.618f);
	glVertex2f(-2.471f, -2.096f);

	glVertex2f(-2.805f, -0.211f);
	glVertex2f(-2.471f, -2.096f);
	glVertex2f(-2.440f, -0.540f);
	
	glVertex2f(-2.926f, -1.618f);
	glVertex2f(-2.931f, -2.786f);
	glVertex2f(-2.471f, -2.096f);

	glColor3ub(126, 157, 252);

	glVertex2f(-2.310, 4.0f);
	glVertex2f(-2.805f, -0.211f);
	glVertex2f(-2.440f, -0.540f);
	
	glColor3ub(84, 127, 242);
	glVertex2f(-2.310, 4.0f);
	glVertex2f(-2.440f, -0.540f);
	glVertex2f(-2.099f, -0.540f);

	glColor3ub(65, 102, 214);
	glVertex2f(-2.310, 4.0f);
	glVertex2f(-2.099f, -0.540f);
	glVertex2f(-1.720f, -0.426f);

	glColor3ub(77, 117, 227);
	glVertex2f(-2.471f, -2.096f);
	glVertex2f(-2.931f, -2.786f);
	glVertex2f(-2.310, -5.202f);
	
	glColor3ub(69, 105, 209);

	glVertex2f(-2.094f, -2.083f);
	glVertex2f(-2.471f, -2.096f);
	glVertex2f(-2.310, -5.202f);

	glColor3ub(54, 85, 179);
	glVertex2f(-1.623f, -2.097f);
	glVertex2f(-2.094f, -2.083f);
	glVertex2f(-2.310, -5.202f);

#pragma endregion


#pragma region Left wing

	glColor3ub(230, 232, 247);
	glVertex2f(-2.805f, -0.211f);
	glVertex2f(-4.667f, -0.637f);
	glVertex2f(-4.394f, -1.84f);

	glVertex2f(-2.805f, -0.211f);
	glVertex2f(-4.394f, -1.84f);
	glVertex2f(-2.926f, -1.618f);

	glColor3ub(190, 191, 204);
	glVertex2f(-2.926f, -1.618f);
	glVertex2f(-4.394f, -1.848f);
	glVertex2f(-4.333f, -2.890f);

	glVertex2f(-2.926f, -1.618f);
	glVertex2f(-4.333f, -2.890f);
	glVertex2f(-2.931f, -2.786f);

	glColor3ub(166, 167, 179);
	glVertex2f(-2.931f, -2.786f);
	glVertex2f(-4.333f, -2.890f);
	glVertex2f(-4.669f, -3.975f);

	glVertex2f(-2.931f, -2.786f);
	glVertex2f(-4.669f, -3.975f);
	glVertex2f(-3.517f, -3.691f);


	glColor3ub(218, 220, 235);
	glVertex2f(-4.667f, -0.637f);
	glVertex2f(-6.444f, -1.396f);
	glVertex2f(-6.198f, -2.297f);

	glVertex2f(-4.667f, -0.637f);
	glVertex2f(-6.198f, -2.297f);
	glVertex2f(-4.394f, -1.848f);


	glColor3ub(180, 181, 194);
	glVertex2f(-4.394f, -1.848f);
	glVertex2f(-6.198f, -2.297f);
	glVertex2f(-6.266f, -3.557f);

	glVertex2f(-4.394f, -1.848f);
	glVertex2f(-6.266f, -3.557f);
	glVertex2f(-4.333f, -2.890f);


	glColor3ub(157, 158, 168);
	glVertex2f(-4.333f, -2.890f);
	glVertex2f(-6.266f, -3.557f);
	glVertex2f(-4.669f, -3.975f);


	glColor3ub(228, 230, 245);

	glVertex2f(-6.444f, -1.396f);
	glVertex2f(-7.339f, -2.251f);
	glVertex2f(-7.089f, -3.187f);

	glVertex2f(-6.444f, -1.396f);
	glVertex2f(-7.089f, -3.187f);
	glVertex2f(-6.198f, -2.297f);


	glColor3ub(190, 191, 204);
	glVertex2f(-6.198f, -2.297f);
	glVertex2f(-7.089f, -3.187f);
	glVertex2f(-6.266f, -3.557f);

	glColor3ub(190, 191, 204);
	glVertex2f(-7.806f, -1.169f);
	glVertex2f(-7.339f, -2.251f);
	glVertex2f(-6.444f, -1.396f);

	glColor3ub(237, 201, 61);
	glVertex2f(-7.806f, -1.169f);
	glVertex2f(-9.773f, -4.944f);
	glVertex2f(-7.339f, -2.251f);

	glColor3ub(201, 171, 52);
	glVertex2f(-7.339f, -2.251f);
	glVertex2f(-9.773f, -4.944f);
	glVertex2f(-7.089f, -3.187f);

#pragma endregion




#pragma region Right Engine

	glColor3ub(59, 93, 195);
	glVertex2f(1.720f, -0.426f);
	glVertex2f(2.094, -2.083);
	glVertex2f(2.099f, -0.540f);

	glVertex2f(1.720f, -0.426f);
	glVertex2f(1.623f, -2.097f);
	glVertex2f(2.094, -2.083);
	

	glColor3ub(76, 115, 229);
	glVertex2f(2.099f, -0.540f);
	glVertex2f(2.471f, -2.096f);
	glVertex2f(2.440f, -0.540f);

	glVertex2f(2.099f, -0.540f);
	glVertex2f(2.094f, -2.083f);
	glVertex2f(2.471f, -2.096f);
	

	glColor3ub(86, 131, 252);
	glVertex2f(2.805f, -0.211f);
	glVertex2f(2.471f, -2.096f);
	glVertex2f(2.926f, -1.618f);
	
	glVertex2f(2.805f, -0.211f);
	glVertex2f(2.440f, -0.540f);
	glVertex2f(2.471f, -2.096f);
	
	glVertex2f(2.926f, -1.618f);
	glVertex2f(2.471f, -2.096f);
	glVertex2f(2.931f, -2.786f);
	

	glColor3ub(126, 157, 252);
	glVertex2f(2.310, 4.0f);
	glVertex2f(2.440f, -0.540f);
	glVertex2f(2.805f, -0.211f);


	glColor3ub(84, 127, 242);
	glVertex2f(2.310, 4.0f);
	glVertex2f(2.099f, -0.540f);
	glVertex2f(2.440f, -0.540f);
	

	glColor3ub(65, 102, 214);
	glVertex2f(2.310, 4.0f);
	glVertex2f(1.720f, -0.426f);
	glVertex2f(2.099f, -0.540f);
	

	glColor3ub(77, 117, 227);
	glVertex2f(2.471f, -2.096f);
	glVertex2f(2.310, -5.202f);
	glVertex2f(2.931f, -2.786f);
	

	glColor3ub(69, 105, 209);
	glVertex2f(2.094f, -2.083f);
	glVertex2f(2.310, -5.202f);
	glVertex2f(2.471f, -2.096f);
	

	glColor3ub(54, 85, 179);
	glVertex2f(1.623f, -2.097f);
	glVertex2f(2.310, -5.202f);
	glVertex2f(2.094f, -2.083f);
	
#pragma endregion



#pragma region Right wing

	glColor3ub(230, 232, 247);
	glVertex2f(2.805f, -0.211f);
	glVertex2f(4.667f, -0.637f);
	glVertex2f(4.394f, -1.84f);

	glVertex2f(2.805f, -0.211f);
	glVertex2f(4.394f, -1.84f);
	glVertex2f(2.926f, -1.618f);

	glColor3ub(190, 191, 204);
	glVertex2f(2.926f, -1.618f);
	glVertex2f(4.394f, -1.848f);
	glVertex2f(4.333f, -2.890f);

	glVertex2f(2.926f, -1.618f);
	glVertex2f(4.333f, -2.890f);
	glVertex2f(2.931f, -2.786f);

	glColor3ub(166, 167, 179);
	glVertex2f(2.931f, -2.786f);
	glVertex2f(4.333f, -2.890f);
	glVertex2f(4.669f, -3.975f);

	glVertex2f(2.931f, -2.786f);
	glVertex2f(4.669f, -3.975f);
	glVertex2f(3.517f, -3.691f);


	glColor3ub(218, 220, 235);
	glVertex2f(4.667f, -0.637f);
	glVertex2f(6.444f, -1.396f);
	glVertex2f(6.198f, -2.297f);

	glVertex2f(4.667f, -0.637f);
	glVertex2f(6.198f, -2.297f);
	glVertex2f(4.394f, -1.848f);


	glColor3ub(180, 181, 194);
	glVertex2f(4.394f, -1.848f);
	glVertex2f(6.198f, -2.297f);
	glVertex2f(6.266f, -3.557f);

	glVertex2f(4.394f, -1.848f);
	glVertex2f(6.266f, -3.557f);
	glVertex2f(4.333f, -2.890f);


	glColor3ub(157, 158, 168);
	glVertex2f(4.333f, -2.890f);
	glVertex2f(6.266f, -3.557f);
	glVertex2f(4.669f, -3.975f);


	glColor3ub(228, 230, 245);

	glVertex2f(6.444f, -1.396f);
	glVertex2f(7.339f, -2.251f);
	glVertex2f(7.089f, -3.187f);

	glVertex2f(6.444f, -1.396f);
	glVertex2f(7.089f, -3.187f);
	glVertex2f(6.198f, -2.297f);


	glColor3ub(190, 191, 204);
	glVertex2f(6.198f, -2.297f);
	glVertex2f(7.089f, -3.187f);
	glVertex2f(6.266f, -3.557f);

	glColor3ub(190, 191, 204);
	glVertex2f(7.806f, -1.169f);
	glVertex2f(7.339f, -2.251f);
	glVertex2f(6.444f, -1.396f);

	glColor3ub(237, 201, 61);
	glVertex2f(7.806f, -1.169f);
	glVertex2f(9.773f, -4.944f);
	glVertex2f(7.339f, -2.251f);

	glColor3ub(201, 171, 52);
	glVertex2f(7.339f, -2.251f);
	glVertex2f(9.773f, -4.944f);
	glVertex2f(7.089f, -3.187f);

#pragma endregion

	glEnd();
}