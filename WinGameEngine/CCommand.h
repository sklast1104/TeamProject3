#pragma once
class CCommand abstract
{
public :

	CCommand() {}
	virtual ~CCommand() {}

	virtual void Execute() = 0;
};

