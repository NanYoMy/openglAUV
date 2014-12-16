#ifndef UAV_H
#define UAV_H
#include "Loader.h"
#include "Terrain.h"
#include "PilotView.h"
#define DEBUG
const int WIDTH =600;
const int HEIGHT =600;
int s_w=WIDTH,s_h=HEIGHT;

Vector3 angles;
Vector3 position;
Vector3 x_axes;
Vector3 y_axes;
Vector3 z_axes;

int heading=0,pitch=0,roll=0,x=0,y=0,z=-30;
double lx=0,ly=0,lz=-1;



const int T_STEP=3;
const int R_STEP=3;

Terrain_Map terrain;
Loader loader;
void printCurrentMatrix(int type){


	std::cout<<"-------------------------------"<<std::endl;

	GLfloat mat[16];

	glGetFloatv(type, mat);

	for (int j=0;j<4;j++)
	{
		for (int i=0;i<4;i++)
		{
			if ((mat[i*4+j]<0.01)&&(mat[i*4+j]>0))
			{
				mat[i*4+j]=0;
			}else if ((mat[i*4+j]>0.99)&&(mat[i*4+j]<1.01))
			{
				mat[i*4+j]=1;
			}else if ((mat[i*4+j]<-0.99)&&(mat[i*4+j]>-1.01))
			{
				mat[i*4+j]=-1;
			}else if ((mat[i*4+j]>-0.01)&&(mat[i*4+j]<0))
			{
				mat[i*4+j]=0;

			}else{}

			std::cout<<mat[i*4+j]<<" ";

		}
		std::cout<<std::endl;

	}


}
///////////////////////////////////////////////////////////////////////////////
// convert Euler angles(x,y,z) to axes(left, up, forward)
// Each column of the rotation matrix represents left, up and forward axis.
// The order of rotation is Roll->Yaw->Pitch (Rx*Ry*Rz)
// Rx: rotation about X-axis, pitch
// Ry: rotation about Y-axis, yaw(heading)
// Rz: rotation about Z-axis, roll
//    Rx           Ry          Rz
// |1  0   0| | Cy  0 Sy| |Cz -Sz 0|   | CyCz        -CySz         Sy  |
// |0 Cx -Sx|*|  0  1  0|*|Sz  Cz 0| = | SxSyCz+CxSz -SxSySz+CxCz -SxCy|
// |0 Sx  Cx| |-Sy  0 Cy| | 0   0 1|   |-CxSyCz+SxSz  CxSySz+SxCz  CxCy|
///////////////////////////////////////////////////////////////////////////////</span>
void anglesToAxes(const Vector3 angles, Vector3& left, Vector3& up, Vector3& forward)
{
	
	float sx, sy, sz, cx, cy, cz, theta;

	theta = angles.x * DEG2RAD;
	sx = sinf(theta);
	cx = cosf(theta);

	theta = angles.y * DEG2RAD;
	sy = sinf(theta);
	cy = cosf(theta);

	theta = angles.z * DEG2RAD;
	sz = sinf(theta);
	cz = cosf(theta);

	left.x = cy*cz;
	left.y = sx*sy*cz + cx*sz;
	left.z = -cx*sy*cz + sx*sz;


	up.x = -cy*sz;
	up.y = -sx*sy*sz + cx*cz;
	up.z = cx*sy*sz + sx*cz;

	forward.x = sy;
	forward.y = -sx*cy;
	forward.z = cx*cy;
}
#endif