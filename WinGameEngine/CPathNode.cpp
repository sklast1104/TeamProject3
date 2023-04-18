#include "stdafx.h"
#include "CPathNode.h"

CPathNode::CPathNode()
	: leftNode{ nullptr }
	, rightNode{ nullptr }
{
	nodeType = L"CPathNode";
}

CPathNode::CPathNode(const wstring& rKey, const wstring& rPath)
	: leftNode{ nullptr }
	, rightNode{ nullptr }
{
	this->rKey = rKey;
	this->rPath = rPath;

	nodeType = L"CPathNode";
}

CPathNode::~CPathNode()
{

}