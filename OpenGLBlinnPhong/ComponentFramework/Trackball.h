#ifndef TRACKBALL_H
#define	TRACKBALL_H

#include "MMath.h"


namespace GAME {
using namespace MATH;


class Trackball {
private:
	Matrix4 mouseRotationMatrix;
	Vec3 begin, end;
public:
	void OnLeftMouseDown(int x, int y);
	void OnMouseMove(int x, int y);

	/// Return the 4x4 rotational matrix
	Matrix4 GetMatrix4() const { return mouseRotationMatrix; }

	/// Return the 3x3 rotational matrix, after all a rotational matrix is a 3x3!
	Matrix3 GetMatrix3() const { return Matrix3(mouseRotationMatrix);  }
};

}

#endif