#pragma once
#include <vector>
#include <glm/glm.hpp>

const int cWidth = 16;
const int cDepth = 16;
const int cHeight = 256;
const int cMaxBlocks = 65536;

class Chunk {
public:
	Chunk();
private:
	glm::vec2 m_Position;
	std::vector<char> m_Blocks;
};
