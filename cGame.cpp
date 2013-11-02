#include "cGame.h"

cGame::cGame(void)
{
	drawGlut = false;
}

cGame::~cGame(void){
}

bool cGame::Init()
{
	Point eye(SCENE_WIDTH+20, SCENE_HEIGHT+20, SCENE_DEPTH+20);
	Point center(SCENE_WIDTH/2, SCENE_HEIGHT/2, SCENE_DEPTH/2);
	Point up(0.0, 1.0, 0.0);
	bool basaur;

	//Graphics initialization
	//CAMERA
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	cam = Camera(eye, center, up);
	glMatrixMode(GL_MODELVIEW);
	glAlphaFunc(GL_GREATER, 0.05f);
	glEnable(GL_ALPHA_TEST);
	//LIGHTNING
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat lightPos[] = { SCENE_WIDTH/2, SCENE_HEIGHT*2, SCENE_DEPTH/2, 0};
	GLfloat specLight[] = { 0, 1, 0, 0};
	GLfloat ambiLight[] = { 1, 1, 1, 0};
	GLfloat diffLight[] = { 0.5, 0, 0, 0};
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambiLight);

	basaur = Scene.Init();	
	return basaur;
}

bool cGame::Loop() {
	bool res = Process();
	if(res) Render();
	return res;
}

void cGame::Finalize() {
	exit(0);
}

//Input
void cGame::ReadKeyboard(unsigned char key, bool press) {
	keys[key] = press;
}
void cGame::ReadSpecialKeyboard(unsigned char specialkey, bool press) {
	specialKeys[specialkey] = press;

}

void cGame::ReadMouse(int button, int state, int x, int y) {

}

void cGame::MouseMove(int x, int y,bool pressed){

}


//Process
bool cGame::Process() {
	if(keys[27])return false;
	if(keys['W'] || keys['w'] || specialKeys[GLUT_KEY_UP]) {
		Point camEye = cam.getCameraEye();
		camEye.setZ(camEye.getZ()+1);
		cam.setCamera(camEye, cam.getCameraCenter());
		return true;
	}
	if(keys['A'] || keys['a'] || specialKeys[GLUT_KEY_LEFT]) {
		Point camEye = cam.getCameraEye();
		camEye.setX(camEye.getX()-1);
		cam.setCamera(camEye, cam.getCameraCenter());
		return true;
	}
	if(keys['S'] || keys['s'] || specialKeys[GLUT_KEY_DOWN]) {
		Point camEye = cam.getCameraEye();
		camEye.setZ(camEye.getZ()-1);
		cam.setCamera(camEye, cam.getCameraCenter());
		return true;
	}
	if(keys['D'] || keys['d'] || specialKeys[GLUT_KEY_RIGHT]) {
		Point camEye = cam.getCameraEye();
		camEye.setX(camEye.getX()+1);
		cam.setCamera(camEye, cam.getCameraCenter());
		return true;
	}
	return true;
}

//Output
void cGame::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	glColor3f(1,1,1);
	Scene.Draw();
	glPopMatrix();
	//cam.updateCamera();
	glutSwapBuffers();
}
