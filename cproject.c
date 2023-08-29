#include<stdio.h>  
#include<wchar.h>
#include<string.h>  
#include<stdlib.h>
struct ad  
{  
    char name[30];  
    char disease[30];  
    int cabin,age;
    long long phone;
} x[100];  
int n,i,j=0,sum=0,g,num; //i,g,j are loop control. num stores the total number of patients and sum is for updating num with n in add 
int read();//Reads the old file and creates a new one if it does exist
void write();  //To update the file after end of operations
void add();  //To add new records
void view();  //To display all the records in the database
void search(); //To search for individual Record in the Database on any of the fields 
void edit();//To change the data in any of the fields of a given record  
void del(); //To clear the value of any given field or delete the entire record 
void show();  //To individually display a single record used in the view function
void header();// Format table
int main()  
{  
    read();  
    int c; //c is for the choice of operation, switch variable 
    printf("%55s----------------------------------Anirudh Hospitals-----------------------------------\n"," ");
    printf("\n");
    printf("%65s __    __                                __    __                __ \n"," ");
    printf("%65s/  |  /  |                              /  |  /  |              /  |\n"," ");
    printf("%65s$$ |  $$ |  ______    _______   ______  $$/  _$$ |_     ______  $$ |\n"," ");
    printf("%65s$$ |__$$ | /      |  /       | /      | /  |/ $$   |   /      | $$ |\n"," ");
    printf("%65s$$    $$ |/$$$$$$  |/$$$$$$$/ /$$$$$$  |$$ |$$$$$$/    $$$$$$  |$$ |\n"," ");
    printf("%65s$$$$$$$$ |$$ |  $$ |$$      | $$ |  $$ |$$ |  $$ | __  /    $$ |$$ |\n"," ");
    printf("%65s$$ |  $$ |$$ |__$$ | $$$$$$  |$$ |__$$ |$$ |  $$ |/  |/$$$$$$$ |$$ |\n"," ");
    printf("%65s$$ |  $$ |$$    $$/ /     $$/ $$    $$/ $$ |  $$  $$/ $$    $$ |$$ |\n"," ");
    printf("%65s$$/   $$/  $$$$$$/  $$$$$$$/  $$$$$$$/  $$/    $$$$/   $$$$$$$/ $$/\n"," ");
    printf("%65s                              $$ |                                  \n"," ");
    printf("%65s                              $$ |                                  \n"," ");

  
    while(c!=6)  
    {  
  
        printf("\n%55s**Enter your choice**\n\n%55s- - - - - - - - - - - - - - - - - - - - - - - - - - \n\n%55s1. Add Information\n\n%55s2. View Information\n\n%55s3. Search\n\n%55s4. Edit Information\n\n%55s5. Delete Information\n\n%55s6. Exit\n\n%55sOption : "," "," "," "," "," "," "," "," "," ");  

        scanf("%d",&c);//choice for option  
        printf("\n%55s- - - - - - - - - - - - - - - - - - - - - - - - - - \n"," ");
        fflush(stdin);//making it clear  
     switch(c)
      {
          case 1://add  
        {  
            add();  
        }  
        break;

        case 2://view  
        {  
            view();  
        }  
        break;

        case 3://search  
        { 
            search();  
        }  
        break;

        case 4://edit  
        {  
            edit();  
        }  
        break;

        case 5://delete  
        {  
            del();  
        }  
        break;

        case 6://exit and update the file  
        {  
            printf( "%55s ________  __                            __                                        __ \n", " "); 
            printf( "%55s/        |/  |                          /  |                                      /  |\n", " ");
            printf( "%55s$$$$$$$$/ $$ |____    ______   _______  $$ |   __    __    __   ______   __    __ $$ |\n", " ");
            printf( "%55s   $$ |   $$      |  /      | /       | $$ |  /  |  /  |  /  | /      | /  |  /  |$$ |\n", " ");
            printf( "%55s   $$ |   $$$$$$$  | $$$$$$  |$$$$$$$  |$$ |_/$$/   $$ |  $$ |/$$$$$$  |$$ |  $$ |$$ |\n", " ");
            printf( "%55s   $$ |   $$ |  $$ | /    $$ |$$ |  $$ |$$   $$<    $$ |  $$ |$$ |  $$ |$$ |  $$ |$$/ \n", " ");
            printf( "%55s   $$ |   $$ |  $$ |/$$$$$$$ |$$ |  $$ |$$$$$$  |   $$ |__$$ |$$ |__$$ |$$ |__$$ | __ \n", " ");
            printf( "%55s   $$ |   $$ |  $$ |$$    $$ |$$ |  $$ |$$ | $$  |  $$    $$ |$$    $$/ $$    $$/ /  |\n", " ");
            printf( "%55s   $$/    $$/   $$/  $$$$$$$/ $$/   $$/ $$/   $$/    $$$$$$$ | $$$$$$/   $$$$$$/  $$/ \n", " ");
            printf( "%55s                                                     $$$$$$/                          \n", " ");
            printf( "%55s                                                    /  |__$$ |                        \n", " ");
            printf( "%55s                                                    $$    $$/                         \n", " ");
            printf("\n");
            printf("%65sTeam : Aman ,Anchal, Erum, Ananya, Anirudh, Arshaan, Deepak, Akhand \n", " ");
            
            write();  
            return 0;  
        }  
        break;

        default:
        {   
            printf("\n\n%55sInvalid input , try again by using valid inputs"," ");  
        }  
      }
        printf("\n\n");  
    }  
}  

