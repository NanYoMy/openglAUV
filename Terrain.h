/*
这个类用来渲染地形
*/
#ifndef Terrain_Map_h
#define Terrain_Map_h

#include "define.h"
class Terrain_Map{

public:



	const static int TexWidth=1;
	const static int TexHeight=1;
	/*if we declare a arry point in GLubyte***, then we should new all the memeory from heap*/

	GLubyte* blackTexImage[TexWidth][TexHeight];
	GLubyte* whiteTexImage[TexWidth][TexHeight];

	const static int MAP_SIZE=1024;

	const static int STEP_SIZE=5;

	GLuint texture[3];

	AUX_RGBImageRec* texture_image[6];

	BYTE height_map[MAP_SIZE*MAP_SIZE];

	bool LoadRawFile();

	float getHeight(int X ,int Y);

	bool renderHeightMap();

	void initialTexture();
	
	void addTexture();

	void initialBlackAndWhiteImage();
	void initialBlackAndWhiteTexture();

	Terrain_Map();

};
#endif