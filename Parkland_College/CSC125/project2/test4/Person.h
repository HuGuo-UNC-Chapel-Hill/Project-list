#ifndef PERSON_H
#define PERSON_H


class Person:public Account
{
private:
    string firstname,lastname,address,ssn;
public:
  Person();
  Person(float bal, float rate,string firstname,string lastname,string address,string ssn);
  void setFirst(string firstname){this->firstname=firstname;}
  void setLast(string lastname){this->lastname=lastname;}
  void setAdd(string address){this->address=address;}
  void setSsn(string ssn){this->ssn=ssn;}
  string getFirst(){return firstname;}
  string getLast(){return lastname;}
  string getAdd(){return address;}
  string getSsn(){return ssn;}
  void perPrint();
};


#endif // PERSON_H
