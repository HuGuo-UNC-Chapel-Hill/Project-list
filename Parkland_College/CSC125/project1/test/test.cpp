/**********************************
Author:     Hu Guo
Date:       07/03/2019
Name:       Project1.cpp
Description:   food menu(linked list & struct method)
***********************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <stdio.h>

#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

using namespace std;

struct Food
{
    string name;
    string group;
    float cal;
    float per;
    Food* next;
};

typedef Food* foodptr;

foodptr head=NULL, tail=NULL;

//read the file,initialize the list,
//and counter the whole numbers of nodes
void Read();

//initialize the linked list
void initialization(foodptr temp);

//print out the current linked list
//for (choice 1& choice menu)
void printfood( );

//welcome and choice menu at the beginning
void Welcome(char &choice);

//choice menu for(choice 1&2&3&4)
void Choice(char &choice);

//Search nodes for inputed food (choice 2)
void search(string name,float &calcount,float &percount);

//output the information of selected nodes (choice 2&3)
void outputmenu(string name0,string name1,string name2,float calcount,float percount);

//counter the linked list and return the number of the list (choice 3)
int counter();

////generate 3 different numbers of nodes in the linked list (choice 3)
void randomselection(int nodes,int &selected0,int &selected1,int &selected2);

//choose the node for selected number and return it (choice 3)
foodptr choose(int number);

//get the name, cal, and per form the selected node (choice 3)
void record(string &name,float &calcount,float &percount,int selected);

//find the node bigger than the limitation (choice 4)
int findcal(float key,foodptr tmp);

//delete the selected node from the linked list (choice 4)
void filter(int key);

int main()
{
    srand(time(0));


    ;

    //head=NULL;

    char choice;

    Read();

    //debug
    //printfood( );

    //input choice
    Welcome(choice);

    //do-while loop to keep running the program
    do
    {
        if(choice=='1')
        {

            choice=0;

            //Print out whole nodes
            printfood();

            //input choice
            Choice(choice);
        }

        else if(choice=='2')
        {
            choice=0;


            //Create variables
            string name0,name1,name2;
            float calcount=0,percount=0;

            //Prompt
            cout<<"\nPlease select three food for your meal."<<endl;

            //input selected food name
            cout<<"Enter food name 0: "<<GRN;
            cin>>name0;
            cout<<RESET;

            //Searching nodes for inputed food and calculate the cal and the per
            search(name0,calcount,percount);


            //input selected food name
            cout<<"Enter food name 0: "<<GRN;
            cin>>name1;
            cout<<RESET;
            search(name1,calcount,percount);

            //input selected food name
            cout<<"Enter food name 0: "<<GRN;
            cin>>name2;
            cout<<RESET;
            search(name2,calcount,percount);

           //output information of selected food
            outputmenu(name0, name1,name2,calcount, percount);

            //input choice
            Choice(choice);
        }

         else if (choice=='3')
        {
            choice=0;

            //create variables
            string name0,name1,name2;
            float calcount=0,percount=0;
            int selected0=0, selected1=0,selected2=0,WholeNodes=0;

            WholeNodes=counter();

            //get numbers of random selected food
            randomselection(WholeNodes,selected0,selected1,selected2);

            //debug
            //cout<<selected0<<" "<<selected1<<" "<<selected2<<endl;

            record(name0,calcount,percount,selected0);
            record(name1,calcount,percount,selected1);
            record(name2,calcount,percount,selected2);

            //output information of selected food
            outputmenu(name0, name1,name2,calcount, percount);

            //debug
            //printfood(head);

            //input choice
            Choice(choice);
        }

        else if (choice=='4')
        {
            choice=0;

            int node=0;
            float limitation=0;

            //inout the calorie limit
            cout<<"Enter calorie limit:"<<GRN;
            cin>>limitation;
            cout<<RESET;

            //delete the node which is bigger than limitation
            filter(limitation);

            //output the modified linked list
            printfood();

            //input choice
            Choice(choice);
        }

        else if (choice=='5')
        {
            exit (-1);
        }


    }while(choice!='5');

    return 0;
}

//read the file,initialize the list,
//and counter the whole numbers of nodes
void Read()
{
    //declare variables
    string name,group;
    float cal,per;

    //creat the ifstream
    ifstream fin;

    //open the txt file
    fin.open("/home/staff/dbock/csc125/projects/project1/foods.txt");

    //check existing of the txt file
    if(fin.fail())
    {
        cout<< "fail to open file";
        exit(-1);
    }


    //read the information from food file
    while(fin>>name>>group>>cal>>per)
    {
        foodptr temp=new Food;
        temp->name=name;
        temp->group=group;
        temp->cal=cal;
        temp->per=per;

        //initialize the linked list
        initialization(temp);
    }

    //recycle the memory
    //delete temp;

     //end the list
    tail->next=NULL;

    //close the file
    fin.close();
}

//initialize the linked list
void initialization(foodptr temp)
{

    //the first node
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }

    //other nodes
    else
    {
        tail->next=temp;
        tail=temp;
    }

    //end the list
    tail->next=NULL;

     //debug
    //cout<<tail->name<<endl;
}

//print out the current linked list
//for (choice 1& choice menu)
void printfood()
{
    foodptr temp;
    cout.setf(ios::left);
    cout<<GRN<<"=======================================";
    cout<<"======================================="<<endl;
    cout<<setw(18)<<"Name"<<setw(17)<<"Group"<<setw(16);
    cout<<"Calories"<<"Daily percentage"<<endl;
    cout<<"=======================================";
    cout<<"======================================="<<endl;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        cout<<setw(18)<<temp->name<<setw(18)<<temp->group;
        cout<<setw(16)<<temp->cal<<temp->per<<endl;
    }
    cout<<RESET;
}

//welcome and choice menu at the beginning
void Welcome(char &choice)
{

    cout<<"\n-----------------------------------"<<endl;
    cout<<"Welcome to Parkland Meal Selector"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"Please select from the following"<<endl;
    cout<<"1 - List food database"<<endl;
    cout<<"2 - Create meal by manual selection"<<endl;
    cout<<"3 - Create meal by random selection"<<endl;
    cout<<"4 - Remove foods high in calorie"<<endl;
    cout<<"5 - Exit"<<endl;
    cin>>choice;

}

//choice menu (choice 1&2&3&4)
void Choice(char &choice)
{
    cout<<"\n-----------------------------------";
    cout<<"-----------------------------------"<<endl;
    cout<<"Please select from the following"<<endl;
    cout<<"1 - List food database"<<endl;
    cout<<"2 - Create meal by manual selection"<<endl;
    cout<<"3 - Create meal by random selection"<<endl;
    cout<<"4 - Remove foods high in calorie"<<endl;
    cout<<"5 - Exit"<<endl;
    cin>>choice;
}

//Search nodes for inputed food (choice 2)
void search(string name,float &calcount,float &percount)
{
    string name1;

    //Create a pointer for struct food
    foodptr fname;

    //Set pointer to head
    fname=head;

    //Searching nodes
    while(fname->name!=name&&fname->next!=NULL)
        fname=fname->next;
    if(fname->name==name)
    {
        calcount+=fname->cal;
        percount+=fname->per;
    }

    //Re-input the food if did not find the food
    else
    {
        cout<<"Did not find the food, please re-input"<<endl;
        cin>>name1;
        search(name1,calcount,percount);
    }
}

//output the information of selected nodes (choice 2&3)
void outputmenu(string name0,string name1,string name2,float calcount,float percount)
{

    cout<<YEL;
    cout<<"\n========================================"<<endl;
    cout<<"Your selected meal"<<endl;
    cout<<"  Foods: "<<GRN<<name0<<" "<<name1<<" "<<name2<<endl;
    cout<<YEL<<"  Total Calorie count: "<<GRN<<calcount<<endl;
    cout<<YEL<<"  Total Daily percentage: "<<GRN<<"%"<<percount*100<<endl;
    cout<<YEL<<"========================================"<<endl;
    cout<<RESET;
}

//counter the linked list and return the number of the list (choice 3)
int counter()
{
    int i=1;
    foodptr tmp;
    tmp=head;
    while(tmp->next!=NULL)
    {
        i++;
        tmp=tmp->next;
    }
    return i;
}

//generate 3 different numbers of nodes in the linked list (choice 3)
void randomselection(int nodes,int &selected0,int &selected1,int &selected2)
{
    while(selected0==selected1||selected0==selected2||selected1==selected2)
    {
        selected0=rand()%nodes+1;
        selected1=rand()%nodes+1;
        if(selected0==selected1)
        {
            selected1=rand()%nodes+1;
        }
        selected2=rand()%nodes+1;
        if(selected0==selected2||selected1==selected2)
        {
            selected2=rand()%nodes+1;
        }
    }
}

//choose the node for selected number and return it (choice 3)
foodptr choose(int number)
{
    foodptr tmp;
    tmp=head;

    //push tmp to the selected node
    for(int i=1;i<number;i++)
        tmp=tmp->next;

    //return the selected node
    return tmp;
}

//get the name, cal, and per form the selected node (choice 3)
void record(string &name,float &calcount,float &percount,int selected)
{
    name=(choose(selected))->name;
    calcount+=(choose(selected))->cal;
    percount+=(choose(selected))->per;
}

//delete the selected node from the linked list (choice 4)
void filter(int key)
{
    foodptr current=head,previous=NULL;

    //for the first node which is bigger than limitation
    while(current&&current->cal>key)
    {
        previous=current;
        current=previous->next;
        head=current;
        delete previous;
    }

    //for other nodes which are bigger than limitation
    while(current)
    {
        if(current->cal<=key)
        {
            previous=current;
            current=current->next;
        }
        else
        {
            previous->next=current->next;
            delete current;
            current=previous->next;
        }
    }

}



