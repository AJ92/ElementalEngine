//SIMPLE DISCARD

attribute lowp vec4 vertex;

attribute lowp vec2 texcoord;

uniform highp mat4 mvp_matrix;

varying lowp vec2 texc;


void main(void)

{

	texc = texcoord;

	gl_Position =  mvp_matrix * vertex;

}