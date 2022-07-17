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

//read the file,initialize the list,
//and counter the whole numbers of nodes
void Read(foodptr &head,foodptr &tail,int &WholeNodes);

//initialize the linked list
void initialization(foodptr &head,foodptr &tail,foodptr temp);

//print out the current linked list
//for (choice 1& choice menu)
void printfood(foodptr head );

//welcome and choice menu at the beginning
void Welcome(char &choice);

//choice menu for(choice 1&2&3&4)
void Choice(char &choice);

//Search nodes for inputed food (choice 2)
void search(foodptr head,string name,float &calcount,float &percount);

//output the information of selected nodes (choice 2&3)
void outputmenu(string name0,string name1,string name2,float calcount,float percount);

////generate 3 different numbers of nodes in the linked list (choice 3)
void randomselection(int nodes,int &selected0,int &selected1,int &selected2);

//choose the node for selected number and return it (choice 3)
foodptr choose(foodptr head,int number);

//get the name, cal, and per form the selected node (choice 3)
void record(string &name,float &calcount,float &percount,int selected,foodptr head);


int main()
{
    srand(time(0));

    int WholeNodes=0;

    foodptr head=NULL,tail=NULL;

    //head=NULL;

    char choice;

    Read(head,tail,WholeNodes);

    //debug
    //printfood( head );

    //input choice
    Welcome(choice);

    //do-while loop to keep running the program
    do
    {
        if(choice=='1')
        {

            choice=0;

            //Print out whole nodes
            printfood(head);

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
            search(head,name0,calcount,percount);


            //input selected food name
            cout<<"Enter food name 0: "<<GRN;
            cin>>name1;
            cout<<RESET;
            search(head,name1,calcount,percount);

            //input selected food name
            cout<<"Enter food name 0: "<<GRN;
            cin>>name2;
            cout<<RESET;
            search(head,name2,calcount,percount);

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
            int selected0=0, selected1=0,selected2=0;

            //get numbers of random selected food
            randomselection(WholeNodes,selected0,selected1,selected2);

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

        else if (choice=='5')
        {
            exit (-1);
        }


    }while(choice!='5');

    return 0;
}

//read the file,initialize the list,
//and counter the whole numbers of nodes
void Read(foodptr &head,foodptr &tail,int &WholeNodes)
{
    //declare variables
    string name,group;
    float cal,per;

    //creat the ifstream
    ifstream fin;

    //open the txt file
    fin.open("foods.txt");

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

        //counter the numbers of food
        ++WholeNodes;

        //initialize the linked list
        initialization(head,tail,temp);
    }

    //recycle the memory
    //delete temp;

     //end the list
    tail->next=NULL;

    //close the file
    fin.close();
}

//initialize the linked list
void initialization(foodptr &head,foodptr &tail,foodptr temp)
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
void printfood(foodptr head )
{
    foodptr temp;
    cout.setf(ios::left);
    cout<<GRN<<"=======================================";
    cout<<"======================================="<<endl;
    cout<<setw(18)<<"Name"<<setw(17)<<"Group"<<setw(18);
    cout<<"Calories"<<"Daily percentage"<<endl;
    cout<<"=======================================";
    cout<<"======================================="<<endl;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        cout<<setw(18)<<temp->name<<setw(18)<<temp->group;
        cout<<setw(18)<<temp->cal<<temp->per<<endl;
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

    //return the selected node
    return tmp;
}

//get the name, cal, and per form the selected node (choice 3)
void record(string &name,float &calcount,float &percount,int selected,foodptr head)
{
    name=(choose(head,selected))->name;
    calcount+=(choose(head,selected))->cal;
    percount+=(choose(head,selected))->per;
}
