#include <windows.h>
#include<stdio.h>
#include<string.h>
void setColor(int ForgC)
{
  //work**

    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);


    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {

        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



//////////////////////////////////////////
//////////////////////////////////////////
//
char name[100], user_name[100], pass[100],shop_name[100];
struct user
{
    char name[100], user_name[100], pass[100],shop_name[100];

} s[700],c[700];


struct product
{
    char p_name[100];
    int id,price,quenty;

} p[700];

int number_of_shoppers=0,number_of_customers=0,number_of_products=0,s_avatar,c_avatar;

void setup()
{
    system("cls");
    gotoxy(67, 31);

    setColor(156);
    printf("By Spartans");
}




int home_page()
{
    setup();

    setColor(238);

    gotoxy(15, 14);
    printf(">  Login");

    setColor(239);

    gotoxy(15, 17);
    printf("   Sign Up");

    gotoxy(15, 20);
    printf("   About Us");

    gotoxy(15, 23);
    printf("   Exit");

    int pos = 0;

    char ch;

    while(1)
    {
        gotoxy(0, 0);

        ch = getch();

        if(ch == 80 && !pos)
        {
            setColor(239);

            gotoxy(15, 14);
            printf("   Login");

            setColor(238);

            gotoxy(15, 17);
            printf(">  Sign Up");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(239);

            gotoxy(15, 17);
            printf("   Sign Up");

            setColor(238);

            gotoxy(15, 20);
            printf(">  About Us");

            pos++;
        }

        else if(ch == 80 && pos == 2)
        {
            setColor(239);

            gotoxy(15, 20);
            printf("   About Us");

            setColor(238);

            gotoxy(15, 23);
            printf(">  Exit");

            pos++;
        }

        else if(ch == 72 && pos == 3)
        {
            setColor(238);

            gotoxy(15, 20);
            printf(">  About Us");

            setColor(239);

            gotoxy(15, 23);
            printf("   Exit");

            pos--;
        }

        else if(ch == 72 && pos == 2)
        {
            setColor(238);

            gotoxy(15, 17);
            printf(">  Sign Up");

            setColor(239);

            gotoxy(15, 20);
            printf("   About Us");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(238);

            gotoxy(15, 14);
            printf(">  Login");

            setColor(239);

            gotoxy(15, 17);
            printf("   Sign Up");

            pos--;
        }

        else if(ch == 32)   return pos;
    }
}

///Shopperrrrrrrrrrrrrrrrrrrrrrrrrrr

//Shopper Read Data
void s_readdata()
{
    int  i;
    FILE *file =fopen("shopper.txt","r");
    if(file == NULL) file=fopen("shopper.txt","w");
    //while(fscanf(file,"%[^\n]",s[i].shop_name) != -1)
    fscanf(file,"%d",&number_of_shoppers);
    for(i=0; i<number_of_shoppers; i++)
    {
        fscanf(file," %[^\n]",s[i].shop_name);
        fscanf(file," %[^\n]",s[i].name);
        fscanf(file,"%s",s[i].user_name);
        fscanf(file," %s",s[i].pass);
    }
    fclose(file);

}

//Shop show
void show()
{
    int i;
    s_readdata();

    for(i = 0; i < number_of_shoppers; i++)
    {
        //printf("%s\n%s\n%s\n%s\n ", s[i].shop_name, s[i].name, s[i].user_name,s[i].pass);

        setColor(219);

        gotoxy(76, 27);
        printf("%s",s[i].shop_name);

        gotoxy(76, 29);
        printf("%s",s[i].name);

        gotoxy(76, 33);
        printf("%s",s[i].user_name);

        gotoxy(76, 35);
        printf("%s",s[i].pass);
    }

}

//SIGNUP:   Shopper unique ID check
int s_uniqueID()
{

    int i;
    s_readdata();
    ///show();
    for(i = 0; i < number_of_shoppers; i++)
        if(!strcmp(user_name, s[i].user_name))
            return 1;
    return 0;
}




//LOGIN :      Shopper UserName check while login
int shopper_user_check()
{
//    int i;
//    s_readdata();
//    for(i = 0; i < number_of_shoppers; i++)
//        if(!strcmp(name, s[i].user_name))
//        {
//            if(!strcmp(pass, s[i].pass))    return 1;
//            return 0;
//        }
//
//    return 0;

    int i;
    s_readdata();
    for(i = 0; i < number_of_shoppers; i++)
    {
        if(!strcmp(user_name, s[i].user_name))
        {
            if(!strcmp(pass, s[i].pass))    return i;
            return -1;
        }
    }
    return -1;

}
void show_all_product()
{
	int i,c;
	read_products();
	system("cls");
	for(i =1,c=11; i <=number_of_products; i++,c+=3) {

             setColor(238);
             gotoxy(15,c);
             printf("%d %s %d %d\n",i,p[i].p_name,p[i].quenty, p[i].price);
             Sleep(100);
		//printf("%s\n%d\n%d\n", arr[i].id, arr[i].marks, arr[i].roll);
	}
//	getchar();
//	getchar();
}


//LOGIN : ENTER IN THE PROFILE SCREEN of shopper

int s_profile(){
    setup();

    setColor(251);

    gotoxy(17, 13);
    printf("Welcome Back");

    gotoxy(17, 16);
    printf("%s!", s[s_avatar].shop_name);

    gotoxy(17, 19);
    printf("%s", s[s_avatar].name);    setColor(238);



    gotoxy(65, 14);
    printf(">  Add Product");


    setColor(239);

    gotoxy(65, 17);
    printf("   Update Pricing");

    gotoxy(65, 20);
    printf("   Delete  Product");

//    gotoxy(65, 23);
//    printf("   Show Product");


    gotoxy(65, 23);
    printf("   Log Out");

    int pos = 0;

    char ch;

    while(1)
    {
        gotoxy(0, 0);

        ch = getch();

        if(ch == 80 && !pos)
        {
            setColor(239);

            gotoxy(65, 14);
            printf("   Add Product");

            setColor(238);

            gotoxy(65, 17);
            printf(">  Update Pricing");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(239);

            gotoxy(65, 17);
            printf("   Update Pricing");

            setColor(238);

            gotoxy(65, 20);
            printf(">  Delete  Product");

            pos++;
        }

        else if(ch == 80 && pos == 2)
        {
            setColor(239);

            gotoxy(65, 20);
            printf("   Delete  Product");

            setColor(238);

            gotoxy(65, 23);
             printf(">  Log Out");
             pos++;
        }
//        else if(ch == 80 && pos == 3)
//        {
//            gotoxy(65, 23);
//            printf("   Show  Product");
//
//
//            gotoxy(65, 26);
//            printf(">  Log Out");
//
//          pos--;
//        }
//        else if(ch == 72 && pos == 4)
//        {
//            setColor(238);
//
//            gotoxy(65, 23);
//            printf(">  Show  Product");
//            gotoxy(65, 20);
//            printf(">  Delete  Product");
//
//            setColor(239);
//
//            gotoxy(65, 26);
//            printf("   Log Out");
//
//            pos--;
//        }
        else if(ch == 72 && pos == 3)
        {
            setColor(238);

            gotoxy(65, 20);
            printf(">  Delete  Product");

           setColor(239);
           gotoxy(65, 23);
           printf("   Log Out");


            pos--;
        }
        else if(ch == 72 && pos == 2)
        {
            setColor(238);

            gotoxy(65, 17);
            printf(">  Update Pricing");

            setColor(239);
            gotoxy(65, 20);
            printf("   Delete  Product");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(238);

            gotoxy(65, 14);
            printf(">  Add Product");

            setColor(239);

            gotoxy(65, 17);
            printf("   Update Pricing");

            pos--;
        }

        else if(ch == 32)   return pos;
    }
}


//Read products
void read_products()
{
    int  i;
    FILE *file =fopen("products.txt","r");
    if(file == NULL) file=fopen("products.txt","w");
    //while(fscanf(file,"%[^\n]",s[i].shop_name) != -1)
    fscanf(file,"%d",&number_of_products);
    for(i=1; i<=number_of_products; i++)
    {
        fscanf(file," %[^\n]",p[i].p_name);
        fscanf(file," %d",&p[i].quenty);
        fscanf(file," %d",&p[i].price);
    }
    fclose(file);

}

//Write Data
void s_writeData()//product
{
	int i;
	FILE *fp;
	fp = fopen("products.txt", "w");
	fprintf(fp, "%d\n", number_of_products);
	for(i = 1; i <=number_of_products; i++) {
		fprintf(fp, "%s\n%d\n%d\n", p[i].p_name,p[i].quenty, p[i].price);
	}
	fclose(fp);
}


//Add Products from shopper ---------------------------------------------------------------------------------------------------------------->
void add_products()
{
    int i,m,j,pr,c,qn;
    char na[100];

    system("cls");
    show_all_product();
    setColor(238);
    gotoxy(65,11);
    printf("how many product input: ");
    scanf("%d",&m);
    for(j=0,c=14;j<m;j++,c+=9){
        gotoxy(65,c);
        printf("input prouduct name: ");

        scanf(" %[^\n]",na);

        gotoxy(65,c+3);
        printf("input product quenty: ");
        scanf("%d",&qn);

        gotoxy(65,c+6);
        printf("input product price: ");
        scanf("%d",&pr);

        read_products();
        number_of_products++;
        strcpy(p[number_of_products].p_name,na);
        p[number_of_products].quenty=qn;
        p[number_of_products].price=pr;
        s_writeData();
    }
    getchar();
	getchar();
}

//Find product name while updating pricing
int findbyname(char name[]){
    int pos = -1, i;
	read_products();
	for(i = 1; i <= number_of_products; i++) {
		if(strcmp(p[i].p_name, name) == 0) {
			pos = i;
		}
	}
	return pos;

}

//Update Product Price
void update_pricing()
{
    char name[100];
    int price,m,c,qn;

    system("cls");
    show_all_product();
    setColor(238);
    gotoxy(65,11);
    printf("How many products you want to update: ");
    scanf("%d",&m);

    for(int j=1,c=14;j<=m;j++,c+=9){

        gotoxy(65,c);
        printf("Enter Your Product Name: ");
        scanf(" %[^\n]",name);

        gotoxy(65,c+3);
        printf("input product quenty: ");
        scanf("%d",&qn);

        gotoxy(65,c+6);
        printf("Enter Your Product Price: ");
        scanf("%d",&price);

        int pos = findbyname(name);

        if(pos!= -1){

           p[pos].quenty += qn;
           p[pos].price = price;
        }
        s_writeData();
    }
    getchar();
	getchar();

}


void ss_writeData()//shopper
{
   int i;
	FILE *fp;
	fp = fopen("shopper.txt", "w");
	fprintf(fp, "%d\n", number_of_shoppers);
	for(i = 0; i <number_of_shoppers; i++) {
		fprintf(fp, "%s\n%s\n%s\n%s\n", s[i].shop_name,s[i].name,s[i].user_name,s[i].pass);
	}
	fclose(fp);
}
// Delete Product from the price
void delete_product()
{
   	char name[100];
   	int price,i,m,j,c;
   	system("cls");
   	show_all_product();
    gotoxy(65,11);
    printf("How many products you want to delete:");
   	scanf("%d",&m);
   	for(j=1,c=14;j<=m;j++,c+=3)
    {
        setColor(238);
        gotoxy(65,c);
        printf("Enter your product name:");
     	scanf(" %[^\n]", name);
      int pos= findbyname(name);
      if(pos != -1)
      {
        number_of_products--;
        for(i = pos; i <=number_of_products; i++)
        {
            p[i]=p[i+1];
        }
      }

     else
     {
         setColor(219);
         gotoxy(65,8);
         printf("%s not found\n",name);
     }
    }

    s_writeData();//Delete Product

    getchar();
	getchar();
}

//saving shopper after signup
void  s_saveInfo()
{
    int i;
    strcpy(s[number_of_shoppers].shop_name,shop_name);
    strcpy(s[number_of_shoppers].name,name);
    strcpy(s[number_of_shoppers].user_name,user_name);
    strcpy(s[number_of_shoppers].pass,pass);
    number_of_shoppers++;
    ss_writeData();
    setColor(219);
    gotoxy(65,8);
    printf("Successfully Created %s Account",user_name);
    sleep(2);
}



//######################################################################################################
//######################################################################################################
//######################################################################################################
//######################################################################################################
///Customerrrrrrrrrrrrrrrrrrrrrrrrrr
//######################################################################################################
//######################################################################################################
//######################################################################################################
//######################################################################################################


///Customer Read Data
void c_readdata()
{
    int  i;
    FILE *file =fopen("customer.txt","r");
    if(file == NULL) file=fopen("customer.txt","w");
    //while(fscanf(file,"%[^\n]",s[i].shop_name) != -1)
    fscanf(file,"%d",&number_of_customers);
    for(i=0; i<number_of_customers; i++)
    {
        fscanf(file," %[^\n]",c[i].name);
        fscanf(file,"%s",c[i].user_name);
        fscanf(file," %s",c[i].pass);
    }
    fclose(file);

}


///SIGNUP:  Customer unique ID check
int c_uniqueID()
{
    int i;
    c_readdata();
    ///show();
    for(i = 0; i < number_of_customers; i++)
        if(!strcmp(user_name, c[i].user_name))
            return 1;
    return 0;
}


///LOGIN :      Customer UserName check while login
int customer_user_check()
{

    int i;
    c_readdata();
    for(i = 0; i < number_of_customers; i++)
        if(!strcmp(user_name, c[i].user_name))
        {
            if(!strcmp(pass, c[i].pass))    return i;
            return -1;
        }

    return -1;


}



///Customer writeData
void cc_writeData()
{
    int i;
	FILE *fp;
	fp = fopen("customer.txt", "w");
	fprintf(fp, "%d\n", number_of_customers);
	for(i = 0; i <number_of_customers; i++) {
		fprintf(fp, "%s\n%s\n%s\n", c[i].name,c[i].user_name,c[i].pass);
	}
	fclose(fp);
}

///saving shopper after signup
void  cc_saveInfo()
{
    int i;
    strcpy(c[number_of_customers].name,name);
    strcpy(c[number_of_customers].user_name,user_name);
    strcpy(c[number_of_customers].pass,pass);
    number_of_customers++;
    cc_writeData();
    setColor(219);
    gotoxy(65,8);
    printf("Successfully Created %s Account",user_name);
    sleep(2);
}

//LOGIN : ENTER IN THE PROFILE SCREEN of the Customer

int c_profile(){
    setup();

    setColor(251);

    gotoxy(17, 13);
    printf("Welcome Back");

    gotoxy(17, 16);
    printf("%s!", c[c_avatar].name);

    gotoxy(17, 19);
    printf("%s", c[c_avatar].user_name);

    setColor(238);

    gotoxy(65, 14);
    printf(">  Search Product");


    setColor(239);

    gotoxy(65, 17);
    printf("   Select Product");

    gotoxy(65, 20);
    printf("   Log Out");

    int pos = 0;

    char ch;

    while(1)
    {
        gotoxy(0, 0);

        ch = getch();

        if(ch == 80 && !pos)
        {
            setColor(239);

            gotoxy(65, 14);
            printf("   Search Product");

            setColor(238);

            gotoxy(65, 17);
            printf(">  Select Product");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(239);

            gotoxy(65, 17);
            printf("   Select Product");

            setColor(238);

            gotoxy(65, 20);
            printf(">  Log Out");

            pos++;
        }

        else if(ch == 72 && pos == 2)
        {
            setColor(238);

            gotoxy(65, 17);
            printf(">  Select Product");

            setColor(239);

            gotoxy(65, 20);
            printf("   Log Out");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(238);

            gotoxy(65, 14);
            printf(">  Search Product");

            setColor(239);

            gotoxy(65, 17);
            printf("   Select Product");

            pos--;
        }

        else if(ch == 32)   return pos;
    }
}
void total(int a[],int b[],int c[],int cont,int sum)
{
    show_all_product();

     int i , j,d;
    for(i=1,d = 8;i<=cont+2;i++,d+=2)
    {
        if(i==cont+1)
        {
           gotoxy(65,d);
           printf("--------------------------");
        }
        else if(i==cont+2)
        {

            gotoxy(65,d);
           printf("Total  = %d",sum);
        }
        else
        {
             gotoxy(65,d);
           printf("%d %s %d %d",i,p[a[i]].p_name,b[i],c[i]);
        }
    }

    getchar();
    getchar();
}

int search_products(){
    printf("Hell66666666666666666666666666666666666666666666666666o");
    sleep(2);
}

int select_products(){

    int cont=0,a[300],b[300],c[100];

    read_products();

    int i=1,n,j,sum=0,s=0;

    while(1)
    {
        s=0;
        system("cls");
       show_all_product();

       gotoxy(65,11);
       printf("%d prouducts select ",cont);

       gotoxy(65,14);
       printf("Are you buy prouduct press 1 otherwise press 0 :");

       gotoxy(121,14);
       scanf("%d",&n);

       if(n>0)
       {
           gotoxy(65,17);
           printf("Select product id:");

           gotoxy(83,17);
           scanf("%d",&a[i]);

           gotoxy(65,20);
           printf("Quenty:");

           gotoxy(75,20);
           scanf("%d",&b[i]);

//            gotoxy(65,23);
//            printf("%d %d",a[i],b[i]);
//
//            sleep(2);
           if(p[a[i]].quenty >= b[i])
           {
                c[i] = p[a[i]].price*b[i];

                sum+=p[a[i]].price*b[i];

                p[a[i]].quenty -= b[i];

                s_writeData();

                cont++;
           }

          else
           {
               gotoxy(65,23);
               printf("%s This product available %d",p[a[i]].p_name,p[a[i]].quenty);
               getchar();
               getchar();
           }

//           s_writeData();
//           for(int c=1;c<=j;j++)
//           {
//               sum+=p[i].price;
//               p[i].quenty--;
//               s_writeData();
//           }
//           cont++;
           //gotoxy(75,23);
//           printf("%d dfhdthfghjgfjfgujuj",sum);
//           sleep(3);

       }
       else
       {
//           for(i=1;i<=cont;i++)
//           {
////               gotoxy(65,23);
//               printf("%d %d",a[i],b[i]);
//
//           }
//           getchar();
//           getchar();
            total(a,b,c,cont,sum);
            break;
       }

        i++;
    }
//    sleep(2);
}


int login(int a)
{
    setup();
    if(a)
    {
        setColor(236);

        gotoxy(65, 8);
        printf("Invalid User Name");

        gotoxy(65, 10);
        printf("  or Password");
    }
    setColor(238);

    gotoxy(15, 14);
    printf(">  Login As a Shopper");

    setColor(239);

    gotoxy(15, 17);
    printf("   Login As a Customer");

    gotoxy(15, 20);
    printf("   Home Page");

    int pos = 0;

    char ch;

    while(1)
    {
        gotoxy(0, 0);

        ch = getch();

        if(ch == 80 && !pos)
        {
            setColor(239);

            gotoxy(15, 14);
            printf("   Login As a Shopper");

            setColor(238);

            gotoxy(15, 17);
            printf(">  Login As a Customer");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(239);

            gotoxy(15, 17);
            printf("   Login As a Customer");

            setColor(238);

            gotoxy(15, 20);
            printf(">  Home Page");

            pos++;
        }

        else if(ch == 72 && pos == 2)
        {
            setColor(238);

            gotoxy(15, 17);
            printf(">  Login As a Customer");

            setColor(239);

            gotoxy(15, 20);
            printf("   Home Page");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(238);

            gotoxy(15, 14);
            printf(">  Login As a Shopper");

            setColor(239);

            gotoxy(15, 17);
            printf("   Login As a Customer");

            pos--;
        }
        else if(ch == 32 && !pos)
        {
            setColor(238);

//            gotoxy(65, 14);
//            printf("Shop Name:");

            gotoxy(65, 14);
            printf("Username:");

            gotoxy(65, 17);
            printf("Password:");

            setColor(219);

//            gotoxy(76, 14);
//            scanf(" %[^\n]",shop_name);

            gotoxy(76, 14);
            scanf("%s",user_name);

            gotoxy(76, 17);
            scanf("%s",pass);

            //gotoxy(65,30);
            s_avatar=shopper_user_check();

            //shopper_user_check();
            //printf("%d 44444444444444444444444444444444444444",s_avatar);
            //sleep(10000);
            if(s_avatar<0)
            {

                return login(1);//shows invalid user
                //printf("3333333333333355555555555555555555555555333333333333333333");
            }
            return 0;
        }


        else if(ch == 32 && pos==1)
        {
            setColor(238);

            gotoxy(65, 14);
            printf("Username:");

            gotoxy(65, 17);
            printf("Password:");

            setColor(219);

            gotoxy(76, 14);
            scanf("%s",user_name);

            gotoxy(76, 17);
            scanf("%s",pass);

            c_avatar=customer_user_check();

            if(c_avatar<0)
            {

                return login(1);//shows invalid user
            }
            else return 1;

        }
//        else if(ch == 32 && pos==2)
//        {
//            home_page();
//        }
        else if(ch == 32)   return pos;

    }
}

int sign_up(int a)
{
    setup();

    if(a)
    {
        setColor(236);

        gotoxy(65, 8);
        printf("This User Name");

        gotoxy(65, 10);
        printf("isn't available");
    }


    setColor(238);

    gotoxy(15, 14);
    printf(">  SignUp As a Shopper");

    setColor(239);

    gotoxy(15, 17);
    printf("   SignUp As a Customer");

    gotoxy(15, 20);
    printf("   Home Page");

    int pos = 0;

    char ch;

    while(1)
    {
        gotoxy(0, 0);

        ch = getch();

        if(ch == 80 && !pos)
        {
            setColor(239);

            gotoxy(15, 14);
            printf("   SignUp As a Shopper");

            setColor(238);

            gotoxy(15, 17);
            printf(">  SignUp As a Customer");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(239);

            gotoxy(15, 17);
            printf("   SignUp As a Customer");

            setColor(238);

            gotoxy(15, 20);
            printf(">  Home Page");

            pos++;
        }

        else if(ch == 72 && pos == 2)
        {
            setColor(238);

            gotoxy(15, 17);
            printf(">  SignUp As a Customer");

            setColor(239);

            gotoxy(15, 20);
            printf("   Home Page");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(238);

            gotoxy(15, 14);
            printf(">  SignUp As a Shopper");

            setColor(239);

            gotoxy(15, 17);
            printf("   SignUp As a Customer");

            pos--;
        }
        else if(ch == 32 && !pos)
        {
            setColor(238);

            gotoxy(65, 14);
            printf("Shop Name:");

            gotoxy(65, 17);
            printf("Name     :");

            gotoxy(65, 20);
            printf("Username :");

            gotoxy(65, 23);
            printf("Password :");

            setColor(219);

            gotoxy(76, 14);
            scanf(" %[^\n]",shop_name);

            gotoxy(76, 17);
            scanf(" %[^\n]",name);

            gotoxy(76, 20);
            scanf("%s",user_name);

            gotoxy(76, 23);
            scanf("%s",pass);
            if(s_uniqueID()) return sign_up(1);

            return 0;
        }
        else if(ch == 32 && pos==1)
        {
            setColor(238);


            gotoxy(65, 14);
            printf("Name     :");

            gotoxy(65, 17);
            printf("Username :");

            gotoxy(65, 20);
            printf("Password :");

            setColor(219);

            gotoxy(76, 14);
            scanf(" %[^\n]",name);

            gotoxy(76, 17);
            scanf("%s",user_name);

            gotoxy(76, 20);
            scanf("%s",pass);
            if(c_uniqueID()) return sign_up(1);
            return 1;

        }
        else if(ch == 32)   return pos;
        /// if(s_uniqueID()) return sign_up(1);

        //s_readdata();
        //show();


    }


    ///return sign_up(1);

    return 1;
}





int main()
{
    int f, f1, f2, f3, f4, f5, f6, f7, i, j;

    while(1)
    {
        f = home_page();

        if(!f)
        {
            f1 = login(0);
//            printf("%d 44444444",f1);
//            sleep(2);
            if(f1==0)
            {

                //f2=s_profile();
                while(1)
                {

                    f2=s_profile();
                    //printf("%d 233467246734343",f2);
                    //sleep(10000);
                    if(f2==0)
                    {
                         add_products();
                    }
                    else if(f2==1)
                    {
                         update_pricing();
                    }
                    else if(f2==2)
                    {
                         delete_product();
                    }
                    else if(f2==3) break;
                }
            }
            else if(f1==1) //login screen of Customer
            {

                while(1)
                {
                    f4=c_profile();

                    //printf("%d 233467246734343",f2);
                    //sleep(10000);
                    if(f4==0)
                    {
                         search_products();
                    }
                    else if(f4==1)
                    {
                         select_products();
                    }
                    else if(f4==2)
                    {
                         break;
                    }

                }

            }

        }
        else if(f==1)
        {
            f6=sign_up(0);
            if(f6==0)
            {
                s_saveInfo();
                s_readdata();
                s_avatar=number_of_shoppers-1;
                while(1)
                {

                    f3=s_profile();
                    //printf("%d 233467246734343",f2);
                    //sleep(10000);
                    if(f3==0)
                    {
                         add_products();
//                         search_products();
                    }
                    else if(f3==1)
                    {
                        update_pricing();
//                         select_products();
                    }
                    else if(f3==2)
                    {
                         delete_product();
                    }
                    else if(f3==3) break;
                }

            }
            else if(f6==1)
            {
                cc_saveInfo();
                c_readdata();
                c_avatar=number_of_customers-1;
                while(1)
                {
                    //c_readdata();
                    f5=c_profile();
                    //printf("%d 233467246734343",f2);
                    //sleep(10000);
                    if(f5==0)
                    {
                        search_products();
//                         add_products();
                    }
                    else if(f5==1)
                    {
                         select_products();
//                         update_pricing();
                    }
                    else if(f5==2) break;
//                    else if(f5==2)
//                    {
//                         delete_product();
//                    }

                }

            }
        }
        else
        {
            system("cls");
            return 0;
        }
    }
}



