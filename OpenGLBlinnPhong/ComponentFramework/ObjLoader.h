#ifndef OBJLOADER_H
#define OBJLOADER_H
#include <vector>
#include "Vector.h"

using namespace MATH;

namespace GAME {
	class ObjLoader {
	public:
		std::vector<Vec3> vertices;
		std::vector<Vec2> uvCoords;
		std::vector<Vec3> normals;

		/// C11 precautions 
		ObjLoader(const ObjLoader&) = delete;  /// Copy constructor
		ObjLoader(ObjLoader&&) = delete;       /// Copy operator
		ObjLoader& operator=(const ObjLoader&) = delete; /// Move constructor
		ObjLoader& operator=(ObjLoader&&) = delete;      /// Move operator

		ObjLoader(const char* path);
		bool loadOBJ(const char* path); 
	private:
		


	};
}
#endif