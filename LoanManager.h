#ifndef LOAN_H
#define LOAN_H

#include "MemberManager.h"
#include "BookManager.h"
#include "Date.h"
#include "List.h"

typedef enum {
   OVERDUE,ACTIVE
} Status;

struct Loan{
    Book* title;
    Member* member;
    Date dateOfReturn;
    Status status;
};

struct LoanManager {
    List loanList;
};


LoanManager* initLoanManager();
Loan* initLoan();
void addNewLoan(BookManager* bookManager, LoanManager* loanManager, MemberManager* memberManager);
int loanBook(BookManager* bookManager, LoanManager* loanManager, Book* title, Member* member);
void returnBook(BookManager* bookManager, LoanManager* loanManager, MemberManager* memberManager);
int isInLoanList(LoanManager* loanManager, char* bookName);
int removeLoanFromMember(LoanManager* loanManager, Book* title, Member* member);
int addLoanToLoanArr(Member* member, Loan* loan);
int isLoanedByMember(Loan* loanArr[], Book* title);
void printLoan(Loan* loan);
void printLoanList(LoanManager* manager);
void printLoanArrOfMember(MemberManager* manager, int memberNumber);
int isOverdue(Date* date);
void freeLoan(Loan* loan);
int freeLoanArr(Loan* loanArr[]);
int writeLoanManagerToText(char* fName, int count, LoanManager* manager);
List* readLoanManagerFromText(char* fName, LoanManager* manager);
int writeLoanManagerToBinary(char* fName, int count, LoanManager* manager);
List* readLoanManagerFromBinary(char* fName, LoanManager* manager);



#endif // !LOAN_H