void add()  
{  
    printf("\n%55s- - - - - - - - - - - - - - - - - - - - - - - - - - \n"," ");
    printf("\n\n");  
    printf("%55sAlready data avalible on the database : %d\n\n"," ",num);//how many inputs  
    printf("%55sHow many entry do you want to add ?  "," ");  
    scanf("%d",&n);  
    sum=n+num;  
  
    for(i=num; i<sum; i++)  
    {  
        char temp;
        printf("\n");  
        scanf("%c", &temp);
        printf("%55sPatient No: %d\n"," ", i+1);
        printf("\n%55sEnter patient's Name = "," ");  
        fscanf(stdin," %[^\n]s",x[i].name); 
        scanf("%c", &temp);//for leaving a space after string input


        printf("\n%55sEnter disease = "," ");  
        fscanf(stdin," %[^\n]s",x[i].disease); 
    //    scanf("%c", &temp);

        printf("\n%55sEnter the age = "," ");  
        scanf("%d",&x[i].age);  
       scanf("%c", &temp);

        printf("\n%55sEnter cabin no = "," ");  
        scanf("%d",&x[i].cabin);  
       scanf("%c", &temp);

        printf("\n%55sEnter phone number = "," ");  
        scanf("%lli",&x[i].phone);  
    //    scanf("%c", &temp);
        printf("\n%55s- - - - - - - - - - - - - - - - - - - - - - - - - - \n"," ");
        printf("\n");   
        num++;  
    }  
}  
  
void view()  
{ 
    printf("\n");
     if(num==0)
       {
         printf("%55sThe Database is Empty \n"," ");
       }
    else    
        {
            header();
              for(i = 0; i < num; i++)
                show(i);
        }
}  

