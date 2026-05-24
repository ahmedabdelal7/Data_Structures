
#include <iostream>
#include "clsQueueLine.h"
int main()
{
    
    clsQueueLine PayBillsQueue("A0", 5);


    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();

    PayBillsQueue.PrintInfo();

    PayBillsQueue.PrintTicketsLineRTL();
    PayBillsQueue.PrintTicketsLineLTR();

    PayBillsQueue.ServeNextClient();
    cout << "\nPay Bills Queue after sereve next client:\n";
    PayBillsQueue.PrintInfo();

    PayBillsQueue.PrintTicketsLineRTL();
    PayBillsQueue.PrintTicketsLineLTR();


    PayBillsQueue.PrintAllTickets();
    system("pause>0");
    return 0;

}
