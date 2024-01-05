# version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform float sinTime;
uniform float cosTime;

out vec3 ourColor;
out vec2 vertPos;

void main()
{
    gl_Position = vec4(aPos.x - cosTime, aPos.y - sinTime, aPos.z, 1.0);

    ourColor = aColor;
    vertPos = aPos.xy;
}
