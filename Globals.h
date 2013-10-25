
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "GL/glut.h"

#define BLOCK_SIZE		42

#define SCENE_WIDHT		1024
#define SCENE_DEPTH		1024
#define SCENE_HEIGHT	256

#define GAME_WIDTH	800
#define GAME_HEIGHT	600

#define EMPTY	0
#define DIRT	1
#define ROCK	2
#define WATER	3
#define SAND	4

#define FPS	60