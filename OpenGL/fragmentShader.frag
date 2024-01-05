# version 330 core

// in vec4 vertexColor;
in vec3 ourColor;
in vec2 vertPos;
uniform float sinTime;

out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0f, 0.851f, 0.855f, 0.1f); //, resolution.x, resolution.y, 1.0);
}
