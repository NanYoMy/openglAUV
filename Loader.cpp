#include "Loader.h" 

/*
 * 这个函数用来初始化纹理
 */
bool Loader::initialTexture(){

	memset(this->texture_image,0,sizeof(void *)*1);

	this->texture_image[0]=auxDIBImageLoadW( L"pic\\up.bmp" );

	glGenTextures(1,&texture[0]);

	glBindTexture(GL_TEXTURE_2D,texture[0]);

	glTexImage2D(GL_TEXTURE_2D, 0,3, texture_image[0]->sizeX, texture_image[0]->sizeX, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_image[0]->data);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,0x812F);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,0x812F);

	//通过bind已经把数据放入到GPU，所以在内存的数据需要释放

	free(texture_image[0]->data);				// 释放纹理图像占用的内存

	free(texture_image[0]);						// 释放图像结构

	this->texture_image[1]=auxDIBImageLoadW( L"pic\\far.bmp" );

	glGenTextures(1,&texture[1]);

	glBindTexture(GL_TEXTURE_2D,texture[1]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture_image[1]->sizeX, texture_image[1]->sizeX, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_image[1]->data);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,0x812F);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,0x812F);

	free(texture_image[1]->data);				// 释放纹理图像占用的内存

	free(texture_image[1]);						// 释放图像结构



	this->texture_image[2]=auxDIBImageLoadW( L"pic\\near.bmp" );

	glGenTextures(1,&texture[2]);

	glBindTexture(GL_TEXTURE_2D,texture[2]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture_image[2]->sizeX, texture_image[2]->sizeX, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_image[2]->data);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,0x812F);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,0x812F);

	free(texture_image[2]->data);				// 释放纹理图像占用的内存

	free(texture_image[2]);						// 释放图像结构

	this->texture_image[3]=auxDIBImageLoadW( L"pic\\down.bmp" );

	glGenTextures(1,&texture[3]);

	glBindTexture(GL_TEXTURE_2D,texture[3]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture_image[3]->sizeX, texture_image[3]->sizeX, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_image[3]->data);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,0x812F);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,0x812F);

	free(texture_image[3]->data);				// 释放纹理图像占用的内存

	free(texture_image[3]);						// 释放图像结构



	this->texture_image[4]=auxDIBImageLoadW( L"pic\\right.bmp" );

	glGenTextures(1,&texture[4]);

	glBindTexture(GL_TEXTURE_2D,texture[4]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture_image[4]->sizeX, texture_image[4]->sizeX, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_image[4]->data);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,0x812F);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,0x812F);

	free(texture_image[4]->data);				// 释放纹理图像占用的内存

	free(texture_image[4]);						// 释放图像结构


	this->texture_image[5]=auxDIBImageLoadW( L"pic\\left.bmp" );

	glGenTextures(1,&texture[5]);

	glBindTexture(GL_TEXTURE_2D,texture[5]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture_image[5]->sizeX, texture_image[5]->sizeX, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_image[5]->data);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,0x812F);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,0x812F);

	free(texture_image[5]->data);				// 释放纹理图像占用的内存

	free(texture_image[5]);						// 释放图像结构

	return true;

}


/*
 * 这个函数用来添加纹理到天空盒
 */
bool Loader::addTexture(){


	
	
	glEnable(GL_TEXTURE_2D);
	
	glShadeModel(GL_SMOOTH);
	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glDisable(GL_DEPTH_TEST);
	//front
	glBindTexture(GL_TEXTURE_2D, this->texture[2]);

	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);

	glEnd();

	//back
	glBindTexture(GL_TEXTURE_2D, this->texture[1]);

	glBegin(GL_QUADS);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);

	glEnd();

	//left
	glBindTexture(GL_TEXTURE_2D, this->texture[5]);

	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);

	glEnd();
	//right
	glBindTexture(GL_TEXTURE_2D, this->texture[4]);

	glBegin(GL_QUADS);

	glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);

	glEnd();
	//up
	glBindTexture(GL_TEXTURE_2D, this->texture[0]);

	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);

	glEnd();

	//down
	
	/*
	glBindTexture(GL_TEXTURE_2D, this->texture[5]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, -1.0f,  10.0f);
	glTexCoord2f(0.1f, 0.0f); glVertex3f(-10.0f, -1.0f,  -10.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0f,  -1.0f,  -10.0f);
	glTexCoord2f(0.1f, 0.0f); glVertex3f(10.0f,  -1.0f,  1.0f);
	glEnd();
	*/
	
	glDisable(GL_TEXTURE_2D);

	return true;

}