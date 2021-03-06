#version 330

in vec2 v2_position;

uniform mat4 m_MVP;

smooth out vec2 v2_vertex_texcoord;

void main()
{
	v2_vertex_texcoord = vec2(v2_position.x, v2_position.y);
	gl_Position = m_MVP * vec4(v2_position.x, v2_position.y, 0.0, 1.0);
}
