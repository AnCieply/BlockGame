#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "render/primitive.h"

static enum BlockType {
    AIR,
    GRASS,
    DIRT,
    STONE
};

static std::vector<glm::vec2> bTexCoords = {
    { 0,     0     },
    { 65535, 0     },
    { 0,     65535 },
    { 0,     65535 },
    { 65535, 0     },
    { 65535, 65535 }
};

static std::vector<glm::vec3> frontFaceVerts = {
    { 0.0f, 0.0f, 1.0f },
    { 1.0f, 0.0f, 1.0f }, 
    { 0.0f, 1.0f, 1.0f }, 
    { 0.0f, 1.0f, 1.0f }, 
    { 1.0f, 0.0f, 1.0f }, 
    { 1.0f, 1.0f, 1.0f }
};

static std::vector<Vertex> backFaceVerts = {
    { 1.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 1.0f, 1.0f, 0.0f },
    { 1.0f, 1.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 1.0f, 0.0f }
};

static std::vector<glm::vec3> leftFaceVerts = {
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 1.0f },
    { 0.0f, 1.0f, 0.0f },
    { 0.0f, 1.0f, 0.0f },
    { 0.0f, 0.0f, 1.0f },
    { 0.0f, 1.0f, 1.0f }
};

static std::vector<glm::vec3> rightFaceVerts = {
    { 1.0f, 0.0f, 1.0f },
    { 1.0f, 0.0f, 0.0f },
    { 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f },
    { 1.0f, 0.0f, 0.0f },
    { 1.0f, 1.0f, 0.0f }
};

static std::vector<glm::vec3> bottomFaceVerts = {
    { 0.0f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 1.0f },
    { 1.0f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 1.0f }
};

static std::vector<glm::vec3> topFaceVerts = {
    { 1.0f, 1.0f, 0.0f },
    { 0.0f, 1.0f, 0.0f },
    { 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f },
    { 0.0f, 1.0f, 0.0f },
    { 0.0f, 1.0f, 1.0f }
};
