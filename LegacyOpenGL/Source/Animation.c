#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#include "AnimationController.h"

int mainMenuScene = 1;
int animationScene = 0;

int frameCounter = 0;
int transitionCounter = 0;

void Initialize(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(200, 10);
	glutCreateWindow("Legacy OpenGL App");
	glClearColor(BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH, 0,
		SCREEN_HEIGHT);
}

void MouseHandler(int button, int state, int x, int y)
{
	// left button press
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if (mainMenuScene)
		{
			SetPixelStart(15, 10);

			if (curMouseX >= 50 + pixelStartX / SCALE_FACTOR && curMouseX <= 68 + pixelStartX / SCALE_FACTOR
				&&
				curMouseY >= 16 + pixelStartY / SCALE_FACTOR && curMouseY <= 20 + pixelStartY / SCALE_FACTOR)
				playClicked = 1;

			if (curMouseX >= 50 + pixelStartX / SCALE_FACTOR && curMouseX <= 69 + pixelStartX / SCALE_FACTOR
				&&
				curMouseY >= 3 + pixelStartY / SCALE_FACTOR && curMouseY <= 7 + pixelStartY / SCALE_FACTOR)
				exitClicked = 1;

			SetPixelStart(0, 0);

		}
	}

	//glutPostRedisplay();
}

void PassiveMouseHandler(int x, int y)	// On Canvas Space - cur x y relative to canvas size (NOT screen x y)
{
	curMouseX = x / SCALE_FACTOR;
	curMouseY = (SCREEN_HEIGHT - y) / SCALE_FACTOR;

	/*
	if (curMouseX >= 47 && curMouseX <= 90
		&&
		curMouseY >= 67 && curMouseY <= 73)
		nameHover = 1;
	else
		nameHover = 0;
	*/

}

void MainLoop(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, 1.0f);

	if (playClicked)
	{
		animationScene = 1;
		mainMenuScene = 0;
	}

	if (exitClicked)
		exit(0);


	//--------------------
	// Animation
	glPointSize(SCALE_FACTOR);

	if (mainMenuScene)
	{
		DrawMenu();
		PlayMenu(frameCounter % TOTAL_MENU_FRAMES);
		DrawUI();
		frameCounter++;
	}

	if (animationScene)
	{
		if (transitionCounter < TRANSITION_FRAMES)	// Transition Enter
		{
			DrawMenu();
			PlayMenu(frameCounter % TOTAL_MENU_FRAMES);
			DrawUI();
			frameCounter++;
			DrawTransitionEnter(transitionCounter);
			transitionCounter++;
		}
		else if (transitionCounter < 2 * TRANSITION_FRAMES)	// Transition Exit
		{
			// Changes between menu and animation
			if (transitionCounter == TRANSITION_FRAMES)
			{
				BACKGROUND_R = 0.9f;
				BACKGROUND_G = 0.9f;
				BACKGROUND_B = 0.9f;
			}
			DrawTransitionExit(transitionCounter);
			transitionCounter++;
			frameCounter = 0;
		}
		else  // Main Animation
		{
			PlayFrame(frameCounter % 89);
			frameCounter++;
		}

	}


	//--------------------

	glutSwapBuffers();
}

void TimerFunc(int a)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / ANIMATION_FRAME_RATE, TimerFunc, 0);
}


void main(int argc, char** argv)
{
	// user input
	SCREEN_WIDTH = SCREEN_SIZE;
	SCREEN_HEIGHT = SCREEN_SIZE;

	CANVAS_WIDTH = CANVAS_SIZE;
	CANVAS_HEIGHT = CANVAS_SIZE;

	SCALE_FACTOR = SCREEN_WIDTH / CANVAS_WIDTH;

	// init
	glutInit(&argc, argv);
	Initialize();
	glutDisplayFunc(MainLoop);
	glutMouseFunc(MouseHandler);
	glutPassiveMotionFunc(PassiveMouseHandler);
	glutTimerFunc(0, TimerFunc, 0);
	glutMainLoop();
}
