/*
  simple terminal based banking app
  supports viewing account balance, adding new transaction, 
  transfer to another account, see transfer history and so on
*/

#include <stdio.h>
#include <stdbool.h>

# define MAX_AMOUNT_ADD 256000

typedef struct{
   int transaction_id;
   int transaction_amount;
   char transaction_to[256];
} Transaction;

Transaction transactions[256];
int total_transactions = 0;
int balance = 0;

void addNewBalance(void);
void checkBalance(void);
void transfer(void);
void showTransferHistory(void);

int main(void){
  printf("----Welcome to the C Banking App----");
  
  while(true){
    printf("\n");
    printf("\n1. Add a new balance\n");
    printf("2. Check the balance\n");
    printf("3. Transfer money to someone\n");
    printf("4. Show transfer history\n");
    printf("5. Quit\n");
    printf("Enter your choice:");
    
    int resp;
    scanf("%i", &resp);

    if(resp == 5){
      break;
    }

    switch(resp){
      case 1:{
        addNewBalance();
        break;
      }
      case 2:{
        checkBalance();
        break;
      }
      case 3:{
        transfer();
        break;
      }
      case 4:{
        showTransferHistory();
        break;
      }
      default:{
        printf("\nInvalid command");
        break;
      }
    }
  }


  return 0;
}

void addNewBalance(void){
  int amount;
  printf("\nEnter amount you want to add:");
  scanf("%i", &amount);

  if(amount >= MAX_AMOUNT_ADD){
    printf("\nUnable to add, Maximum amount you can add at once is: %i", MAX_AMOUNT_ADD);
  }else{
    balance+=amount;
    printf("\nSuccess!");
  }
}

void checkBalance(void){
  printf("\n Your balance is $%i", balance);
}

void transfer(void){
  Transaction new_transaction;

  printf("\nEnter transaction amount:");
  scanf("%i", &new_transaction.transaction_amount);

  if(new_transaction.transaction_amount > balance){
    printf("\nTransaction failed. You don't have enough balance :(");
  }else{
    printf("\nEnter name of person you want to send:");
    scanf("%s", new_transaction.transaction_to);

    transactions[total_transactions++] = new_transaction;
    balance-= new_transaction.transaction_amount;
    
    printf("\nSuccesfully completed the transaction, Your new balance is $%i", balance);
  }
}

void showTransferHistory(void){
  if(total_transactions == 0){
    printf("\nNo any transactions so far");
    return;
  }

  printf("\nHere are the transactions you've done so far:");
  for(int i=0;i<total_transactions;i++){
    printf("\nTransfered $%i to %s", transactions[i].transaction_amount, transactions[i].transaction_to);
  }
}
