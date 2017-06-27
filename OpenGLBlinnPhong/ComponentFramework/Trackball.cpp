#include "Trackball.h"
#include <GL/glew.h>
#include "VMath.h"
#include "MMath.h"

using namespace GAME;
using namespace MATH;

void Trackball::OnLeftMouseDown(int x, int y){
		int viewport[4];
		glGetIntegerv(GL_VIEWPORT, viewport);
		begin = Vec3(float(x - viewport[2]/2), float(viewport[3]/2)-y, 0.0f );
}

void Trackball::OnMouseMove(int x, int y){
	int viewport[4];
	glGetIntegerv( GL_VIEWPORT, viewport );
	/// Center mouse screen coords
	end = Vec3(float(x - viewport[2]/2), float(viewport[3]/2)-y, 0.0f );
	/// if the mouse movement to too small then leave
	float magnitude = VMath::mag(end - begin);
	if(magnitude  < VERY_SMALL) return;  /// VERY_SMALL is defined in Vector.h
	/// v1 is the dir of the mouse crossed with the z-axis gives the axis of rotation
	Vec3 v1 = VMath::normalize(end  - begin) ;
	Vec3 rotAxis = VMath::cross(Vec3(0.0f,0.0f,1.0f),v1);
	mouseRotationMatrix = mouseRotationMatrix * MMath::rotate(magnitude, rotAxis.x, rotAxis.y, rotAxis.z);
	begin = end;
}

