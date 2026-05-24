#pragma once
#include<iostream>
#include"string"
#include<queue>
#include<stack>
#include"clsDate.h"
using namespace std;
class clsQueueLine
{

private:

	string _Prefix= "";
	short _TotalTickets = 0;
	short _AverageServeTime =0;

	class clsTicket {
	private:
		short _Number;
		string _Prefix;
		string _TicketTime;
		short _WaitingClients;
		short _AverageServeTime;
		short _ExpectedServeTime;
	public:
		clsTicket(string Prefix, short Number, short WatingClients, short AverageServeTime) {

			_Prefix = Prefix;
			_Number = Number;
			_TicketTime = clsDate::GetSystemDateTimeString();
			_WaitingClients = WatingClients;
			_AverageServeTime = AverageServeTime;

		}

		string Prefix() { return _Prefix; }

		short Number() { return _Number; }

		string FullNumber() { return _Prefix + to_string(_Number); }

		short WaitingClients() { return _WaitingClients; };

		short AverageServeTime() { return _AverageServeTime; }

		string TicketTime() { return _TicketTime; }
		
		short ExpectedServeTime() { return _AverageServeTime * _WaitingClients; }

		void Print() {
			cout << "\n" << left << setw(35) << ""
				<< "--------------------------------\n";

			cout << "\n" << left << setw(35) << "" << "\t\t  " << FullNumber() << "\n";
			cout << "\n" << left << setw(35) << "" << "\t" << _TicketTime;
			cout << "\n" << left << setw(35) << "" << "\tWaiting Clients  = " << _WaitingClients;
			cout << "\n" << left << setw(35) << "" << "\t   Serve Time In ";
			cout << "\n" << left << setw(35) << "" << "\t    " << ExpectedServeTime() << " Minutes.\n";

			cout << "\n" << left << setw(35) << ""
				<< "--------------------------------\n";
		}
	};

	queue<clsTicket> QueueLine;

public:
	clsQueueLine(string Prefix, short AverageServeTime) {

		_Prefix = Prefix;
		_TotalTickets = 0;
		_AverageServeTime = AverageServeTime;
	}

	void IssueTicket() {

		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime);
		QueueLine.push(Ticket);

	}

	short WaitingClients() {
		return QueueLine.size();
	}

	bool ServeNextClient() {
		if (QueueLine.empty())
			return false;

		QueueLine.pop();
		return true;
	}

	string WhoIsNext() {
		if (QueueLine.empty())
			return"No Clients Left";
		else
			return QueueLine.front().FullNumber();
	}

	short ServedClients() {
		return _TotalTickets - WaitingClients();
	}

	void PrintInfo() {
		cout << "\n";
		cout << "" << left << setw(35) <<""
			<< "--------------------------------\n";

		cout << "\n\t\t\t\t\t     Queue Info\n";

		cout << "\n" << left << setw(35)<<""
			<< "--------------------------------\n";

		cout << "\n\t\t\t\t\tPrefix          = " << _Prefix;
		cout << "\n\t\t\t\t\tTotal Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t\t\tServed Clients  = " << ServedClients();
		cout << "\n\t\t\t\t\tWaiting Clients = " << WaitingClients();

		cout << "\n";
		cout << "\n" << left << setw(35) << ""
			<< "--------------------------------\n" << endl;
	}

	void PrintTicketsLineRTL(){
	
		cout << "\n" << left << setw(30) << "" << "Tickets: ";

		if (!QueueLine.empty())
		{
			queue<clsTicket> TempQueue = QueueLine;

			while (!TempQueue.empty())
			{
				cout << " " << TempQueue.front().FullNumber();
				cout << " <-- ";
				TempQueue.pop();
			}

		}else
			cout << "\tNo tickets avilable in the system\n";

	}

	void PrintTicketsLineLTR(){
	
		cout << "\n" << left << setw(30) << "" << "Tickets: ";

		if (!QueueLine.empty())
		{
			queue<clsTicket> TempQueue = QueueLine;
			stack<clsTicket> TempStack;
			while (!TempQueue.empty())
			{
				TempStack.push(TempQueue.front());
				TempQueue.pop();
			}

			while (!TempStack.empty())
			{
				cout << " " << TempStack.top().FullNumber();
				cout << " --> ";
				TempStack.pop();
			}
		}
		else		
			cout << "\tNo tickets avilable in the system\n";
	
	}

	void PrintAllTickets() {

		cout << "\n\n" << left << setw(35) << "" << "\t    ---Tickets---\n";


		if (QueueLine.empty()) {
			cout << "\n" << left << setw(20) << "" << "\t    There is no tickts Availabel in the system -:(\n";
			return;
		}

		queue<clsTicket> TempQueue = QueueLine;

		while (!TempQueue.empty())
		{
			TempQueue.front().Print();
			TempQueue.pop();
			cout << endl;
		}

	}

};
