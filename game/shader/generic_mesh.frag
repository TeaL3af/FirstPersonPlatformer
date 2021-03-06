#version 330

smooth in vec2 v2_vertex_texcoord;
smooth in vec3 v3_vertex_normal;

uniform sampler2D tex2D_texture0;
uniform vec3 v3_world_light_vector;
uniform vec3 v3_world_light_diffuse;
uniform vec3 v3_world_light_ambient;

out vec4 v4_frag_color;

void main()
{
    vec4 v4_tex_color = texture(tex2D_texture0, v2_vertex_texcoord);
    float diffuseTerm = clamp(dot(v3_vertex_normal, normalize(v3_world_light_vector)), 0.0, 1.0);
    vec3 v3_frag_color = ((v3_world_light_ambient * v4_tex_color.xyz) + (v4_tex_color.xyz * v3_world_light_diffuse * diffuseTerm));
    v4_frag_color = vec4(v3_frag_color, 1.0);
}
