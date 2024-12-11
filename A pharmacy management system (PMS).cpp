#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
int main()
{       int choice;
        int drugchoice[5];
        int inventoryquantity[5];//quantity of medicines for calculating receipt
        int numberofmedicine;
        int indexnumber=0;//variable used to access array from index 0
        int totalprice=0;//the total bill purchased by the user 
        int length;
        int user_choice;
        int added_drug=0;
        int password=1234;  
        int access_password;
        char date[]={"9/25/2023"};

        string search;
        string name;
        string medicinelist[25]={"Amoxicillin","Ampicillin","Delafloxacin","Paracetamol","Ibuprofen",
                             "Naproxin","Morphine","Potassium","Ascorbic-Acid","Thiamine",
                             "Vitamin-D3","Anthistamine","Decognizant","Sertraline","Fluoxetine"};
         string medicinetype[25]={"Antibiotics","Antibiotics","Antibiotics","Anti-pain","Anti-pain",
                             "Anti-pain","Anti-pain","Vitamins","Vitamins","Vitamins",
                             "Vitamins","Antitussives","Antitussives","Antidepressants", "Antidepressants"};
        int medicineprice[25]={150,180,300,127,120,600,150,90,100,220,400,300,320,230,120};
        string medicine_info[20]={"Solid oral dosage form:50mg", "Powder for injection:500mg", "Powder for injection:100mg",
                             "Tablet:100mg to 500mg      ", "Tablet:200mg;500mg      ", "Tablet:325mg;500mg       ",
                             "Tablet(immediate):10mg     ", "Tablet:500mg (elemental)", "Tablet:50mg               ",
                             "Tablet: 50mg(hydrochloride)", "Oral liquid: 400 IU/ml  ", "Tablet(chewable):500mg   ",
                              "Tablet:200mg;300mg        ", "Tablet:100mg to 400mg   ", "Injection:25mg (HCL)    "  };
    cout<<right<<setw(40)<<"Pharmacy Management System\n";
    cout<<"-------------------------------------------------"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<setw(36)<<"Welcome to E-Pharmacy\n";
    cout<<"Menu\n";
    cout<<"choose from the given options:\n";
    cout<<"1. Buy a medicine\n";
    cout<<"2. Display medicine price list\n";
    cout<<"3. Search for available medicine\n";
    cout<<"4. To add medicine to the inventory(authorized user only)\n";
    cout<<"5. To exit from the system\n\n";
    cout<<"Enter your choice from the menu: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
               main_menu:  cout<<"choose the medicine you want to buy from the following list:\n";
                        cout <<"---------------------------------------------------------------------------------\n";
				        cout<<"Inventory ID"<<"\tDrugs Name"<<"   \t\tDrug Type"<<"\t\tDRUGS PRICE(Birr)"<<endl;
				        cout <<"---------------------------------------------------------------------------------\n";
                        for(int i=0;i<15;i++)
                        cout<<i+1<<"\t\t"<<medicinelist[i]<<"\t\t"<<medicinetype[i]<<"\t\t"<<medicineprice[i]<<endl;
                        cout <<"-------------------------------------------------------------------------\n";
                        cout <<"-------------------------------------------------------------------------\n";
            A:cout<<"Enter how many typesof medicine you want to buy(Maximum limit is 4 types of drugs): ";
            cin>> numberofmedicine;
               cout<<"Enter your name: ";
               cin.ignore();
              getline(cin, name);//cin>>name; fix this inorder to contain full name
                
                cout<<endl;
                if(numberofmedicine<5)//number of medicine type the user wants
                {
                

                    for(int i=numberofmedicine;i>0;i--)
                    {
                        cout<<"Enter Inventory ID of the medicine: ";
                        cin>>drugchoice[indexnumber];
                        cout<<endl;
                        cout<<"How many "<<medicinelist[drugchoice[indexnumber]-1]<<" would you like to order:";
                        cin>>inventoryquantity[indexnumber];
                        indexnumber++;

                    }
                }
                else{     
                    cout<<"You can't buy more than 4\n";
                            goto A;
                
                    }
            //cout<<medicinelist[drugchoice[0]-1];//the -1 is for accessing the right index   
cout<<"\n\n";
                cout<<"==========================================================================="<<endl;
                cout << "Order Taken Successfully"<<endl;
                cout<<"==========================================================================="<<endl;
                cout << "Here is the Reciept to Pay The Bill"<<endl;
                cout<<"==========================================================================="<<endl; 

                    
                cout <<"\t-------------------------------------------------------------------------\n";
                cout <<"\t                       Pharmacy Receipt                                  \n";
                cout <<"\t-------------------------------------------------------------------------\n";
                cout<<"\tName: "<<name<<"                                 Date"<<" "<<date<<"\n";
                cout <<"\t-------------------------------------------------------------------------\n";
                cout<<"\tNo.\tMedicine name\tprice\tquantity\ttotal price\n";
                indexnumber=0;
                for(int i=numberofmedicine;i>0;i--)
                {      
                    totalprice+=medicineprice[drugchoice[indexnumber]-1]*inventoryquantity[indexnumber];
                    //drugchoice is the inventory id stored
                    cout<<"\t"<<indexnumber+1   <<"\t"   <<medicinelist[drugchoice[indexnumber]-1]  <<"\t" <<medicineprice[drugchoice[indexnumber]-1] 
                    <<"\t" <<inventoryquantity[indexnumber]<<"\t\t"<<medicineprice[drugchoice[indexnumber]-1]*inventoryquantity[indexnumber]<<endl;
                    indexnumber++;
                }
                cout<<endl;
                cout<<"\t\t\t\t\tGrand total: "<<totalprice<<endl;
                cout <<"\t-------------------------------------------------------------------------\n";
        
         break;
    case 2:  
                  display_menu:              cout <<"---------------------------------------------------------------------------------------------------------\n";
				                cout<<"  Drugs Name"<<"   \t\tDrug Type"<<"\t\t\tDrug Info"<<"\t\t\tDRUGS PRICE(Birr)"<<endl;
                                cout <<"---------------------------------------------------------------------------------------------------------\n";
                for(int i=0;i<15;i++)
                cout<<i+1<<"."<<medicinelist[i]<<"\t\t"<<medicinetype[i]<<"\t\t"<<medicine_info[i]<< "\t\t" <<medicineprice[i]<<" Birr"<<endl;
                                cout<<"===========================================================================================================\n";
                                cout<<"\nIf you want to buy the drugs from the above list press 1\n";
                                cout<<"To exit the system press any key: ";
                                 cin>>user_choice;
                            cout<<"\n\n";
                                                if(user_choice==1)
                                                    goto main_menu;
                                                    else if(user_choice!=1)
                                                    goto exit_menu;
                                                else{
                                                    break;
                                                    
                                                }

            break;
    case 3:
                cout<<"Enter the medicine name you want to check from the inventory:\n";
                cin>>search;
                length=search.size();
   
                search[0]=toupper(search[0]);//to convert user input string to first letter capital and the rest to lower
                for(int i=1;i<length;i++) 
                search[i]=tolower(search[i]);
       for(int i=0;i<15;i++)
   {    
        
            if(medicinelist[i]==search)
            {
            cout<<"The drug is available in the inventory with the following medication details\n";
                            cout <<"---------------------------------------------------------------------------------\n";
                            cout<<"Inventory ID"<<"\tDrugs Name"<<"   \t\tDrug Type"<<"\t\tDRUGS PRICE(Birr)"<<endl;
                            cout <<"---------------------------------------------------------------------------------\n";
                            cout<<i+1<<"\t\t"<<medicinelist[i]<<"\t\t"<<medicinetype[i]<<"\t\t"<<medicineprice[i]<<endl;
                            cout<<"To buy the drug press 1\n";
                            cout<<"To exit the system press 2: ";
                            cin>>user_choice;
                            cout<<"\n\n";
                                                if(user_choice==1)
                                                    goto main_menu;
                                                    else if(user_choice==2)
                                                    goto exit_menu;
                                                else{
                                                    break;
                                                }
                    
            }
            else if(i==14)
                {  cout<<"------------------Drug not found!----------------------\n";
                  cout<<"if you want to see the available drugs in the inventory press 1\n";
                  cout<<"To exit the system press any key: ";
                  cin>>user_choice;
                  if(user_choice==1)
                                                    goto display_menu;
else if(user_choice==2)
                                                    goto exit_menu;
                                                else{
                                                    break;
                                                }
                }
                  
      }
   
    case 4:
         cout<<"Access to authorized people only enter the password:\n";
         cin>>access_password;
         if(access_password==password)
                  { 
                    cout<<"\n----------------------Access granteed-----------------------\n";
                    cout<<"enter how many types of drugs you want to add to the inventory\n";
                    cout<<"(you can only add maximum of 9 more drugs) ";
                    cin>> added_drug;
                    if(added_drug<10)
                        {for(int i=0;i<added_drug;i++)
                                        {  
                                            cout<<"Enter the name of the drug: ";
                                            cin.ignore();
                                            getline(cin,medicinelist[i+15]);
                                            medicinelist[i+15].resize(14);
                                            cout<<endl;
                                            cout<<"Enter the price per unit: Birr  ";
                                            cin>>medicineprice[i+15];
                                            cout<<endl;
                                            cout<<"Enter the drugs type(class): ";
                                            cin.ignore();
                                            getline(cin,medicinetype[i+15]);
                                            medicinetype[i+15].resize(14);
                                            cout<<endl;
                                            
                                        }
                                    cout<<"Medicine menu has been updated as following\n ";
                                    cout <<"---------------------------------------------------------------------------------\n";
                                    cout<<"Inventory ID"<<"\tDrugs Name"<<"   \t\tDrug Type"<<"\t\tDRUGS PRICE(Birr)"<<endl;
                                    cout <<"---------------------------------------------------------------------------------\n";
                                    for(int i=0;i<15+added_drug;i++)
                                    cout<<i+1<<"\t\t"<<medicinelist[i]<<"\t\t"<<medicinetype[i]<<"\t\t"<<medicineprice[i]<<endl;
                                    cout <<"-------------------------------------------------------------------------\n";
                                    cout <<"-------------------------------------------------------------------------\n";
                    
                    }
                  }
        else{ cout<<"password incorrect try again";}
        break;

case 5:
          exit_menu: exit(0);
         break; 




    
    

      default:
         break;
    }

     
   return 0;
}