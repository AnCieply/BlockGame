#version 460 core

in vec4 oColor;
in vec2 oUV;

uniform sampler2D tex;

out vec4 FragColor;

void main() {
	FragColor = texture(tex, oUV);
}
