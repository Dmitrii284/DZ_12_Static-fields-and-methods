#pragma once
#include "Client.h"
#include <map>
#include <iostream>
#include <memory>

class System
{
private:
	static std::map<int, std::shared_ptr<Client>> m_DataBaseClients;// ������� map ��� ����� ��� int � �������� ����� ��������� �� ������� ������ Client 
	static uint32_t m_NumberClients; // ����� ������� (����������)
public:
	static void AddClient(const std::shared_ptr<Client>& client) // ������� ������� - ���� ���������� �������� . 
		//(��������� � ���� � ���� ���������� �� ������ ������� ������ Client 
	{
		m_NumberClients++;
		m_DataBaseClients.insert(std::make_pair(m_NumberClients, client));
	}

	static void ShowClients()
	{
		for (auto& client : m_DataBaseClients)// ����� ������ �� map � ������� ������ � ����� �������� .
		{
			std::cout << "Client " << client.first << "/" << m_DataBaseClients.size() << std::endl; // ������ ������(����� ������� ) �� ������ ���������� ��������
			client.second.get()->ShowData(); // � ��� ������� ������ � ������� ������� ShowData �� ������ ��������� client ����.
			std::cout << std::endl;
		}
	}
};

uint32_t System::m_NumberClients{0};
std::map<int, std::shared_ptr<Client>> System::m_DataBaseClients;