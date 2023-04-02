#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "TextureLoader.h"
#include "stdexcept"

GLuint TextureLoader::LoadTexture(const std::string &path) {
    GLuint textureID;
    glGenTextures(1, &textureID);

    int width, height, nrChannels;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    if(!data){
        throw std::runtime_error("Failed to load texture file");
    }

    GLenum format;
    if(nrChannels == 1){
        format = GL_RED;
    }
    else if(nrChannels == 3){
        format = GL_RGB;
    }
    else if(nrChannels == 4){
        format = GL_RGBA;
    }

    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);

    return textureID;
}