# version 330 core

// in vec4 vertexColor;
in vec3 ourColor;
uniform vec2 resolution;

out vec4 FragColor;

void main()
{
    FragColor = vec4(ourColor, 1.0); //, resolution.x, resolution.y, 1.0);
}
