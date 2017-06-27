#version 330

in  vec4 vVertex; 
in  vec4 vNormal;
in  vec2 vTexture;


out vec2 texCoords; /// Pass the texture coordinates to the fragment shader



uniform mat4 projMatrix;
uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;
uniform vec4 light_Pos;  /// not used right now but you'll need it

void main() {
	texCoords = vTexture; ///Pass them to the fragment shader
	gl_Position = projMatrix * modelViewMatrix * vVertex;
}