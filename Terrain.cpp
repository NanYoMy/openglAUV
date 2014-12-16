#include "Terrain.h"
#include <string>


/**
*这个函数用来读取地形的高度图
*/
bool Terrain_Map::LoadRawFile(){

	FILE* pfile=NULL;

	std::string str="pic\\terrain.raw";

	pfile=fopen(str.c_str(),"rb");

	//fopen_s(pfile,str.c_str(),"rb");

	if(pfile==NULL){

		return false;
	}else{}

	fread(this->height_map,1,this->MAP_SIZE*this->MAP_SIZE,pfile);

	fclose(pfile);

	return true;
}


/**
*这个函数用来获取X,Z坐标下，Y的高度
*/
float Terrain_Map::getHeight(int X ,int Y){

	int  x =  X% MAP_SIZE;				// 限制X的值在0-1024之间

	int y = Y % MAP_SIZE;				// 限制Y的值在0-1024之间

	int heigh=((this->height_map[x + (y * MAP_SIZE)]));

	float heigh_f=(float)heigh/100;

	heigh_f=-heigh_f;

	return 	heigh_f*10;

}


/**
*这个函数用来渲染地形
*/
bool Terrain_Map::renderHeightMap(){

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_TEXTURE_2D);
	
	glShadeModel(GL_SMOOTH);

	glBindTexture(GL_TEXTURE_2D,texture[0]);

	float X = 0, Y = 0;					

	float x, y, z;						

					
		
	for ( X = 0; X < MAP_SIZE; X += STEP_SIZE ){

		for ( Y = 0; Y < MAP_SIZE; Y += STEP_SIZE )
		{

			if ((X>499)&&(X<521))
			{
				if((X>509)&&(X<511)){

					glBindTexture(GL_TEXTURE_2D,texture[1]);

				}else{
				
					glBindTexture(GL_TEXTURE_2D,texture[2]);
				}
				
			}else{

				glBindTexture(GL_TEXTURE_2D,texture[0]);

			}

			glBegin( GL_QUADS );
			// 获得(x,y,z)坐标
			x = X;

			y = this->getHeight( X, Y );

			z = Y;

			x=x-this->MAP_SIZE/2;
			
			z=z-this->MAP_SIZE/2;

			glTexCoord2f(0.0f, 0.0f); 

			glVertex3f(x, y, z);

			// 绘制(x,y+1)处的顶点
			x = X;

			y = this->getHeight( X, Y + STEP_SIZE );

			z = Y + STEP_SIZE ;

			x=x-this->MAP_SIZE/2;
			
			z=z-this->MAP_SIZE/2;

			glTexCoord2f(0.0f, 1.0f);

			glVertex3f(x, y, z);		

			// 绘制(x+1,y+1)处的顶点

			x = X + STEP_SIZE;

			y = this->getHeight( X + STEP_SIZE, Y + STEP_SIZE );

			z = Y + STEP_SIZE ;

			x=x-this->MAP_SIZE/2;

			z=z-this->MAP_SIZE/2;

			glTexCoord2f(1.0f, 1.0f); 

			glVertex3f(x, y, z);			

			// 绘制(x+1,y)处的顶点
			x = X + STEP_SIZE;

			y = this->getHeight(X + STEP_SIZE, Y );

			z = Y;

			x=x-this->MAP_SIZE/2;

			z=z-this->MAP_SIZE/2;

			glTexCoord2f(1.0f, 0.0f);

			glVertex3f(x, y, z);	
			glEnd();
		}
	}

	

	glDisable(GL_TEXTURE_2D);

	return true;
}

/**
*这个函数用来初始化地形的纹理
*/
void Terrain_Map::initialTexture(){

	memset(this->texture_image,0,sizeof(void *)*1);

	this->texture_image[0]=auxDIBImageLoadW( L"pic\\down.bmp" );

	glGenTextures(1,&texture[0]);

	glBindTexture(GL_TEXTURE_2D,texture[0]);

	glTexImage2D(GL_TEXTURE_2D, 0,3, texture_image[0]->sizeX, texture_image[0]->sizeX, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_image[0]->data);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,0x812F);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,0x812F);

	free(texture_image[0]->data);				// 释放纹理图像占用的内存

	free(texture_image[0]);						// 释放图像结构

	initialBlackAndWhiteTexture();



}


/*
*地形对象的初始化函数
*/
Terrain_Map::Terrain_Map(){

	this->initialTexture();

}

void Terrain_Map::initialBlackAndWhiteImage()
{
	

		//i haven't delete it ,memory leak here
		for(int i=0;i<TexWidth;i++){

			for(int j=0;j<TexHeight;j++){

				blackTexImage[i][j]=new GLubyte[4];
				whiteTexImage[i][j]=new GLubyte[4];
			}
		}

		for(int i=0;i<TexWidth;i++){ 

			for(int j=0;j<TexHeight;j++){

				blackTexImage[i][j][0]=255;
				blackTexImage[i][j][1]=255;
				blackTexImage[i][j][2]=255;
				blackTexImage[i][j][3]=1;

				whiteTexImage[i][j][0]=0;
				whiteTexImage[i][j][1]=0;
				whiteTexImage[i][j][2]=0;
				whiteTexImage[i][j][3]=1;

			}		

		}


}

void Terrain_Map::initialBlackAndWhiteTexture()
{

	initialBlackAndWhiteImage();
		//set textrue
		glGenTextures(1,&this->texture[1]);
		glBindTexture(GL_TEXTURE_2D,this->texture[1]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,this->TexWidth,this->TexHeight,0,GL_RGBA,GL_UNSIGNED_BYTE,this->blackTexImage);


		//set textrue
		glGenTextures(1,&this->texture[2]);
		glBindTexture(GL_TEXTURE_2D,this->texture[2]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,this->TexWidth,this->TexHeight,0,GL_RGBA,GL_UNSIGNED_BYTE,this->whiteTexImage);


}