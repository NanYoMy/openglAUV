#ifndef DEFINE_H
#define DEFINE_H

#ifdef WIN32
#define M_PI	3.14159f
#include <windows.h>
#endif

#ifndef GLUT_DISABLE_ATEXIT_HACK  
#define GLUT_DISABLE_ATEXIT_HACK 
#endif 

//包含open及glut的头文件及库

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
//add by dwb
#include <GL/glaux.h>
#pragma comment (lib,"glaux.lib")

#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

const float DEG2RAD = 3.141593f / 180;
#define debug(A) std::cout<<#A<<":"<<A<<std::endl;
#define log(A) std::cout<<A<<std::endl;
class Vector3
{
public:
	float x;
	float y;
	float z;
	Vector3() : x(0), y(0), z(0) {}; 
};
void printCurrentMatrix(int type);
#endif
