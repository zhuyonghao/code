#include "ClientData.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;
/*

int main()
{
	ofstream outCredit("credit.dat", ios::out | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	ClientData blankClient;
	for (int i = 0; i < 100; ++i)
		outCredit.write(reinterpret_cast<const char*>(&blankClient),
			sizeof(ClientData));
}


int main()
{
	int accountNumber;
	string lastName;
	string firstName;
	double balance;

	fstream outCredit("credit.dat", ios::in | ios::out | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Enter account number (1 to 100, 0 to end input)\n? ";
	ClientData client;
	cin >> accountNumber;
	while (accountNumber > 0 && accountNumber <= 100)
	{
		cout << "Enter lastname, firstName, balance\n? ";
		cin >> lastName;
		cin >> firstName;
		cin >> balance;

		client.setAccountNumber(accountNumber);
		client.setLastName(lastName);
		client.setFirstName(firstName);
		client.setBalance(balance);

		//找到写入的位置(从0的位置开始写入数据)
		outCredit.seekp((client.getAccountNumber()-1) * sizeof(ClientData));
		//写入到文件中
		outCredit.write(reinterpret_cast<const char*>(&client),sizeof(client));
		cout << "Enter account number\n? ";
		cin >> accountNumber;
	}
}


void outputLine(ostream&, const ClientData&);

int main()
{
	ifstream inCredit("credit.dat", ios::in | ios::binary);

	if (!inCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	cout << left << setw(10) << "Account" << setw(16)
		<< "Last Name" << setw(11) << "First Name" 
		<< setw(10) << right << "Balance" << endl;

	ClientData client;
	inCredit.read(reinterpret_cast<char*>(&client),
		sizeof(ClientData));
	while (inCredit && !inCredit.eof())
	{
		if (client.getAccountNumber() != 0)
			outputLine(cout, client);
		inCredit.read(reinterpret_cast<char*>(&client),
			sizeof(ClientData));
	}
}

void outputLine(ostream& output, const ClientData& record)
{
	output << left << setw(10) << record.getAccountNumber()
		<< setw(16) << record.getLastName()
		<< setw(11) << record.getFirstName()
		<< setw(10) << setprecision(2) << right << fixed
		<< showpoint << record.getBalance() << endl;
}
*/
int enterChoice();
void createTextFile(fstream&);
void updateRecord(fstream&);
void newRecord(fstream&);
void deleteRecord(fstream&);
void outputLine(ostream&, const ClientData&);
int getAccount(const char* const);

enum Choices {PRINT = 1, UPDATE, NEW, DELETE ,END};

int main()
{
	fstream inOutCredit("credit.dat", ios::out | ios::in | ios::binary);

	if (!inOutCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}
	int choice;
	while ((choice = enterChoice()) != END)
	{
		switch (choice)
		{
		case PRINT:
			createTextFile(inOutCredit);
			break;
		case UPDATE:
			updateRecord(inOutCredit);
			break;
		case NEW:
			newRecord(inOutCredit);
			break;
		case DELETE:
			deleteRecord(inOutCredit);
			break;
		default:
			cerr << "Incorrect choice" << endl;
			break;
		}
		inOutCredit.clear();
	}
}

int enterChoice()
{
	cout << "\nEnter your choice" << endl
		<< "1 - store a formatted text file of accounts" << endl
		<< "    called \"print.txt\" for printing" << endl
		<< "2 - update an account" << endl
		<< "3 - add a new account" << endl
		<< "4 - deelte an account" << endl
		<< "5 - end program\n? ";
	int menuChoice;
	cin >> menuChoice;
	return menuChoice;
}

void createTextFile(fstream& readFromFile)
{
	ofstream outPrintFile("print.txt", ios::out);

	if (!outPrintFile)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	outPrintFile << left << setw(10) << "Account" << setw(16)
		<< "Last Name" << setw(11) << "FirstName" << right
		<< setw(10) << "Balance" << endl;
	readFromFile.seekg(0);
	ClientData client;
	readFromFile.read(reinterpret_cast<char*>(&client),
		sizeof(ClientData));
	while (!readFromFile.eof())
	{
		if (client.getAccountNumber() != 0)
			outputLine(outPrintFile, client);
		readFromFile.read(reinterpret_cast<char*>(&client),
			sizeof(ClientData));
	}
}

void updateRecord(fstream& updateFile)
{
	int accountNumber = getAccount("Enter account to update");
	updateFile.seekg((accountNumber - 1) * sizeof(ClientData));
	ClientData client;
	updateFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
	if (client.getAccountNumber() != 0)
	{
		outputLine(cout, client);
		cout << "\nEnter charge (+) or payment (-): ";
		double transaction;
		cin >> transaction;
		double oldBalance = client.getBalance();
		client.setBalance(oldBalance + transaction);
		outputLine(cout, client);
		updateFile.seekp((accountNumber - 1) * sizeof(ClientData));
		updateFile.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));

	}
	else
		cerr << "Account #" << accountNumber
		<< "has no information." << endl;
}

void newRecord(fstream& insertInFile)
{
	int accountNumber = getAccount("Enter new account number");
	insertInFile.seekg((accountNumber - 1) * sizeof(ClientData));

	ClientData client;
	insertInFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
	if (client.getAccountNumber() == 0)
	{
		string lastName;
		string firstName;
		double balance;

		cout << "Enter lastName, firstName, balance\n? ";
		cin >> setw(15) >> lastName;
		cin >> setw(10) >> firstName;
		cin >> balance;
		client.setLastName(lastName);
		client.setFirstName(firstName);
		client.setBalance(balance);
		client.setAccountNumber(accountNumber);
		insertInFile.seekp((accountNumber - 1) * sizeof(ClientData));
		insertInFile.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));

	}
	else
	{
		cerr << "Account #" << accountNumber
			<< " already contains information." << endl;
	}
}

void deleteRecord(fstream& deleteFromFile)
{
	int accountNumber = getAccount("Enter account to delete");
	deleteFromFile.seekg((accountNumber - 1) * sizeof(ClientData));
	ClientData client;
	deleteFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

	if (client.getAccountNumber() != 0)
	{
		ClientData blankClient;
		deleteFromFile.seekp((accountNumber - 1) * sizeof(ClientData));
		deleteFromFile.write(reinterpret_cast<const char*>(&blankClient), sizeof(ClientData));
		cout << "Account #" << accountNumber << " deleted.\n";
	}
	else
		cerr << "Account #" << accountNumber << " is empty.\n";
}

void outputLine(ostream& output, const ClientData& record)
{
	output << left << setw(10) << record.getAccountNumber()
		<< setw(16) << record.getLastName()
		<< setw(11) << record.getFirstName()
		<< setw(10) << setprecision(2) << right << fixed
		<< showpoint << record.getBalance() << endl;
}

int getAccount(const char* const prompt)
{
	int accountNumber;
	do
	{
		cout << prompt << " (1 - 100): ";
		cin >> accountNumber;
	} while (accountNumber < 1 || accountNumber > 100);
	return accountNumber;
}