/**********************************
Author:     Hu Guo
Date:       04/10/2019
Name:       Lab8.cpp
Description:   Balls in the urn
***********************************************/
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

void declration(vector<int>& urn);
//create the vector and set up the balls
void ballvalues(vector<int>& urn, int& ballvalue,ofstream& fout);
//pick up three balls and output the total number of balls
//put back three balls for next customer
void printvector(vector<int> vec,ofstream& fout);
//print out the current vector size and value

int main()
{
    srand(time(0));

    //declare vector for balls
    vector<int> urn(3,1);

    //declare array for counting
    int tally[25]={0};

    //set up balls in the urn
    declration(urn);

    //declare fout
    ofstream fout;
    fout.open("HistoryLog.txt",std::ios::app);

    //check fout
    if(fout.fail())
    {
        cout<<"\nOpening HistoryLog failed";
        exit(-1);
    }


    //count 1000 times
    int i=0;
    while(i<1000)
    {
        fout<<endl;
        fout<<"\n"<<i+1<<"th customer";
        fout<<endl;
        int ballvalue=0;
        ballvalues(urn,ballvalue,fout);
        tally[ballvalue]++;
        i++;
    }


    cout<<endl;
    fout<<endl;

    //output the distribution
    for(int i=3;i<25;i++)
    {
        cout<<"Number of discounts "<<i<<"= "<<tally[i]<<endl;
        fout<<"Number of discounts "<<i<<"= "<<tally[i]<<endl;
    }

    //close fout
    fout.close();

    cout<<"\nPlease check the 'HistoryLog.txt' for every customer's discount";
    cout<<endl;
    return 0;
}

void printvector(vector<int> vec, ofstream& fout)
{
    fout<< "\nThe size of vector is "<<vec.size();
    fout<< endl;
    for(int i=0;i<vec.size();i++)
    {
        fout<<vec[i]<<" ";
    }
    fout<<endl;
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

void ballvalues(vector<int>& urn, int& ballvalue, ofstream& fout)
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

        fout<< "\nThe "<<i+1<<"th picked ball is "<<ball[i];
        printvector(urn,fout);
    }

    fout<< "\nThe discount for this customer is "<<ballpicked;
    fout<<"% ("<<ball[0]<<" "<<ball[1]<< " "<<ball[2]<<")\n";

    ballvalue=ballpicked;

    urn.push_back(ball[2]);
    urn.push_back(ball[1]);
    urn.push_back(ball[0]);
    fout<< "\nPush back balls to the urn.";
    printvector(urn,fout);
}
