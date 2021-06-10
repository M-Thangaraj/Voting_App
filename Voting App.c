#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int voterid = 1;
int candidate1 = 0;
int candidate2 = 0;
int candidate3 = 0;
int nota = 0;
struct voting
{
    int age;
    char name[100];
    char sex[100];
    char mobileNumber[110];
    int aadhaarNumber;
    char password[100];
    int status;
    int polled;
}voterlist[10000];

void strongPassword()
{
    char temp[1000];
    int digit=0,alpha=0,char1=0;
    printf("Password must contain minimum of 8 characters with atleast 1 Upper case, 1 Special Character, 1 number\n");
    scanf(" %s",voterlist[voterid-1].password);
    strcpy(temp,voterlist[voterid-1].password);
    int l=strlen(voterlist[voterid-1].password);
    for(int i=0;i<l;i++)
    {
        if(isdigit(temp[i])!=0)
        {
            digit++;
        }
        else if(isalpha(temp[i])!=0)
        {
            if(isupper(temp[i]))
            alpha++;
        }
        else
        {
            char1++;
        }
    }
    if(!(digit>0 && alpha>0 && char1>0))
    {
        printf("Enter strong Password\n");
        strongPassword();
    }
}

int rePassword(int voterid1)
{
    char pasword[1000];
    printf("Enter your password\n");
    scanf("%s",pasword);
    if((strcmp((voterlist[voterid1-1].password),pasword))!=0)
    {
        int reenter;
        printf("Enter your correct password\nPress 1 to re-enter the password or press 0 to abord\n");
        scanf("%d",&reenter);
        if(reenter)
            rePassword(voterid1);
        else
            return 0;
    }
    else
    {
      return 1;
    }
}


int accCreate()
{
    printf("Enter your name:\n");
    scanf(" %[^\n]s",(voterlist[voterid-1].name));
    printf("Sex:\nMale\nFemale\nTransgender\n");
    scanf(" %s",(voterlist[voterid-1].sex));
    printf("Enter your Mobile Number\n");
    scanf(" %s",(voterlist[voterid-1].mobileNumber));
    printf("Enter your age\n");
    scanf("%d",&voterlist[voterid-1].age);
    while((voterlist[voterid-1].age)<18)
    {
        printf("Your age is less than 18,So You can't enroll for Voterid\n");
        return 0;
    }
    printf("Enter your Aadhaar Number\n");
    scanf("%d",&(voterlist[voterid-1].aadhaarNumber));
    printf("Enter the password\n");
    strongPassword();
    voterlist[voterid-1].status=1;
    voterlist[voterid-1].polled=0;

    printf("\n\nYour voter id is generated\n\nYour voter id is %d\nYour password is %s\n\n",voterid,voterlist[voterid-1].password);
    voterid++;
}

void userLogin()
{

    int voterid1,number;
    printf("Enter your voterid \n");
    scanf("%d",&voterid1);
    if(voterlist[voterid1-1].polled == 1)
    {
        printf("\nYou had already polled your vote!!\n\n");
        return;
    }
    while(voterid1 < 1 || voterid1 > voterid || ((voterlist[voterid1-1].status)!= 1))
    {
        printf("You don't have voterid\n");
        printf("Press 1 to enter your voter id again or press 0 to abord\n");
        scanf("%d",&number);
        if(number)
        {
            printf("Enter your correct voterid\n");
            scanf("%d",&voterid1);
        }
        else
        {
            printf("your process failed\n");
            return;
        }
    }
    if(rePassword(voterid1))
    {
        int num1;
        printf("         ------------Welcome-------------        \n");
        printf("   -------------Login successfully-------------      \n");
        printf("Name : %s\n",voterlist[voterid1-1].name);
        voterlist[voterid1-1].polled=1;
        int choice1;
        do
        {
            printf("Poll Your Voter\n1.Candidate1 \n2.Candidate2 \n3.Candidate3 \n4.NOTA\n");
            scanf("%d",&choice1);
            switch(choice1)
            {
                case 1:
                    candidate1++;
                    printf("You had succesfully voted for Candidate1\n");
                    break;
                case 2:
                    candidate2++;
                    printf("You had succesfully voted for Candidate2\n");
                    break;
                case 3:
                    candidate3++;
                    printf("You had succesfully voted for Candidate3\n");
                    break;
                case 4:
                    nota++;
                    printf("You had succesfully voted for nota\n");
                    break;
                default:
                    printf("Enter a valid choice:\n");
                    printf("Press 1 to go Home Screen or 0 to logout\n");
                    scanf("%d",&num1);
            }

        }while(num1);
    }
    else
    {
        printf("Your Process Failed\nThank You\n");
    }
}

void adminLogin()
{
    int voterid1,number,num;
    printf("Enter your voterid \n");
    scanf("%d",&voterid1);
    while(voterid1 < 1 || voterid1 > voterid || ((voterlist[voterid1-1].status)!= 1))
    {
        printf("You don't have voterid\n");
        printf("Press 1 to enter your voter id again or press 0 to abord\n");
        scanf("%d",&number);
        if(number)
        {
            printf("Enter your correct voterid\n");
            scanf("%d\n",&voterid1);
        }
        else
        {
            printf("your process failed\n");
            return;
        }
    }
    if(rePassword(voterid1))
    {
        printf("               ----------------Welcome Admin----------------        \n");
        printf("          -------------------Login successfully---------------     \n");
        printf("Name : %s\n",voterlist[voterid1-1].name);
        printf("The count of Canditate1 is %d\n",candidate1);
        printf("The count of Canditate2 is %d\n",candidate2);
        printf("The count of Canditate3 is %d\n",candidate3);
        printf("The count of nota is %d\n",nota);
        printf("Total polled vote is %d\n\n",candidate1+candidate2+candidate3+nota);
        printf("Press 1 to Logout\n");
        scanf("%d",&num);
    }
    else
    {
        printf("Your Process Failed\nThank You\n");
    }
}
int main()
{
    int choice,num=1;
    printf("           -----------Welcome to polling----------\n");
    do{
        printf("\nEnter your choice\n1.Create the voter id\n2.User Login\n3.Admin Login\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                accCreate();
                break;
            case 2:
                userLogin();
                //num = 0;
                break;
            case 3:
                adminLogin();
                break;
            default:
                printf("Enter the valid choice\n");
                printf("Enter 0 to abord or 1 to go Dashboard\n");
                scanf("%d",&num);
        }
    }while(num);
    return 0;
}
