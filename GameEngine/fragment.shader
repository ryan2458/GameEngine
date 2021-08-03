#version 330 core
in vec2 TexCoords;
out vec4 color;

uniform sampler2D image;
uniform vec4 spriteColor;

void main()
{    
    vec4 finalColor = spriteColor * texture(image, TexCoords);
    
    if (finalColor.a < 0.05)
    {
        discard;
    }
    
    color = finalColor;
}  