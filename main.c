#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


struct login
{

    char name[15];
    char passw[15];

} login[10];
void clrscr(){system("cls");}

void car_pool();
void userEntry();
int login_fun();
void car(int i,float duration);
void mainfunction();
void getch();
void dataentry()
{
    int i;
    FILE *fw;
    fw=fopen("user.txt","w+");
    for(i=0; i<10; i++)
    {
        printf("Enter a valid Username ");
        gets(login[i].name);
        printf("Enter a valid Password ");
        gets(login[i].passw);
        fwrite(&login[i],sizeof(struct login),1,fw);
    }
    fclose(fw);
}


int login_fun()
{
    FILE *fp;
    char name[30],pass[30];
    int checku,checkp,i,flag=0;
    fp=fopen("user.txt","r");

    for(i=0; i<100; i++)
    {
        clrscr();
        printf("\n\n\t\t\t\t\tWELCOME TO LOG IN ZONE");
        printf("\n\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^");
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",name);
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        scanf("%s",pass);
        while(!feof(fp))
        {

            fread(&login[i],sizeof(login[i]),1,fp);
            checku=strcmp(name,login[i].name);
            checkp=strcmp(pass,login[i].passw);
            if(checku==0&&checkp==0)
            {
                flag=1;
                clrscr();
                printf("\n\n\n\t\t\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
                break;
            }

            else if(checku!=0 || checkp!=0)
            {
                flag=0;
            }
        }

        break;
    }
    fclose(fp);
    return flag;
}

void loop_fun()
{
    int i,j;
    for(i=0; i<10; i++)
    {
        j=login_fun();
        if(j==1)
        {
            mainfunction();
        }
        if(j==0)
        {

            printf("\nUsername or Password is wrong");
            getch();
            //delay(2000);
            continue;
        }
    }
}


void mainfunction()
{
    int choice;
    float duration;
    printf("\n\t\t\t\t\t\tAccess Granted\t\t\t\t\t\n");
    printf("\t\t\t\tWelcome to our cab and rental vehicle service\t\t\t\t\t");
    printf("\nPlease Choose :\n[1] Rental Service\n[2] C Service\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("\n\nPlease enter time duration (in days) for which you want our rental vehicle service\n");
        scanf("%f",&duration);
        system("cls");

        int i;
        printf("\nPlease Choose :\n[1] Car\n[2] Bike\n");
        scanf("%d",&i);
        car(i,duration);
        break;
    case 2:
        car_pool();
        break;
    }


}

void car_pool ()
{

    char area[8][30]= {"Iskon-Cross Road", "ISRO","Jodhupur Cross Road","Shivrajani","Nehrunagar","Panjrapol","Gulbai Tekra","L.D. College"};
    printf("Choose any location from the following:\n");

    for(int i=0; i<8; i++)
    {
        printf("[%d] %s\n",i+1,area[i]);
    }
    int curl;//currentLocation;
    int fin;//finalLocation;
    float tr;//tripCost;
    printf("\n\n");
    printf("Enter the index number given to your desired location");
    printf(" Please, Enter your Current Location (corresponding no.) : ");
    scanf("%d",&curl);
    printf(" Please, Enter your Final Location (corresponding no.) : ");
    scanf("%d",&fin);
    printf("\n");
    printf(" Your current Location is %s and your final Location is %s \n",area[curl-1],area[fin-1]);
    printf("\n");

    if(curl-fin>0)
    {
        tr=(curl-fin)*12+10;
    }
    else
    {
        tr=(-1)*(curl-fin)*12+10;
    }

    printf(" You have to pay %0.2f for the trip.\n",tr);
    printf(" Thank you for choosing us !\n");
    getch();
}
void car(int i,float duration)
{
    int b;
    int c;
    int suv=8500;
    int sedan=7500;
    int hatchback=6000;
    int Racing_bike=3500;
    int gearless_vehicle=2500;
    int normal_bike=3000;
    float d;

    switch(i)
    {
    case(1):
        printf("\nPlease Choose :\n[1] Suv\n[2] Sedan\n[3] Hatchback\n");
        scanf("%d",&b);
        switch(b)
        {
        case(1):
            d=duration*suv;
            printf("\nYou may have to pay %.2f for %.2f days\n",d,duration);
            break;
        case(2):

            d=duration*sedan;
            printf("\nYou may have to pay %.2f for %.2f days\n",d,duration);
            break;
        case(3):
            d=duration*hatchback;
            printf("\nYou may have to pay %.2f for %.2f days\n",d,duration);
            break;
        }
        break;
    case(2):
        printf("\nPlease Choose :\n[1]racing bike\n[2]gearless vehicle\n[3]normal Bike\n");
        scanf("%d",&c);
        switch(c)
        {
        case(1):
            d=duration*Racing_bike;
            printf("\nYou may have to pay %.2f for %.2f days\n",d,duration);
            break;
        case(2):
            d=duration*gearless_vehicle;
            printf("\nYou may have to pay %.2f for %.2f days\n",d,duration);
            break;
        case(3):
            d=duration*normal_bike;
            printf("\nYou may have to pay %.2f for %.2f days\n",d,duration);
            break;
        }
        break;


    }
    getch();
}



int main()
{
    loop_fun();
    return 0;
}



