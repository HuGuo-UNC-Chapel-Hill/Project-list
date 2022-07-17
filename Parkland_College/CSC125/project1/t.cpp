#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

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

//print out the current linked list (choice 1& choice menu)
void printfood(foodptr head );

int main()
{
    //srand(time(0));

    int WholeNodes=0;

    foodptr head=NULL,tail=NULL;

    //head=NULL;

    char choice;

    Read(head,tail,WholeNodes);

    //cout<<"R"<<WholeNodes;

    printfood( head );


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

    /*/the first node
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

     //debug
    cout<<tail->name<<endl;*/

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
    cout<<tail->name<<endl;
}

//print out the current linked list (choice 1& choice menu)
void printfood(foodptr head )
{
    foodptr temp;

    cout.setf(ios::left);
    cout<<"=======================================";
    cout<<"======================================="<<endl;
    cout<<setw(20)<<"Name"<<setw(20)<<"Group"<<setw(20);
    cout<<"Calories"<<setw(20)<<"Daily percentage"<<endl;
    cout<<"=======================================";
    cout<<"======================================="<<endl;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        cout<<setw(20)<<temp->name<<setw(20)<<temp->group;
        cout<<setw(20)<<temp->cal<<setw(20)<<temp->per<<endl;
    }
    //delete temp;
}
