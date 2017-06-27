#version 330

out vec4 fragColor;

in vec3 viewNormal;
in vec3 viewLightDir;
in vec3 viewPosition;

const vec4 ambientColor = vec4(0.2, 0.2, 0.2, 1.0);
const vec4 lightColor = vec4(1,1,1,1);
const float lightIntensity = 0.1;

void main()
{
	vec4 albedo = vec4(viewNormal, 1);
	
	vec4 specCol = vec4(1,1,1,1);

	vec4 lightCol = lightColor * lightIntensity;

	vec3 light = normalize(viewLightDir);
	vec3 norm = normalize(viewNormal);
	vec3 look = normalize(-viewPosition);

	vec3 halfVec = normalize(light + look);
	float spec = pow(max(0.0, dot(norm, halfVec)), 16.0);


	float diffuse = max(0.0, dot(viewNormal, viewLightDir));

	fragColor = albedo * lightCol * diffuse + specCol * lightCol * spec + albedo * ambientColor;

	//fragColor = vec4(1,0,0,1);

}