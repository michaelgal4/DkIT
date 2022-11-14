#include "raylib.h"

static const int windowWidth = 800;										//window width
static const int windowHeight = 450;									//window height

int main(){	

int pos1 = 0;															// starting position for the pastic bottles
int pos2 = -200;														// starting position for the pastic bottles
int pos3 = -1000;														// starting position for the pastic bottles
int pos4 = -600;														// starting position for the pastic bottles
int pos5 = -1300;														// starting position for the pastic bottles
int pos6 = -800;														// starting position for the pastic bottles

Sound sound;															// giving a name for my audio
Music music;															// giving a name for my background music
Font font;																// giving a name for my font

InitWindow(windowWidth, windowHeight, "CA1 RayLib MG : Save The Turle"); 	//assigning the windoe width and height size with project title name
InitAudioDevice();														// assigning audio device function

sound = LoadSound("resources/splash.wav");								// getting audio from rescorce folder
music = LoadMusicStream("resources/ocean-waves.wav");					// getting audio from rescorce folder
PlayMusicStream(music);													// playing background music

font = LoadFont("resources/BEACHTYP.TTF");								// getting font from rescorce folder
				
Texture2D turtle = LoadTexture("resources/turtle.png"); 				//loading the turtle png

unsigned numFrames = 8; 												//assigning 8 frames to aniamte the turtle
int frameWidth = turtle.width / numFrames; 								// turtle frames width and height
Rectangle frameRecTurtle = { 0.0f, 0.0f, (float)frameWidth, (float)turtle.height };	// assigning a size to the turle for the frame rate

Texture2D plastic1 = LoadTexture("resources/Plastic 1.png");			//loading the plastic png
Texture2D plastic2 = LoadTexture("resources/Plastic 2.png");			//loading the plastic png
Texture2D plastic3 = LoadTexture("resources/Plastic 3.png");			//loading the plastic png
Texture2D plastic4 = LoadTexture("resources/Plastic 4.png");			//loading the plastic png
Texture2D plastic5 = LoadTexture("resources/Plastic 4.png");			//loading the plastic png

float x = 550.0f, y = 32.0f;											// position of turtle inside the window

unsigned frameDelay = 10; 												// slow down frames in turtle animation
unsigned frameDelayCounter = 0;											// assigning a frame counter
unsigned frameIndex = 0; 												//frame counter

SetTargetFPS(60);														// frame rate of the scene

while (!WindowShouldClose()) 											//updates after every frame
{
	UpdateMusicStream(music);											// triggering background sound

	pos1 += GetFrameTime()*200;											// moving the plastic across the screen on x axis
	if (pos1 > 800){													// once it gets to the end of the screen it moves back to the start
		pos1 = -100;
	}
	pos2 += GetFrameTime()*200;											// moving the plastic across the screen on x axis
	if (pos2 > 800){													// once it gets to the end of the screen it moves back to the start
		pos2 = -100;
	}
	pos3 += GetFrameTime()*200;											// moving the plastic across the screen on x axis
	if (pos3 > 800){													// once it gets to the end of the screen it moves back to the start
		pos3 = -100;
	}
	pos4 += GetFrameTime()*200;											// moving the plastic across the screen on x axis
	if (pos4 > 800){													// once it gets to the end of the screen it moves back to the start
		pos4 = -100;
	}
	pos5 += GetFrameTime()*200;											// moving the plastic across the screen on x axis
	if (pos5 > 800){													// once it gets to the end of the screen it moves back to the start
		pos5 = -100;
	}
	pos6 += GetFrameTime()*200;											// moving the plastic across the screen on x axis
	if (pos6 > 800){													// once it gets to the end of the screen it moves back to the start
		pos6 = -100;
	}

	if(IsKeyDown(KEY_UP)){												// assigning the UP key to trigger commands when pressed down
		PlaySoundMulti(sound);											// triggering audio
		y -= GetFrameTime()* 200.0f;									// moving the y value up at a speed
	}

	if(IsKeyDown(KEY_DOWN)){											// assigning the DOWN key to trigger commands when pressed down
		PlaySoundMulti(sound);											// triggering audio
		y += GetFrameTime()* 200.0f;									// moving the y value down at a speed
	}

	++frameDelayCounter;												// triggering the animation
	if(frameDelayCounter > frameDelay){  								//if frame delay counder is greater then zero then slow down the frame rate
		frameDelayCounter = 0;
		++frameIndex;
		frameIndex %= numFrames;
		frameRecTurtle.x = (float) frameWidth * frameIndex;
	}
	

	BeginDrawing();

	DrawTextEx(font,"Save The Turles", {300, 20}, 30, 2, WHITE);		// Writing save the turtles in the font I downloaded

	ClearBackground(BLUE);												// Blue background

	DrawTexturePro(turtle, frameRecTurtle, Rectangle{x, y, 200, 200}, Vector2{0, 0}, 0, RAYWHITE); // Drawing the turtle and animating it

	DrawTexture(plastic1, pos1, 200, WHITE);							// drawing pastic trash and assigning v position and using the x position assigned above
	DrawTexture(plastic2, pos2, 350, WHITE);							// drawing pastic trash and assigning v position and using the x position assigned above
	DrawTexture(plastic3, pos3, 50, WHITE);								// drawing pastic trash and assigning v position and using the x position assigned above
	DrawTexture(plastic4, pos4, 150, WHITE);							// drawing pastic trash and assigning v position and using the x position assigned above
	DrawTexture(plastic5, pos5, 100, WHITE);							// drawing pastic trash and assigning v position and using the x position assigned above
	DrawTexture(plastic1, pos6, 0, WHITE);						 		// drawing pastic trash and assigning v position and using the x position assigned above

	EndDrawing();														// end of the code
}

CloseAudioDevice();														// shut down audio when close window
StopMusicStream(music);													// shut down background music when close window

CloseWindow();															// shut down window
}