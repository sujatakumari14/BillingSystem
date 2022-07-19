#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
    int pcode;
    float price;
    float dis;
    string pname;


    public:
     void menu();
     void administrator();
     void buyer();
     void add();
     void edit();
     void rem();  //to remove
     void list();  //to display list
     void receipt();
};

void shopping :: menu()
{
    m:
  int choice;
  string email;
  string password;


   cout<<"\t\t\t\t____________________________________\n";
   cout<<"\t\t\t\t                                     \n";
   cout<<"\t\t\t\t    Supermarket Main Menu            \n";
   cout<<"\t\t\t\t                                     \n";
   cout<<"\t\t\t\t_____________________________________\n";
   cout<<"\t\t\t\t                                      \n";
   cout<<"\t\t\t\t|  1)  Administrator      |\n";
   cout<<"\t\t\t\t|                         |\n";
   cout<<"\t\t\t\t|  2)  Buyer              |\n";
   cout<<"\t\t\t\t|                         |\n";
   cout<<"\t\t\t\t|  3) Exit                |\n";
   cout<<"\t\t\t\t|                         |\n";
   cout<<"\n\t\t\t\t Please select!\n\n";
   cin>>choice;

   switch(choice)
   {
            case 1:
               cout<<"\t\t\t  Please Login:  \n\n";
               cout<<" Enter Email   \n\n";
               cin>>email;
               cout<<endl;
               cout<<"Password       \n\n";
               cin>>password;

               if(email=="Sujata@gmail.com" && password=="Sujata@")   //email and password of the admin
               {
                   administrator();

               }
               else
               {
                 cout<<"Invalid email/password";
               }
               break;


            case 2:
                {
                    buyer();
                    //break;
                }
            case 3:
                {

                    exit(0);
                    //break;
                }

            default :
                {

                    cout<<"Please select from the given options";
                }

   }
goto m;
}


void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t  Administrator menu";
    cout<<"\n\t\t\t\t|____1) Add the product_______|";
    cout<<"\n\t\t\t\t|                             |";
    cout<<"\n\t\t\t\t|____2) Modify the product____|";
    cout<<"\n\t\t\t\t|                             |";
    cout<<"\n\t\t\t\t|____3) Delete the product____|";
    cout<<"\n\t\t\t\t|                             |";
    cout<<"\n\t\t\t\t|____4) Back to main menu_____|";

    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;
    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout<<"invalid choice!";

    }
    goto m;
}

void shopping ::buyer()
{
     m:
     int choice;
     cout<<"\t\t\t\t____________________\n";
     cout<<"\t\t\t\t     Buyer   \n";
     cout<<"\t\t\t\t____________________\n";
     cout<<"                            \n";
     cout<<"\t\t\t\t1) Buy product      \n";
     cout<<"                            \n";
     cout<<"\t\t\t\t2) Go back          \n\n";
     cout<<"\t\t\t   Enter your choice  :  ";

     cin>>choice;

     switch(choice)
     {
     case 1:
         receipt();
         break;

     case 2:
        menu();
        break;

     default:

        cout<<"invalid choice";

     }

     goto m;
}


void shopping:: add()
{
    m:

    fstream data;       //creating data of fstream class
    int c;
    int token=0;
    float p;
    float d;
    string n;


    cout<<"\n\n\t\t\t  Add new product";
    cout<<"\n\n\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product ";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"\n\n\t Discount on product";
    cin>>dis;


    data.open("database.txt",ios::in);//opening the file in reading mode

    if(!data)                   //if the file oesnot exist
    {

        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";  //writing to the file
        data.close();       //closing the file

    }
    else   //if file is there
    {
        data>>c>>n>>p>>d;

       while(!data.eof())     //make sure to check every content of the file through iteration
       {
           if(c ==pcode)         //if there is a duplicasy
           {
               token++;

           }
           data>>c>>n>>p>>d;            //reading from file;

       }

    data.close();    //closing the file



  if(token==1)
     goto m;      //if there is duplicates in product code

   else{

       //product code is unique  u can enter the product data inside the file
       data.open("database.txt",ios::app|ios::out);
       data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
       data.close();

   }
}

   cout<<"\n\n\t\t  Record inserted  !";
}

