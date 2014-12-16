#ifndef PILOTVIEW_H
#define PILOTVIEW_H
#include "define.h"

void pilotRotate( GLdouble roll, GLdouble pitch, GLdouble heading){


	glRotated(roll,0.0,0.0,1.0);
	glRotated(pitch,0.0,1.0,0.0);
	glRotated(heading,1.0,0.0,0.0);
	printCurrentMatrix(GL_MODELVIEW_MATRIX);

}

void pilotTranslate(GLdouble x, GLdouble y, GLdouble z){

	glTranslated(x,y,z);

}

void pilotView(GLdouble x, GLdouble y, GLdouble z, GLdouble roll, GLdouble pitch, GLdouble heading){


	pilotRotate(roll,pitch,heading);
	pilotTranslate(x,y,z);

}


#endif