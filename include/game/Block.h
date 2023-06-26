#pragma once

#include <vector>

#include "render/primitive.h"

static std::vector<Vertex> frontFaceVerts = {
    { 0.0f, 0.0f, 1.0f, 0, 0 },
    { 1.0f, 0.0f, 1.0f, 65535, 0 },
    { 0.0f, 1.0f, 1.0f, 0, 65535 },
    { 0.0f, 1.0f, 1.0f, 0, 65535 },
    { 1.0f, 0.0f, 1.0f, 65535, 0 },
    { 1.0f, 1.0f, 1.0f, 65535, 65535 }
};

static std::vector<Vertex> backFaceVerts = {
    { 1.0f, 0.0f, 0.0f, 0, 0 },
    { 0.0f, 0.0f, 0.0f, 65535, 0 },
    { 1.0f, 1.0f, 0.0f, 0, 65535 },
    { 1.0f, 1.0f, 0.0f, 0, 65535 },
    { 0.0f, 0.0f, 0.0f, 65535, 0 },
    { 0.0f, 1.0f, 0.0f, 65535, 65535 }
};

static std::vector<Vertex> leftFaceVerts = {
    { 0.0f, 0.0f, 0.0f, 0, 0 },
    { 0.0f, 0.0f, 1.0f, 65535, 0 },
    { 0.0f, 1.0f, 0.0f, 0, 65535 },
    { 0.0f, 1.0f, 0.0f, 0, 65535 },
    { 0.0f, 0.0f, 1.0f, 65535, 0 },
    { 0.0f, 1.0f, 1.0f, 65535, 65535 }
};

static std::vector<Vertex> rightFaceVerts = {
    { 1.0f, 0.0f, 1.0f, 0, 0 },
    { 1.0f, 0.0f, 0.0f, 65535, 0 },
    { 1.0f, 1.0f, 1.0f, 0, 65535 },
    { 1.0f, 1.0f, 1.0f, 0, 65535 },
    { 1.0f, 0.0f, 0.0f, 65535, 0 },
    { 1.0f, 1.0f, 0.0f, 65535, 65535 }
};

static std::vector<Vertex> bottomFaceVerts = {
    { 0.0f, 0.0f, 0.0f, 0, 0 },
    { 1.0f, 0.0f, 0.0f, 65535, 0 },
    { 0.0f, 0.0f, 1.0f, 0, 65535 },
    { 0.0f, 0.0f, 1.0f, 0, 65535 },
    { 1.0f, 0.0f, 0.0f, 65535, 0 },
    { 1.0f, 0.0f, 1.0f, 65535, 65535 }
};

static std::vector<Vertex> topFaceVerts = {
    { 1.0f, 1.0f, 0.0f, 0, 0 },
    { 0.0f, 1.0f, 0.0f, 65535, 0 },
    { 1.0f, 1.0f, 1.0f, 0, 65535 },
    { 1.0f, 1.0f, 1.0f, 0, 65535 },
    { 0.0f, 1.0f, 0.0f, 65535, 0 },
    { 0.0f, 1.0f, 1.0f, 65535, 65535 }
};

static std::vector<std::vector<Vertex>> blockVerts = {
    frontFaceVerts,
    backFaceVerts,
    leftFaceVerts,
    rightFaceVerts,
    topFaceVerts,
    bottomFaceVerts
};
