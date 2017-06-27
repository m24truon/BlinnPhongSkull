#version 330

uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;

in vec4 vVertex;
in vec4 vNormal;

out vec3 viewNormal;
out vec3 viewLightDir;
out vec3 viewPosition;

const vec3 objLightDir = vec3(0,0,1);

void main()
{
	viewNormal = (normalMatrix * vNormal.xyz);
	viewLightDir = (modelViewMatrix * vec4(objLightDir, 0.0)).xyz;
	viewPosition = (modelViewMatrix * vVertex).xyz;

	gl_Position = projectionMatrix * modelViewMatrix * vVertex;
}