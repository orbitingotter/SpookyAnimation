#include <GL/glut.h>
#include <math.h>

// Global States

#define SCREEN_SIZE 768
#define CANVAS_SIZE 96

int SCREEN_WIDTH, SCREEN_HEIGHT;

int CANVAS_WIDTH, CANVAS_HEIGHT;
int SCALE_FACTOR;

float BACKGROUND_R = 33.0f / 255.0f, BACKGROUND_G = 37.0f / 255.0f, BACKGROUND_B = 44.0f / 255.0f;

int ANIMATION_FRAME_RATE = 10;
int TOTAL_FRAMES = 120;
int TOTAL_MENU_FRAMES = 8;

// transition states
int TRANSITION_FRAMES = 15;
int TRANSITION_COLOR = 0x111111;

// helpers
int pixelStartX = 0, pixelStartY = 0;

// input
int curMouseX = 0, curMouseY = 0;
int playClicked = 0, exitClicked = 0;



// Helper Function

void PutPixel(int x, int y, int hexValue)
{
	int resultX = (x * SCALE_FACTOR) + (SCALE_FACTOR / 2);
	int resultY = (y * SCALE_FACTOR) + (SCALE_FACTOR / 2);

	float r = ((hexValue >> 16) & 0xFF) / 255.0f;
	float g = ((hexValue >> 8) & 0xFF) / 255.0f;
	float b = ((hexValue >> 0) & 0xFF) / 255.0f;

	glBegin(GL_POINTS);
	glColor4f(r, g, b, 1.0f);
	glVertex2i(pixelStartX + resultX, pixelStartY + resultY);
	glEnd();
}

void SetPixelStart(int x, int y)
{
	pixelStartX = x * SCALE_FACTOR;
	pixelStartY = y * SCALE_FACTOR;
}


// Main Code
// main menu

// transitions
void DrawTransitionEnter(int counter)
{
	float i = -3.0f + (counter / (float)TRANSITION_FRAMES * 3.0f);

	for (int y = 0; y < CANVAS_SIZE; y++)
	{
		int x = (int)-sqrt(pow((CANVAS_SIZE / 2), 2) - pow(y - CANVAS_SIZE / 2, 2)) - (CANVAS_SIZE / 2 * i);

		while (x < CANVAS_SIZE)
		{
			PutPixel(x, y, TRANSITION_COLOR);
			x++;
		}
	}
}


void DrawTransitionExit(int counter)
{
	float i = -2.0f + ((counter - TRANSITION_FRAMES) / (float)TRANSITION_FRAMES * 3.0f);


	for (int y = 0; y < CANVAS_SIZE; y++)
	{
		int x = (int)sqrt(pow((CANVAS_SIZE / 2), 2) - pow(y - CANVAS_SIZE / 2, 2)) - (CANVAS_SIZE / 2 * i);

		for (int j = 0; j < x; j++)
		{
			PutPixel(j, y, TRANSITION_COLOR);
		}
	}
}



#include "Menu.h"
#include "UI.h"
#include "Pumpkin.h"