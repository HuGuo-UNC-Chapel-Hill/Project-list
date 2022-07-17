#include <iostream>
//Libraries are used in C++ to add feature to the language
//there are 72 keywords in C++
//iostream is a library about input and output
using namespace std; // semicolons end a complete thought
/*****************************************************
 Author : Hu Guo
 Date : 2/7/2019
 Name : hello.cpp
 Description : Demo for today
*****************************************************/
int main()
// this is our startup function
// this also our end function
{
    // frills show organization
    int numberOfPods, peasPerPod, totalPeas;
    cout << "Press return after entering a number."<<endl;
    cout << "Enter the number of pods:"<<endl;
    cin >> numberOfPods;
    cout << "Enter the number of peas in a pod:"<<endl;
    cin >> peasPerPod;
    totalPeas = numberOfPods * peasPerPod;
    cout << "If you Have "<< numberOfPods<< " pea pods and "<< peasPerPod<< " peas in each pod, then"<<endl;
    cout << "you have "<< totalPeas<< " peas in all the pods."<<endl;
    // end function
    return 0;
}
