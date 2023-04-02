#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <string>
#include <glad.h>

class TextureLoader{
public:
    static GLuint LoadTexture(const std::string& path);
};

#endif
