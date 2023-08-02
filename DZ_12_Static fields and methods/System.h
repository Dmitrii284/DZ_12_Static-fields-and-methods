#pragma once
#include "Client.h"
#include <map>
#include <iostream>
#include <memory>

class System
{
private:
	static std::map<int, std::shared_ptr<Client>> m_DataBaseClients;// Создаем map где ключь это int а значение умные указатели на Объекты класса Client 
	static uint32_t m_NumberClients; // Номер клинета (уникальный)
public:
	static void AddClient(const std::shared_ptr<Client>& client) // Создали функцию - член Добавления КЛИЕНТОВ . 
		//(ПРИНИМАЕТ В СЕБЯ В ВИДЕ АРГУМЕНТОВ по ссылке оБЪЕКТЫ КЛАССА Client 
	{
		m_NumberClients++;
		m_DataBaseClients.insert(std::make_pair(m_NumberClients, client));
	}

	static void ShowClients()
	{
		for (auto& client : m_DataBaseClients)// Бежип циклом по map и выводим размер и самих клиентов .
		{
			std::cout << "Client " << client.first << "/" << m_DataBaseClients.size() << std::endl; // Первый клиент(номер клиента ) из общего количества клиентов
			client.second.get()->ShowData(); // А тут Выводим данные о клиенте методом ShowData По нашему итератору client мапа.
			std::cout << std::endl;
		}
	}
};

uint32_t System::m_NumberClients{0};
std::map<int, std::shared_ptr<Client>> System::m_DataBaseClients;