//SIMPLE DISCARD

uniform lowp sampler2D sampler0;

varying lowp vec2 texc;

void main(void)

{

	lowp vec4 color = texture2D(sampler0, texc.st).rgba;

	if(color[3] < 0.95){

		discard;

	}	
	
	gl_FragColor = color;

	
}
