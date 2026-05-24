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
	string _Prefix;
	short _AverageServeTime;
	short _TotalTickets = 0;
	short _ServerdClients = 0;
	short _WaitingClients = 0;

	struct stTicket
	{
		string TicketNumber;
		string DateTime;
		short WaitingClients;
		short ServerTimeInMinutes;
	};

	queue<stTicket> _QueueTicketLine;

	void _PrintTicketCard(stTicket Ticket) {
		cout << "\n" << left << setw(35) << ""
			<< "--------------------------------\n";

		cout << "\n" << left << setw(35) << "" << "\t\t  " << Ticket.TicketNumber<<"\n";
		cout << "\n" << left << setw(35) << "" << "\t" << Ticket.DateTime;
		cout << "\n" << left << setw(35) << "" << "\tWaiting Clients  = "<<Ticket.WaitingClients;
		cout << "\n" << left << setw(35) << "" << "\t   Serve Time In ";
		cout << "\n" << left << setw(35) << "" << "\t    " << Ticket.ServerTimeInMinutes << " Minutes.\n";

		cout << "\n" << left << setw(35) << ""
			<< "--------------------------------\n";
	}

	stTicket _FillTicketInfo(stTicket& Ticket) {

		Ticket.TicketNumber = _Prefix + to_string(_TotalTickets + 1);
		Ticket.DateTime = clsDate::GetSystemDateTimeString();
		Ticket.WaitingClients = _WaitingClients;
		Ticket.ServerTimeInMinutes = _AverageServeTime * _WaitingClients;
		return Ticket;
	}

public:
	clsQueueLine(string Prefix, short AverageServeTime) {

		_Prefix = Prefix;
		_AverageServeTime = AverageServeTime;
	}

	void IssueTicket() {

		stTicket Ticket;

		_FillTicketInfo(Ticket);		

		_QueueTicketLine.push(Ticket);

		_TotalTickets++;
		_WaitingClients++;
	}

	void ServeNextClient() {
		if (!_QueueTicketLine.empty()) {

			_QueueTicketLine.pop();

			_WaitingClients--;
			_ServerdClients++;
		}
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
		cout << "\n\t\t\t\t\tServed Clients  = " << _ServerdClients;
		cout << "\n\t\t\t\t\tWaiting Clients = " << _WaitingClients;

		cout << "\n";
		cout << "\n" << left << setw(35) << ""
			<< "--------------------------------\n" << endl;
	}

	void PrintTicketsLineRTL(){
	
		cout << "\n" << left << setw(30) << "" << "Tickets: ";

		if (!_QueueTicketLine.empty())
		{
			queue<stTicket> TempQueue = _QueueTicketLine;

			while (!TempQueue.empty())
			{
				cout << " " << TempQueue.front().TicketNumber;
				cout << " <-- ";
				TempQueue.pop();
			}

		}else
			cout << "\tNo tickets avilable in the system\n";

	}

	void PrintTicketsLineLTR(){
	
		cout << "\n" << left << setw(30) << "" << "Tickets: ";

		if (!_QueueTicketLine.empty())
		{
			queue<stTicket> TempQueue = _QueueTicketLine;
			stack<stTicket> TempStack;
			while (!TempQueue.empty())
			{
				TempStack.push(TempQueue.front());
				TempQueue.pop();
			}

			while (!TempStack.empty())
			{
				cout << " " << TempStack.top().TicketNumber;
				cout << " --> ";
				TempStack.pop();
			}
		}
		else		
			cout << "\tNo tickets avilable in the system\n";
	
	}

	void PrintAllTickets() {

		cout << "\n\n" << left << setw(35) << "" << "\t    ---Tickets---\n";


		if (_QueueTicketLine.empty()) {
			cout << "\n" << left << setw(20) << "" << "\t    There is no tickts Availabel in the system -:(\n";
			return;
		}

		queue<stTicket> TempQueue = _QueueTicketLine;

		while (!TempQueue.empty())
		{
			_PrintTicketCard(TempQueue.front());
			TempQueue.pop();
			cout << endl;
		}

	}

};
