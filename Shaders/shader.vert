#version 450 	// Use GLSL 4.5

layout(location = 0) out vec3 fragColour;	// Output colour for vertex (location is required)

// Traingle vertex positions (will put in to vertex buffer later)
vec3 positions[3] = vec3[](
	vec3(0.0, -0.4, 0.0),
	vec3(0.4, 0.4, 0.0),
	vec3(-0.4, 0.4, 0.0)
);

// Traingle vertex colour
vec3 colour[3] = vec3[](
	vec3(1.0, 0.0, 0.0),
	vec3(0.0, 1.0, 0.0),
	vec3(0.0, 0.0, 1.0)
);

void main(){
	gl_Position = vec4(positions[gl_VertexIndex], 1.0);
	fragColour = colour[gl_VertexIndex];
}