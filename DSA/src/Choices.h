#pragma once


#include <string>
#include <vector>


class BaseChoice
{
private:
	std::vector<std::string> m_choices;
	virtual int getNumChoices() = 0;
public:
	virtual int getChoice() = 0;

};


class BSTChoices : BaseChoice
{
private:
	std::vector<std::string> m_choices;
	int getNumChoices() override;

public:
	BSTChoices();
	int getChoice() override;
};