void shopping::edit()
{
    fstream data,data1;

    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t  Modify the record";
    cout<<"\n\n\t\t  Product code  :  ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFile doesn't exist!  ";
    }

    else{

        data1.open("database1.txt",ios::app|ios::out);      //edit the file in database1 and then rename it as database.txt

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)   //pkey is the pcode that the administrator wants to edit
            {

                cout<<"\n\t\t  Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount  :";
                cin>>d;

                //now all the updated details of the product will be entered with the help of data1 object

                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited  ";
                token++;
            }

            else{
                    //if the product code does not matches with anyone
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }

             data>>pcode>>pname>>price>>dis;

            }
            data.close();
            data1.close();


            //rename the database1 as database  using remove () and rename();

            remove("database.txt");
            rename("database1.txt","database.txt");

            if(token==0)
            {

                cout<<"\n\n Record not found sorry !";
            }

        }
    }

    void shopping::rem()
    {

        fstream data ,data1;
        int pkey;
        int token=0;
        cout<<"\n\n\t Delete product";
        cout<<"\n\n\t Product code  :";
        cin>>pkey;
        data.open("database.txt",ios::in);

        if(!data)
        {
            cout<<"File does't exist";
        }

        else{
            data1.open("database1.txt",ios::app|ios::out);
            data>>pcode>>pname>>price>>dis;

            while(!data.eof())
            {
                if(pcode==pkey)
                {
                    cout<<"\n\n\tProduct deleted succesfully";
                    token++;
                }
                else{
                    data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
                }

                data>>pcode>>pname>>price>>dis;
            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt","database.txt");

            if(token==0)
            {
                cout<<"\n\n  Record not found";
            }
        }
    }

void shopping::list()
{

    fstream data;
    data.open("database.txt",ios::in);

   cout<<"\n\n|____________________________________\n";
   cout<<"ProNo\t\tProdName\tPrice\tDiscount\n";
   cout<<"\n\n|____________________________________\n";
        data>>pcode>>pname>>price>>dis;

   while(!data.eof())
   {
       cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
         data>>pcode>>pname>>price>>dis;
   }

    data.close();


}

void shopping::receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t RECEIPT  ";
    data.open("database.txt",ios::in);

    if(!data)
    {
        cout<<"\n\n  Empty database";
    }

    else{
        data.close();

        list();   //to show the customer what items are available in super market
        cout<<"\n______________________________________\n";
        cout<<"\n|                                    \n";
        cout<<"\n     Please Place the order            \n";
        cout<<"\n|                                    \n";
        cout<<"\n______________________________________\n";

        do
        {
            m:

            cout<<"\n\nEnter the Product code:";
            cin>>arrc[c];
            cout<<"\n\nEnter the product quantity  :";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code.Please try again!";
                    goto m;
                }

            }
            c++;
            cout<<"\n\n Do u want to buy another product?  if yes then press y else no \t";
            cin>>choice;
        }
        while(choice=='y');


    cout<<"\n\n\t\t\t|______________RECEPIT____________________\n";
    cout<<"\nProduct No\t Product Name\t Product quantity\tprice\t Amount\tAmount with discount\n";


              for(int i=0;i<c;i++)
              {
                 data.open("database.txt",ios::in);
                 data>>pcode>>pname>>price>>dis;
                 while(!data.eof())
                       {
                         if(pcode==arrc[i])
                         {
                             amount=price*arrq[i];
                             dis=amount-(amount*dis/100);
                             total=total+dis;
                             cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                         }

                       data>>pcode>>pname>>price>>dis;
                       }

             data.close();
        }
    }

              cout<<"\n\n|____________________________________\n";
              cout<<"\n Total Amount  :"<<total;

    }


int main()
{
      shopping obj;
      obj.menu();
}



