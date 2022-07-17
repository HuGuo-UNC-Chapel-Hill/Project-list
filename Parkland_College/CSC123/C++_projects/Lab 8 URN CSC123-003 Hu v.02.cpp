/**********************************
Author:     Hu Guo
Date:       04/10/2019
Name:       Lab8.cpp
Description:   Balls in the urn
***********************************************/

#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

void declration(vector<int>& urn);
//create the vector and set up the balls
void ballvalues(vector<int>& urn, int& ballvalues);
//pick up three balls and out put the total number of balls
//put back three balls for next customer
void printvector(vector<int> vec);
//print out the vector size and value

int main()
{
    srand(time(0));

    //declare vector for balls
    vector<int> urn(3,1);

    //declare array for counting
    int tally[25]={0};

    //set up balls in the urn
    declration(urn);

    //count 1000 times
    int i=0;
    while(i<1000)
    {
        cout<<endl;
        cout<<"\n"<<i+1<<"th customer";
        cout<<endl;
        int ballvalue=0;
        ballvalues(urn,ballvalue);
        tally[ballvalue]++;
        i++;
    }


    cout<<endl;

    //output the distribution
    for(int i=3;i<25;i++)
    {
        cout<<"Number of discounts "<<i<<"= "<<tally[i]<<endl;
    }

}

void printvector(vector<int> vec)
{
    cout<< "\nThe size of vector is "<<vec.size();
    cout<< endl;
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void declration(vector<int>& urn )
{
    int i=0;
    int number=1;
    while(i<7)
    {
        urn.push_back(number+1);
        urn.push_back(number+1);
        urn.push_back(number+1);
        i++;
        number++;
    }

}

void ballvalues(vector<int>& urn, int& ballvalues)
{

    int ball[3]={0};
    int ballpicked=0;
    for(int i=0;i<3;i++)
    {
        int choice={0};
        int temp=0;

        choice=rand()%urn.size();
        ballpicked+=urn[choice];

        temp=urn[choice];
        urn[choice]=urn[urn.size()-1];
        urn[urn.size()-1]=temp;

        ball[i]=0;
        ball[i]=urn[urn.size()-1];
        urn.pop_back();

        cout<< "\nThe picked ball is "<<ball[i];
        cout<< endl;

        printvector(urn);
    }

    cout<< "\nHold the number for next customer is ";
    cout<<ball[0]<<" "<<ball[1]<< " "<<ball[2]<<"\n";

    ballvalues=ballpicked;

    urn.push_back(ball[0]);
    urn.push_back(ball[1]);
    urn.push_back(ball[2]);
    cout<< "\nPush back balls to the urn.";

    printvector(urn);
}
