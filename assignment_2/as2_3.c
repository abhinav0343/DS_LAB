#include<stdio.h>
#include<stdlib.h>
struct bankmgmt {
    int account_num;
    char name[50];
    float balance;
    char acc_type[20];
};
int main()
{
    struct bankmgmt ass;
    printf("enter the account number \n");
    scanf("%d",&ass.account_num);
    printf("enter account holders name \n");
    getchar();//before fgets you should use this compulsory.
    fgets(ass.name,sizeof(ass.name),stdin);
    printf("enter account balance \n");
    scanf("%f",&ass.balance);
    printf("enter account type \n");
    getchar();//before fgets you should use this compulsory.
    fgets(ass.acc_type,sizeof(ass.acc_type),stdin);  // inside of fgets you should not use semicolumns .
    printf("here we are providing you menu options enter the number according to mentioned below \n");
    printf(" 1 -> WITHDRAWL \n");
    printf(" 2 -> DEPOSIT \n");
    printf(" 3 -> DISPLAY BALANCE \n");
    printf(" 4 -> EXIT \n");
    int num,k;
    while( 1 ) // this is infinite loop it will exit on break .
    {
        printf("enter the number \n");
        scanf("%d",&num);
        k=num;
        if( k < 1 || k > 4)
        {
            printf("invalid number , please enter the number according to the menu mentioned above");
            continue;
        }
        else{
          switch (k)  //switch syntax
          {
            case 1 : printf("enter the amount you want to withdrwal\n");
                  float amount;
                  scanf("%f",&amount);
                  if(ass.balance < amount)
                    printf("INSUFFICIENT FUNDS \n");
                  else
                  {
                    printf("TRANSACTION SUCCESFUL \n");
                    printf("Please collect your amount \n");
                    float bal;
                    bal = ass.balance - amount ;
                    ass.balance = bal;
                    printf("your available balance is : %f \n",bal);
                  }  
                  break;
            case 2 : printf("enter the amount you want to deposit\n");
                  float dep;
                  scanf("%f",&dep);
                  printf("SUCCESFULL \n");
                  float dep_bal;
                  dep_bal = dep + ass.balance;
                  ass.balance = dep_bal;
                  printf("your current balance is : %f \n",dep_bal);
                  break;
            case 3 : printf("enter account number\n");
                  int acc;
                  scanf("%d",&acc);
                  if(acc == ass.account_num)
                  {
                    printf("your available balance is : %f \n",ass.balance);
                  }    
                  else
                  {
                    printf("INVALID ACCOUNT NUMBER \n");
                  }
                  break;
            case 4 : printf("exiting the application \n"); 
                    return 0; // for exiting the application.
           }
        }
    }
}