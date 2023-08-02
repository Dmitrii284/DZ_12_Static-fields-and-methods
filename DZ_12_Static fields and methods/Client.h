#pragma once

class Client
{
private:
	std::string m_FirstName;
	std::string m_LastName;
	std::string m_Adress;
	float m_Bill;
public:
	Client(std::string firstName, std::string lastName, std::string adress, float bill) :
		m_FirstName{ std::move(firstName) }, m_LastName{ std::move(lastName) }, m_Adress{ std::move(adress) }, m_Bill{ std::move(bill) }
	{
	}

	void ShowData()
	{
		std::cout << "First name: " << m_FirstName << std::endl;
		std::cout << "Last name: " << m_LastName << std::endl;
		std::cout << "Adress: " << m_Adress << std::endl;
		std::cout << "Bill: " << m_Bill << std::endl << std::endl;
	}
};