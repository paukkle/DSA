#pragma once

#include "Choices.h"
#include "DataStructures.h"


class BaseFlow
{
private:
	BaseChoice* m_choiceProvider;
	BaseDataStructure* ds;
	int m_choice;
public:
	virtual void runFlow() = 0;

};