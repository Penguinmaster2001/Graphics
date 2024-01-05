# version 330 core

// in vec4 vertexColor;
in vec3 ourColor;
in vec2 vertPos;
uniform float sinTime;

out vec4 FragColor;

void main()
{
    FragColor = vec4(vertPos, 0.0f, 1.0f); //, resolution.x, resolution.y, 1.0);
}