void edit()
{
    int q, p;
    char temp;
    printf("\n%55sEnter the serial no of that patient(1 - %d) : ", " ",num);
    scanf("%d", &p);
    p = p-1;// as we have serial numbers from 1
    if (p < num)
    {
    printf("\n\n%101sOLD DATA OF PATIENT\n\n", " ");
    header();
    show(p);
    
        // serial number
        printf("\n\n%55sWhat do you want to edit ?\n"," ");
        printf("\n%55sEnter your option\n"," ");
        printf("\n%55s1.Name\n\n%55s2.Disease\n\n%55s3.Age\n\n%55s4.Cabin\n\n%55s5.Phone no.\n\n"," "," "," "," "," ");
        printf("%55sOption : "," ");
        scanf("%d", &q);
     switch(q)
     {
        case 1:
        {

            printf("\n%55sEnter the new name : ", " ");
            fscanf(stdin, " %[^\n]s", x[p].name);
        }
        break;

        case 2:
        {

            printf("\n%55sEnter the new Disease : "," ");
            fscanf(stdin, " %[^\n]s", x[p].disease);
        }
        break;

        case 3:
        {

            printf("\n%55sEnter the new Age : ", " ");
            scanf("%d", &x[p].age);
        }
        break;

        case 4:
        {
            printf("\n%55sEnter the new Cabin no : ", " ");
            scanf("%d", &x[p].cabin);
        }
        break;

        case 5:
        {
            printf("\n%55sEnter the new Phone no : ", " ");
            scanf("%lli", &x[p].phone);
        }
        break;

        default:
        {
            printf("\n\n%55sInvalid Serial \n%55sTry Again !!\n\n"," "," ");
            return;
        }
     }
        printf("\n\n%101sNEW DATA OF PATIENT\n\n", " ");
        // scanf("%c", &temp);
        header();
        show(p);
    }
    else 
    {
        printf("\n\n%55sInvalid Serial \n%55sTry Again !!\n\n", " ", " ");
            return;
    }
      
}

void search()  
{  
    int s,h,f;  //s=serial number, h is for seach field, f is flag
    char temp;
    char u[100];  
    printf("\n%55s- - - - - - - - - - - - - - - - - - - - - - - - - - \n"," ");
    printf("\n%55sBy what do you want to search ?\n\n", " ");  
    printf("%55s1.Serial no.\n\n%55s2.Name\n\n%55s3.Disease\n\n%55s4.Cabin no.\n\n%55s5.Phone no.\n\n%55s6.Age\n\n%55sOption : ", " "," "," "," "," "," "," ");  
    scanf("%d",&h);  
    scanf("%c", &temp);
    printf("\n");
    switch(h)
    {
     case 1:
    {  
        int f=1;
        printf("%55sEnter Serial number of the patient : ", " ");  
        scanf("%d",&s);  
        if(s<=num)  
        {  
            printf("\n");  
            header();
            show(s-1); 
            f = 0;  
        }  
        else  
            printf("\n%55sNot Found\n"," ");  
    }  
    break;

    case 2:
    {  
        int f=1;  //flag
       
        printf("%55sEnter your name : ", " ");  
        fgets(u, sizeof(u), stdin);
        u[strcspn(u, "\n")] = '\0'; //The input will have a break at the end, we are removing it by going till break and changing that index value to end of string
        header();
        for(g=0; g<num; g++)  
        {  
            
            if(strcmp(u,x[g].name)==0)  
            {  
                printf("\n"); 
                show(g); 
                f = 0;
  
            }  
        }  
        if(f==1)  
            printf("\n%55sNot Found\n"," ");  
    }
    break;

    case 3:
    {  
        int f=1;  //flag
       
        printf("%55sEnter Disease : ", " ");  
        fgets(u, sizeof(u), stdin);
        u[strcspn(u, "\n")] = '\0'; 
        header();
        for(g=0; g<num; g++)  
        {  
            //header(); 
            if(strcmp(u,x[g].disease)==0)  
            {  
                //printf("\n");
                
                show(g); 
                f = 0; 
            }  
        }  
        if(f==1)  
            printf("\n%55sNot Found\n"," "); 
    }  
    break;

    case 4:
    {  
        int f=1, c;  
        printf("%55sEnter Cabin number : ", " ");  
        scanf("%d",&c); 
        header();  
        for(g=0; g<num; g++)  
        {  
            
            if(c==x[g].cabin)  
            {  
                printf("\n"); 
                show(g); 
                f = 0;
            }  
  
        }  
        if(f==1)  
            printf("\n%55sNot Found\n"," ");  
    }  
    break;

    case 5:
    {  
        int f=1, c;  
        printf("%55sEnter Phone number : ", " ");  
        scanf("%d",&c);  
        header();
        for(g=0; g<num; g++)  
        {  
             
            if(c==x[g].phone)  
            {  
                printf("\n"); 

                show(g); 
                f = 0;  
            }  
  
        }  
        if(f==1)  
           printf("\n%55sNot Found\n"," ");
    }  
    break;

    case 6:
    {  
        int f=1, c ;  
        printf("%55sEnter Age : ", " ");  
        scanf("%d",&c); 
        header(); 
        for(g=0; g<num; g++)  
        {  
            if(c==x[g].age)  
            {  
                printf("\n");  
                show(g); 
                f = 0;
            }  
  
        }  
        if(f==1)  
            printf("\n%55sNot Found\n"," ");
    }  
    break;

     default:
     {
        printf("\n\n%55sInvalid input\n\n", " ");  
     }  
    }
}  

