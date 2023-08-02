#include<iostream>
#include<map>
#include<memory>
#include "System.h"
/*
Задание 1
создать класса пользователь(клиент) для онлайн фирмы
который будет позволять узнавать количество текущих
клиентов в программе
комментарии:
клиент представлен именем, фамилией, адресом
и состоянием счёта.
в системе есть объекты в фоновой обработке(хранятся
гдето в векторе, листе, итп) и объекты в активной
работе(не в оснновной коллекции)
данные объекты должны влиять на количество клиентов
а временные объекты не должны вызывать такого эффекта
*/

//Пишем тип статичного поля и где оно находиться
//Каждое статичное поле нужно так инициализировать


int main()
{
	setlocale(LC_ALL, "Rus");
	std::shared_ptr<Client>client1 = std::make_shared < Client>("John", "Alex", "Sirotina", 200.0f);
	std::shared_ptr<Client>client2 = std::make_shared < Client>("Yehanson", "Barak", "Sirotina", 26500.698f);
	std::shared_ptr<Client>client3 = std::make_shared < Client>("Boser", "Leon", "Pertov", 2087890.70f);
	std::shared_ptr<Client>client4 = std::make_shared < Client>("Sidorov", "Herloc", "Ubuntu", 3353500.8840f);
	std::shared_ptr<Client>client5 = std::make_shared < Client>("Fredi", "Leroi", "Renatovna", 50230.0f);

	System::AddClient(client1);
	System::AddClient(client2);
	System::AddClient(client3);
	System::AddClient(client4);
	System::AddClient(client5);
	System::ShowClients();
	return 0;
}