//STANDARD

attribute lowp vec4 vertex;

attribute lowp vec2 texcoord;

attribute lowp vec3 normal;

uniform highp mat4 c_matrix;

uniform highp mat4 p_matrix;

uniform highp mat4 mv_matrix;

uniform highp mat4 mvp_matrix;

uniform highp mat3 norm_matrix;

varying lowp vec2 texc;

varying lowp vec3 norm;







void main(void)

{

	texc = texcoord;
	norm = normalize(vec3(norm_matrix * normal));
	gl_Position =  mvp_matrix * vertex;

}