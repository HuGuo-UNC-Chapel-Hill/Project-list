#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>


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
int findcal(foodptr head,float filter);

//delete the selected node from the linked list (choice 4)
void delnode(foodptr &head,int number);

void deleteEntry(foodptr head,float key);



int main()
{
    srand(time(0));

    foodptr head,tail,newp;
    head=tail=newp=NULL;

    char choice;

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
            cout<<"\nPlease select three food for your meal."<<endl;

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

            //get the number of random selected food
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
	    cout<<"Enter calorie limit:";
        cin>>key;

   /*    struct food** pp = &head;
        while (*pp)
            {

        struct food* entry = *pp;

        // If key found, then put
        // next at the address of pp
        // delete entry.
        if (entry->cal > key) {
            *pp = entry->next;
            delete (entry);
        }

        // Else move to next
        else
            pp = &(entry->next);
        }*/
        /*
        foodptr prev,tmp;
        prev=NULL;
	    tmp=head;


        /*Take care of the case where leading nodes are value to be deleted
        while (tmp && tmp->cal>key)
        {
            prev = tmp;
            tmp = tmp->next;
            head = tmp;
            delete prev;
        }
        /*At the end of above loop our new head is known which makes things simpler
        /*Now we traverse the list from left to right
        while (tmp)
        {
            if (tmp->cal> key)
            {
                prev->next = tmp->next;
                delete tmp;
                tmp = prev->next;
            }
            else
            {
                prev = tmp;
                tmp = tmp->next;
            }
        }

            */

    foodptr tmp1,tmp2;
    tmp2=NULL;
    tmp1=head;
    while(tmp1&&tmp1->cal>key)
    {   tmp2=tmp1;
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
    //delete fname;
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
    //delete tmp;
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

    cout<<"\n==========================================="<<endl;
    cout<<"Your selected meal"<<endl;
    cout<<"  Foods: "<<name0<<" "<<name1<<" "<<name2<<endl;
    cout<<"  Total Calorie count: "<<calcount<<endl;
    cout<<"  Total Daily percentage: %"<<percount*100<<endl;


}

//find the node bigger than the limitation (choice 4)
int findcal(foodptr head,float filter)
{
    foodptr tmp5;
    tmp5=head;
    int i=1;
    while(tmp5->next!=NULL)
    {

        if(tmp5->cal>filter)
        {
            return i;
        }
        tmp5=tmp5->next;
        i++;
    }

}


//delete the selected node from the linked list (choice 4)
void delnode(foodptr &head,int node)
{
    foodptr tmp1,tmp2;
    tmp1=head;
    if(node==1)
    {
        tmp2=tmp1;
        tmp1=tmp2->next;
        head=tmp1;
        delete tmp2;

    }
    //situation for node is behind the first
    else
    {
    for(int i=0;i<node-2;i++)
        tmp1=tmp1->next;
    tmp2=tmp1->next;
    tmp1->next=tmp2->next;
    delete tmp2;
    }

    //debug
    //printfood(head);
}