void del()  
{  
    int f,h;  //serial no. and h is field
    printf("\n%55sEnter the serial number of the patient that you want to delete : "," ");  
    scanf("%d",&f);  
    f = f-1;
    
     if(f<num)  
     { 
        printf("\n\n");
        header();
        show(f);
        printf("\n\n%55sWhat do you want ?\n", " ");  
        printf("\n%55s1.Remove the whole record\n\n%55s2.Remove Name\n\n%55s3.Remove Disease\n\n%55s4.Remove age\n\n%55s5.Remove Cabin\n\n%55s6.Remove phone number\n\n%55sOption : ", " "," "," "," "," "," "," ");  
        scanf("%d",&h); 
        switch(h)
        { 
        case 1:
        {  
            while(f<num)  
            {  
                x[f] = x[f+1];
                f++;  
            }  
            num--;  
        }  
        break;

        case 2:
        {  
            strcpy(x[f].name,"Cleared");  
        }  
        break;

        case 3:  
        {  
            strcpy(x[f].disease,"Cleared");  
        }  
        break;

        case 4:
        {  
            x[f].age=0;  
        }  
        break;

        case 5:
        {  
            x[f].cabin=0;  
        }  
        break;

        case 6:
        {  
            x[f].phone=0;  
        }  
        break;

        default:
        {
            printf("\n\n%55sInvalid Option\n", " ");
        }
  
      }  
     }
      else  
        printf("\n\n%55sInvalid Serial number\n", " ");  
     
} 

int read()  
{  
    FILE *fp = fopen("patient.txt","r");  
     if(fp == NULL)  
     {  
        //create empty file, so that we can open it  
        //in the next execution of this program  
        fp = fopen("patient.txt","w");  
        fclose(fp);  
        return 0;  
      }  
  
    num = fread(x, sizeof(struct ad),100, fp);  
    fclose(fp);  
}  


void write()  
{  
    FILE *fp = fopen("patient.txt","w");  
    if(fp == NULL)  
    {  
        printf("Error");  
        exit(1);  
    }  
    fwrite(x, sizeof(struct ad),num, fp);  
  
    fclose(fp);  
} 

void header()
{
    printf("                                                       *************************************************************************************************************\n");
    printf("%55s%-12s%-32s%-32s%-8s%-12s%-15s\n", " ", "S No.", "Patient Name", "Disease", "Age", "Cabin No", "Phone no.");
    printf("                                                       - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
} 

void show(int i)
{
    printf("\n\n");
    printf("%55s%-12d%-32s%-32s%-8d%-12d%-15lli", " ", i+1, x[i].name, x[i].disease, x[i].age, x[i].cabin, x[i].phone);
}
