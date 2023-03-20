#version 460 core

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aUV;

uniform mat4 viewproj;

out vec4 oColor;
out vec2 oUV;

void main() {
	gl_Position = vec4(aPosition, 1.0) * viewproj;
	oColor = aColor;
	oUV = aUV;
}
