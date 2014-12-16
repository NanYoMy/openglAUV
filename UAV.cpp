#include "UAV.h"

void logParameter(){

	debug(x);
	debug(z);
	debug(y);
	debug(heading);
	debug(roll);
	debug(pitch);

}



void drawAxis(float size) {
	glBegin(GL_LINES);
	glColor4f(1.0f,0.0f,0.0f,1.0f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(size,0.0f,0.0f);

	glColor4f(0.0f,1.0f,0.0f,1.0f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(0.0f,size,0.0f);

	glColor4f(0.0f,0.0f,1.0f,1.0f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(0.0f,0.0f,size);

	glColor4f(1.0f,1.0f,1.0f,1.0f);
	glEnd();

}

void init(){


	//地面纹理
	loader.initialTexture();
	terrain.LoadRawFile();
	terrain.initialTexture();
	//白色纹理

	z_axes.z=-1;
	y_axes.y=1;

	glClearColor(0.0,0.0,0.0,0.0);
	//why always use shademode
	glShadeModel(GL_FLAT);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glEnable(GL_SCISSOR_TEST);
	
	
}




void keyboard(unsigned char key,int x_mouse,int y_mouse){

	//x=y=z=heading=pitch=roll=0;

	log("------------------");
	log("step into keyboard");


	switch(key){

		case 'w':{

			
			anglesToAxes(angles,x_axes,y_axes,z_axes);
			position.x += y_axes.x;
			position.y += y_axes.y;
			position.z += y_axes.z;

			debug(position.x);
			debug(position.y);
			debug(position.z);

			glutPostRedisplay();
			break;
				 }

		case 's':{
			

			anglesToAxes(angles,x_axes,y_axes,z_axes);
			position.x -= y_axes.x;
			position.y -= y_axes.y;
			position.z -= y_axes.z;
			glutPostRedisplay();
			break;
				 }
		case 'd':{
		

			anglesToAxes(angles,x_axes,y_axes,z_axes);
			position.x += x_axes.x;
			position.y += x_axes.y;
			position.z += x_axes.z;

			glutPostRedisplay();

				glutPostRedisplay();
			break;
				 }
		case 'a':{
		

			anglesToAxes(angles,x_axes,y_axes,z_axes);
			position.x -= x_axes.x;
			position.y -= x_axes.y;
			position.z -= x_axes.z;
				glutPostRedisplay();
			break;
				 }
		case 'q':{
		

			anglesToAxes(angles,x_axes,y_axes,z_axes);
			position.x += z_axes.x;
			position.y += z_axes.y;
			position.z += z_axes.z;

			glutPostRedisplay();
			break;
				 }
		case 'e':{
			
			anglesToAxes(angles,x_axes,y_axes,z_axes);
			position.x -= z_axes.x;
			position.y -= z_axes.y;
			position.z -= z_axes.z;

			glutPostRedisplay();
			break;
				 }
		case 'u':{

			angles.x=((int)angles.x+R_STEP)%360;
			anglesToAxes(angles,x_axes,y_axes,z_axes);

			glutPostRedisplay();
			break;
				 }
		case 'j':{

			angles.x=((int)angles.x-R_STEP)%360;
			anglesToAxes(angles,x_axes,y_axes,z_axes);

			glutPostRedisplay();
			break;
				 }
		case 'k':{

			//Y轴旋转
			angles.y=((int)angles.y+R_STEP)%360;
			anglesToAxes(angles,x_axes,y_axes,z_axes);
			glutPostRedisplay();
			break;
				 }
		case 'i':{
			angles.y=((int)angles.y-R_STEP)%360;
			anglesToAxes(angles,x_axes,y_axes,z_axes);
			glutPostRedisplay();
			break;
				 }
		case 'o':{
			angles.z=((int)angles.z+R_STEP)%360;
			anglesToAxes(angles,x_axes,y_axes,z_axes);
			glutPostRedisplay();
			break;
				 }
		case 'l':{
			angles.z=((int)angles.z-R_STEP)%360;
			anglesToAxes(angles,x_axes,y_axes,z_axes);
			glutPostRedisplay();
			break;
				 }
		case 'r':{
			x=0;
			z=0;
			y=0;
			angles.x=0;
			angles.y=0;
			angles.z=0;
			position.x=0;
			position.y=0;
			position.z=0;
			x_axes.x=0;
			x_axes.y=0;
			x_axes.z=0;
			y_axes.x=0;
			y_axes.y=1;
			y_axes.z=0;
			z_axes.x=0;
			z_axes.y=0;
			z_axes.z=1;
			glLoadIdentity();

			glutPostRedisplay();
			break;
				 }
		default: break;


	}

	log("after modify parameter");



}
//the reshape method must involk before display!!
void reshape(int w, int h){

	s_h=h;
	s_w=w;

}


void renderLand(){

	glPushMatrix();
	//glTranslated(0,0,-100);
	//glRotated(90,1,0,0);
	drawAxis(3);
	terrain.renderHeightMap();
	glPopMatrix();
	drawAxis(10);
}
void displayLandScape(){

	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0,1.0,0.0);
	log("display One view");
	int h=s_h;
	int w=s_w;

	glViewport(0,0,(GLsizei)h,(GLsizei)w);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0,(GLfloat)w/(GLfloat)h,1.0,200.0);
	//set the model

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//anglesToAxes(angles,z_axes,y_axes,x_axes);
	gluLookAt(position.x,position.y,position.z,position.x-z_axes.x,position.y-z_axes.y,position.z-z_axes.z,y_axes.x,y_axes.y,y_axes.z);
	
	printCurrentMatrix(GL_MODELVIEW_MATRIX);
	glTranslated(0,0,-50);
	glRotated(90,1,0,0);
	renderLand();
	printCurrentMatrix(GL_MODELVIEW_MATRIX);
	glFinish();
	glutSwapBuffers();




}

int main(int argc,char** argv){

	logParameter();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(s_w,s_h);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(displayLandScape);
	//glutDisplayFunc(displayLandScape);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;

}

