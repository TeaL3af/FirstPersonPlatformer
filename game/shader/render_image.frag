#version 330

smooth in vec2 v2_vertex_texcoord;

uniform sampler2D tex2D_texture0;

out vec4 v4_frag_color;

void main()
{
    v4_frag_color = texture(tex2D_texture0, v2_vertex_texcoord);
}
