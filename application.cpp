#include <iostream>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;


void menu();
void record();
void update();

int main(){
cout<<"Hello World"<<endl;


time_t rawtime;
struct tm * timeinfo;

time (&rawtime);
timeinfo = localtime (&rawtime);
printf("Current local time and date: %s", asctime(timeinfo));
int options;
while(options != 1 && options != 2)
{
menu();


cin>>options;

switch(options){

  case 1:
      record();
      break;
  case 2:
      update();
      break;
  case 3:
     options = 3;
     cout<<"Exiting ...."<<endl;
     exit(0);

  default:
     cout<<"Invalid Input"<<endl;
     

}
}
  return 0;
}



void menu(){

  cout<<"\nUniversity Student Examination System"<<endl;
  cout<<"1.Student Result Records\n";
  cout<<"2.Result Updates\n";
  cout<<"3.Exit\n";
  cout<<"\n\nKey In Your Options"<<endl;  
  
}

void record()
{ 
  string line;
  ifstream studentfile("student.txt");
  if(studentfile.is_open())
  {
  while (getline(studentfile,line))
   {
     cout<< line<<'\n';
    }
   studentfile.close();
   
  }
  else cout<<"Unable to open file\n";
 
}

void update()
{
 ofstream studentfile;
 studentfile.open("student.txt",std::ios_base::app);
 cout<<"What you want to update? \n";
 char input[20];
 char input2[20];
 cin>> input;
 cin>>input2;
 studentfile<<"\n"<< input <<"  "<<input2;
 cout<<"\n Update Successfully"<<endl;
 studentfile.close(); 

}

