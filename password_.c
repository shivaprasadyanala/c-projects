#include <unistd.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>


/**void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}**/
COORD coord ={0,0};
void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
char catagories[][15]={"computer","mechanical","IT","civil","electrical","economics"};

struct meredate{
int dd,mm,yy;
};
struct books
{
char auther[20];
float price;
int id;
int quntity;
int count;
char name[20];
int rackno;
char stname[20];
char *cat ;
struct meredate issued;
struct meredate due_date;
};

struct books a;

int i;
FILE *fp,*ft,*fs;


int checkid(int);
void t(void);
void main_menu(void);
int getdata(void);
void main_menu()
{
    system("cls");
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Main menu \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2 1.Add a book.");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2 2.Delete a book.");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2 3.Search for a book.");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2 4.List of  book.");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2 5.Edit books record.");
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2 6.Issue a book.");
    gotoxy(20,19);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2 7.Close Application.");
    gotoxy(20,21);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,22);
    t();
    gotoxy(25,23);
    printf("Enter your choice:");
    //scanf("%d",&ch);
    switch(getch())
    {
        case '1':addbook();//printf("hello");
        break;
        /**case 2:delebook();
        break;
        case 3:searchbook();
        break;
        case 4:listbook();
        break;
        case 5:editbookrecord();
        break;
        case 6:issuebook();
        break;
        case 7:closeapp();
        break;
        default :printf("Invalid choice");**/
    }
}
void addbook()
{
    system("cls");
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT CATGORIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2\xB2 1.COMPUTER");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2\xB2 2.MECHANICAL");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2\xB2 3.IT");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2\xB2 4.CIVIL");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2\xB2 5.ELECTRONICS");
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2\xB2 6.ECONOMICS");
    gotoxy(20,19);
    printf("\xDB\xDB\xDB\xDB\xB2\xB2 7.Main menu");
    gotoxy(20,21);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,22);
    printf("Enter the choice:");
    scanf("%d",&i);
    if(i==7)
    main_menu();
    system("cls");
    fp=fopen("file1.txt","w");
    if(getdata()==1)
    {
        a.cat=catagories[i-1];
        fseek(fp,0,SEEK_END);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        gotoxy(20,17);
        printf("one book got added...");
        gotoxy(20,18);
        printf("Do you want to add new book(y/n)");
        int n;
        if(getch()==n)
            main_menu();
        else
        {
          system("cls");
          addbook();

        }


    }



}
void t(void)
{
    time_t t;
    time(&t);
    printf("Date and time is %s",ctime(&t));
}
char Password[20]="shiva";

int getdata()
{
    int t;
    gotoxy(20,4);
    printf("Enter the information here:");
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,6);printf("\xB2");gotoxy(43,6);printf("\xB2");
    gotoxy(20,7);printf("\xB2");gotoxy(43,7);printf("\xB2");
    gotoxy(20,8);printf("\xB2");gotoxy(43,8);printf("\xB2");
    gotoxy(20,9);printf("\xB2");gotoxy(43,9);printf("\xB2");
    gotoxy(20,10);printf("\xB2");gotoxy(43,10);printf("\xB2");
    gotoxy(20,11);printf("\xB2");gotoxy(43,11);printf("\xB2");
    gotoxy(20,12);printf("\xB2");gotoxy(43,12);printf("\xB2");
    //gotoxy(20,13);printf("\xB2");gotoxy(43,13);printf("\xB2");
    //gotoxy(20,14);printf("\xB2");gotoxy(43,14);printf("\xB2");
    //gotoxy(20,15);printf("\xB2");gotoxy(43,15);printf("\xB2");
    gotoxy(20,13);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(21,6);
    printf(" catogory:");
    printf(" %s",catagories[i-1]);
    gotoxy(21,7);
    printf(" book ID:");
    scanf("%d",&t);
    if(checkid(t)==0)
    {
      printf("\aThis book ID already exists\a");
      getch();
      main_menu();
    }
    a.id=t;
    gotoxy(21,8);
    printf(" Book name:");
    scanf("%s",&a.name);
    gotoxy(21,9);
    printf(" Auther name:");
    scanf("%s",&a.auther);
    gotoxy(21,10);
    printf(" Quantity:");
    scanf("%d",&a.quntity);
    gotoxy(21,11);
    printf(" Rack_number:");
    scanf("%d",&a.rackno);
    gotoxy(21,12);
    printf(" Price:");
    scanf("%f",&a.price);
    gotoxy(20,16);
    return (1);
}
int checkid(int t)
{
   rewind(fp);
   while(fread(&a,sizeof(a),1,fp)==1)
      if(a.id==t)
      {
        return 0;
      }

        return 1;
}
void password(void)
{
    char ch,j,k,i=0;
    char pass[10];
    char p[]="password protected";
    gotoxy(20,5);
    for(int j=0;j<15;j++)
    {

        printf("*");
        Sleep(50);
    }
    for(int j=0;j<sizeof(p);j++)
    {

        printf("%c",p[j]);
        Sleep(50);
    }
    for(int j=0;j<15;j++)
    {
        printf("*");
        Sleep(50);
    }
    gotoxy(10,10);
    gotoxy(27,7);
    printf("Enter password:");
    while(ch!=13)
    {
        ch=getch();
        if(ch!=13&&ch!=8)
        {
            printf("*");
            pass[i]=ch;
            i++;
        }
    }
    pass[i]='\0';
    if(strcmp(pass,Password)==0)
    {
        gotoxy(27,9);
        printf("password matched");
        gotoxy(28,10);
        printf("Press any key to continue...");
        getch();
        main_menu();
    }
    else
    {
        gotoxy(27,16);
        printf("warning!!Incorrect password");
        getch();
        system("cls");
        password();
    }
}
main()
{
    addbook();
    //getdata();
    //password();
}

