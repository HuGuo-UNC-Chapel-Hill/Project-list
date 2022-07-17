#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <stdio.h>
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"


using namespace std;

struct food
{
    string name;
    string group;
    float cal;
    float per;
    food* next;
};

typedef food* foodptr;

//initialize the linked list from the text file
void Initial(ifstream &fin,foodptr &head,foodptr &tail,foodptr &newp);

//welcome and choice menu at the beginning
void Welcome(char &choice);

//choice menu (choice 1&2&3&4)
void Choice(char &choice);

//print out the current linked list (choice 1& choice menu)
void printfood(foodptr head );

//Search nodes for inputed food (choice 2)
void search(foodptr head,string name,float &calcount,float &percount);

//counter the linked list and return the number of the list (choice 3)
int counter(foodptr head);

//generate 3 different numbers of nodes in the linked list (choice 3)
void randomselection(int nodes,int &selected0,int &selected1,int &selected2);

//choose the node for selected number and return it (choice 3)
foodptr choose(foodptr head,int number);

//get the name, cal, and per form the selected node (choice 3)
void record(string &name,float &calcount,float &percount,int selected,foodptr head);

//output the information of selected nodes (choice 2&3)
void outputmenu(string name0,string name1,string name2,float calcount,float percount);

//find the node bigger than the limitation (choice 4)
void findcal(foodptr head,float key);


int main()
{
    srand(time(0));

    foodptr head,tail,newp;
    head=tail=newp=NULL;

    char choice;

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
        //Create linked nodes
        Initial(fin,head,tail,newp);

        //input choice
        Welcome(choice);


    //do-while loop to keep running the program
    do
    {
        if(choice=='1')
        {
            choice=0;

            //Create linked nodes
            //Initial(fin,head,tail,newp);
            //Print out whole nodes
            printfood(head);

            //input choice
            Choice(choice);
        }

        else if(choice=='2')
        {
            choice=0;

            //Create linked nodes
            //Initial(fin,head,tail,newp);
            //Create variables
            string name0,name1,name2;
            float calcount=0,percount=0;

            //Prompt
            cout<<GRN<<"\nPlease select three food for your meal."<<endl;

            //input selected food name
            cout<<"Enter food name 0: ";
            cin>>name0;

            //Searching nodes for inputed food and calculate the cal and the per
            search(head,name0,calcount,percount);


            cout<<"Enter food name 1: ";
            cin>>name1;
            search(head,name1,calcount,percount);
            cout<<"Enter food name 2: ";
            cin>>name2;
            search(head,name2,calcount,percount);
	    cout<<RESET;
           //output information of selected food
            outputmenu(name0, name1,name2,calcount, percount);

            //input choice
            Choice(choice);

        }
        else if (choice=='3')
        {
            choice=0;

            //Create linked nodes
            //Initial(fin,head,tail,newp);

            //create variables
            string name0,name1,name2;
            float calcount=0,percount=0;
            int nodes=0,selected0=0, selected1=0,selected2=0;

            // counter the number of whole linked list
            nodes=counter(head);

            //get numbers of random selected food
            randomselection(nodes,selected0,selected1,selected2);

            //debug
            //cout<<selected0<<" "<<selected1<<" "<<selected2<<endl;

            record(name0,calcount,percount,selected0,head);
            record(name1,calcount,percount,selected1,head);
            record(name2,calcount,percount,selected2,head);

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
            float key=0.0;

            //inout the calorie limit
            cout<<"Enter calorie limit:"<<GRN;
            cin>>key;
		 cout<<RESET;	
	   //findcal(head, key);

            foodptr tmp1,tmp2;
            tmp2=NULL;
            tmp1=head;

            //situation for the node is at the first
            while(tmp1&&tmp1->cal>key)
            {
                tmp2=tmp1;
                tmp1=tmp2->next;
                head=tmp1;
                delete tmp2;
            }
            //situation for node is behind the first
            while(tmp1)
            {
                if(tmp1->cal>key)
                {
                    tmp2->next=tmp1->next;
                    delete tmp1;
                    tmp1=tmp2->next;
                }
                else
                {
                    tmp2 = tmp1;
                    tmp1 = tmp1->next;
                }
            }

            //output the modified linked list
            printfood(head);

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

//initialize the linked list from the text file
void Initial(ifstream &fin,foodptr &head,foodptr &tail,foodptr &newp)
{
    //declare variables
    string name,group;
    float cal,per;

    //read from the txt and initializ
    while(fin>>name>>group>>cal>>per)
    {
       newp=new food;

       //debug
       //cout<<name<<" "<<group<<" "<<cal<<" "<<per<<endl;

       //initialize newp
       newp->name=name;
       newp->group=group;
       newp->cal=cal;
       newp->per=per;

       //Create linked nodes
       if(head==NULL)
       {
           head=newp;
           tail=newp;
       }
       else
       {
           tail->next=newp;
           tail=newp;
       }
    }
    tail->next=NULL;
    //delete newp;
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

//print out the current linked list (choice 1& choice menu)
void printfood(foodptr head )
{
    foodptr temp;
    cout.setf(ios::left);
    cout<<GRN<<"=======================================";
    cout<<"======================================="<<endl;
    cout<<setw(18)<<"Name"<<setw(18)<<"Group"<<setw(18);
    cout<<"Calories"<<setw(18)<<"Daily percentage"<<endl;
    cout<<"=======================================";
    cout<<"======================================="<<endl;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        cout<<setw(18)<<temp->name<<setw(18)<<temp->group;
        cout<<setw(18)<<temp->cal<<setw(18)<<temp->per<<endl;
    }
	cout<<RESET;


    //delete temp;
}

//Search nodes for inputed food (choice 2)
void search(foodptr head,string name,float &calcount,float &percount)
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
        search(head ,name1,calcount,percount);
    }
}

//counter the linked list and return the number of the list (choice 3)
int counter(foodptr head)
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
foodptr choose(foodptr head,int number)
{

    foodptr tmp;
    tmp=head;

    //push tmp to the selected node
    for(int i=1;i<number;i++)
        tmp=tmp->next;

    return tmp;
}

//get the name, cal, and per form the selected node (choice 3)
void record(string &name,float &calcount,float &percount,int selected,foodptr head)
{
    name=(choose(head,selected))->name;
    calcount+=(choose(head,selected))->cal;
    percount+=(choose(head,selected))->per;
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

//find the node bigger than the limitation (choice 4)
void findcal(foodptr head,float key)
{	
	foodptr tmp1,tmp2;
        tmp2=NULL;
        tmp1=head;
    //situation for the node is at the first
    while(tmp1&&tmp1->cal>key)
    {
        tmp2=tmp1;
        tmp1=tmp2->next;
        head=tmp1;
        delete tmp2;
    }
    //situation for node is behind the first
    while(tmp1)
    {
        if(tmp1->cal>key)
        {
           tmp2->next=tmp1->next;
           delete tmp1;
           tmp1=tmp2->next;
        }
        else
        {
           tmp2 = tmp1;
           tmp1 = tmp1->next;
        }
    }
}


