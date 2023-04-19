#include "AnimationFrames.h"

// Function Pointers
typedef void(*VoidFunc)(void);

/*
SEQUENCE -
	1. Intro(11)
	2. Laugh(6)
	3. Jump(6)
	4. Appear(23)
	5. Attack(16)
	6. Spell(16)
	7. Disappear(11)

TOTAL FRAMES = 89
TOTAL UNIQUE FRAMES = 74

1. Intro
intro0-intro10

2. Laugh
(laugh0-laugh1)x3

3. Jump
jump0-jump5

4. Appear
appear0-appear20

5.Attack
attack0-attack15

6. Spell
spell0-spell15 + (reuse animation) - attack

7. Disappear
disappear0-disappear2 + (reuse animation) - reverse jump appear
*/

VoidFunc mainAnimationFrames[] = {
	Intro0, Intro1, Intro2, Intro3, Intro4, Intro5, Intro6, Intro7, Intro8, Intro9, Intro10,	// Intro

	Laugh0, Laugh1, Laugh0, Laugh1, Laugh0, Laugh1,												// Laugh

	Jump0, Jump1, Jump2, Jump3, Jump4, Jump5,													// Jump

	Appear0, Appear1, Appear2, Appear3, Appear3, Appear4, Appear5, Appear6,						// Appear
	Appear7, Appear8, Appear9, Appear10, Appear11, Appear11, Appear12, Appear13,
	Appear14, Appear15, Appear16, Appear17, Appear18, Appear19, Appear20,

	Attack0, Attack1, Attack2, Attack3, Attack4, Attack5, Attack6, Attack7,						// Attack
	Attack8, Attack9, Attack10, Attack11, Attack12, Attack13, Attack14, Attack15,

	Appear11, Appear12, Appear13, Spell0, Spell1, Spell2, Spell3, Spell4,						// Spell
	Spell5, Spell6, Spell7, Spell8, Spell9, Spell10, Spell11, Spell12,

	Appear3, Appear3, Appear2, Appear1, Appear0, Jump5, Jump4, Disappear0,						// Disappear
	Disappear1, Disappear2, Jump0 };


VoidFunc menuFrames[] = { Frame0, Frame1, Frame2, Frame3, Frame4, Frame5, Frame6, Frame7 };

void PlayMenu(int frameID)
{
	VoidFunc CurrentFrame = menuFrames[frameID];
	CurrentFrame();
}


void PlayFrame(int frameID)
{
	VoidFunc CurrentFrame = mainAnimationFrames[frameID];
	CurrentFrame();
}