/*
�����������Ⱦ��պ�
*/

#ifndef LOADER_H
#define LOADER_H

#include "define.h"
class Loader{

public:
	
	GLuint texture[1];

	AUX_RGBImageRec* texture_image[1];

	bool initialTexture();
	
	bool addTexture();
};

#endif