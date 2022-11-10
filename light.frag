#version 330 core

out vec4 FragColor;

uniform vec4 lightColor;

void main()
{	

	//set the color of shape
	FragColor = lightColor;
}