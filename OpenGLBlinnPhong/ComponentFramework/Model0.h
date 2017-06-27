#ifndef MODEL0_H
#define MODEL0_H
#include <GL/glew.h>
#include "Model.h"

namespace GAME {

/// Forward declarations;
class Shader; 
class QuadSphere;

class Model0 :public Model {
public:
	Model0();


	Model0(const Model0&) = delete;
	Model0(Model0&&) = delete;
	Model0& operator = (const Model0&) = delete;
	Model0& operator = (Model0&&) = delete;

	virtual bool OnCreate() ;
	virtual void OnDestroy();
	virtual void Update(const float deltaTime);
	virtual void Render(const Matrix4& projectionMatrix, const Matrix4& modelViewMatrix, const Matrix3& normalMatrix) const;
	virtual ~Model0();

	void SetLightPos(const Vec3& );
private:
             
	Shader *shader;
	GLuint vbo;
	GLuint vao;
	GLint verticiesID;
	GLint normalsID;
	GLint uvCoordsID; 

	GLint projectionMatrixID;
	GLint modelViewMatrixID;
	GLint normalMatrixID;
	GLint lightPosID;
	Vec3 lightPos;
};
}
#endif
