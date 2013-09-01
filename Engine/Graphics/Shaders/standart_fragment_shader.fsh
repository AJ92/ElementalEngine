//STANDARD

uniform lowp sampler2D sampler0;

uniform lowp sampler2D sampler1;

varying lowp vec2 texc;

//old directional light shader
varying lowp vec3 norm;





void main(void)

{

	lowp vec3 lightcolor = vec3(1.4,1.3,1.2);

	lowp vec3 lightdir = vec3(0.0,1.0,1.0);

	lowp vec3 lightnorm = normalize(lightdir);

	lowp vec3 normal = normalize(norm);

	lowp float intensity = max(dot(lightnorm, normal),0.0);

	lowp vec3 calcColor = vec3(0.2,0.2,0.2) + lightcolor * intensity;



	lowp vec4 color0 = texture2D(sampler0, texc.st).rgba;

	lowp vec4 color1 = texture2D(sampler1, texc.st).rgba;


	//specularity map intensity

	lowp float specular_intensity = 0.9*(1.0-cos(3.14159265*intensity));

	lowp float multip = ((color1[0] + color1[1] + color1[2]) / 3.0) * specular_intensity;

	gl_FragColor = vec4(color0.rgb*calcColor+multip, color0.a);

	

}
