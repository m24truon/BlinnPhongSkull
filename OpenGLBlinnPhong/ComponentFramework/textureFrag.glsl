#version 330

in  vec2 texCoords;
out vec4 fragColor;
uniform sampler2D myTexture0;  


void main() { 
	fragColor = texture2D(myTexture0,texCoords);
}