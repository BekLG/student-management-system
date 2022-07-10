

//this program is a frame work in which the full program is
//to be developed based on it. open this file in your compiler
//and continue coding the remaining parts.

//here include other appropriate header files.
#include <iostream>
#include<fstream>
#include<string>
#include<stdlib.h> // to use function exit()
#include <cstring>

using namespace std;

//here write the declaration of Course and Student structures.
struct Student {
char ID[10];
char fullName[40];
int age;
char sex[4];
char department[60];
char cID [10];
};

struct Course {
char cID[10];
char title[40];
int creditHour;
};

//here are the prototypes.
void showChoices();//shows the menus.
void writeCourse(fstream& aFile, char filename[]); // accept from user and write course data
void writeStud(fstream& aFile, char filename2[], char filename[]); //accept from user and write student data
void searchDispStud(fstream& aFile, char filename2[]); // search a student by its course
void readStudent(fstream& aFile, char filename2[]); // read all students data and display
void readCourse(fstream& aFile, char filename[]); //read all course data and display
void searchstudNameId(fstream& aFile, char filename2[]); // search student by name or id and display
void searchcourseNameId(fstream& aFile, char filename[]); // search course by name or id and dissplay


int main()
{
    //declare appropriate variables here.
    //like fstream variable , filename, etc.
   Course cr;
   Student s;
   fstream aFile;
   char* filename;
   filename="course.dat";

   char* filename2;
   filename2="student.dat";

    int choice;
    do
    {
        showChoices(); //display the menu
        cin >> choice;
	switch (choice)
        {
	   case 1:
              //here call function to write courses data.
              writeCourse(aFile,filename);
	         break;
	   case 2:
              //here call function to write students data
              writeStud( aFile, filename2, filename);
	         break;
	   case 3:
              //here call function to search student
              //given course id and display search result.
              searchDispStud(aFile, filename2);
	         break;
     case 4:
              //here call function to read students data
              readStudent( aFile, filename2);              
	         break;
     case 5:
                 //here call function to read courses data
               readCourse( aFile, filename);            
	         break;
      case 6:
            //  here call function to serch student by name or id
              searchstudNameId( aFile, filename2);         
         break;
      case 7:
              //here call function to search course by title or id
              searchcourseNameId( aFile, filename);
         break;
      case 8:
            //here write code to exit from the program.
            cout<<"-----Alert----"<<endl;
            cout<<"program closed"<<endl;
            cout<<"--------------"<<endl;
            exit(0);
         break;
	   default:
            cout<<  "----Alert----"<<endl;
            cout << "Invalid input" << endl;
            cout<<  "-------------"<<endl;
	  }
    }while (choice != 8);

    return 0;
}

void showChoices()
{
	cout << "MENU" << endl;
	cout << "1: Enter Courses Data " << endl;
	cout << "2: Enter Students Data " << endl;
	cout << "3: Search for Student " << endl;
	cout << "4: Display Student Data " << endl;
	cout << "5: Display Course Data " << endl;
  cout << "6: Search student by name or ID " << endl;
  cout << "7: Search course by title or ID " << endl;
	cout << "8: Exit " << endl;
	cout << "Enter your choice :";
}

void writeCourse(fstream& aFile, char filename[])
{
    //here write code to write course data
    Course cr;
     cout<<"enter ID: ";
     cin>>cr.cID;
     cout<<"enter Title: ";
     cin>>cr.title;
     cout<<"enter Credit hour: ";
     cin>>cr.creditHour;

   aFile.open(filename,ios::out|ios::app);
   if(!aFile)
   {
     cout<<"----------------Alert--------------------"<<endl;
     cout<<filename<<" file opening error for writing"<<endl;
     cout<<"program terminating"<<endl;
     cout<<"-----------------------------------------"<<endl;
     exit(0); 
   }
   else
   {

     aFile<<"Course ID: "<<cr.cID<<"    Course Title: "<<cr.title<<"    Creadit Hour: "<< cr.creditHour<<endl;    
    cout<<"file written sucessfuly "<<endl;
    aFile.close();
}
}

void writeStud(fstream& aFile, char filename2[], char filename[])
{
    //here write code to write student data. here, course id
    //should be already existed. Otherwise report error
    //write the code that check if course id exist after finishing all the other features
     Student s;

     cout<<"Enter student ID: ";
     cin>>s.ID;
     cout<<"Enter student name: ";
     cin>>s.fullName;
     cout<<"Enter student Age: ";
     cin>> s.age;
     cout<<"Enter student Sex: ";
     cin>> s.sex;
     cout<<"Enter student Department: ";
     cin>> s.department;
     cout<<"Enter Course Id: ";
     cin>>s.cID;

    aFile.open(filename,ios::in); // opening course file to check if courseID exists.
    if(!aFile)
    {
      cout<<"----------------Alert--------------------"<<endl;
      cout<<filename2<<" Eroor while checking course"<<endl;
      cout<<"program terminating"<<endl;
      cout<<"-----------------------------------------"<<endl;
      exit(0); 
    }
    else
    {   
    string yesmessage=" student registered successfully "; //messages or notifications to be displayed
    string nomessage=" the course id does not exist!";
    string message= nomessage;
    string line;

    while(!aFile.eof())
    {    
			getline(aFile, line);
			size_t found = line.find(s.cID);
			if (found != string::npos)
      {
        aFile.close(); // closing course file
        aFile.open(filename2,ios::out|ios::app);
          if(!aFile)
          {
            cout<<"----------------Alert--------------------"<<endl;
            cout<<filename2<<" file opening error for writing"<<endl;
            cout<<"program terminating"<<endl;
            cout<<"-----------------------------------------"<<endl;
            exit(0); 
          }
          else
          {
            aFile<<" student ID: "<<s.ID <<" Fullname: "<<s.fullName <<" Age: "<<s.age <<" Sex: "<<s.sex <<" Department: "<<s.department <<" Course Id: "<<s.cID<<endl;
            message=yesmessage;
            aFile.close(); //closing student file
          }                 
      }              
    } 
     cout<<"--------------------------------"<<endl; 
     cout<<message<<endl; //displaying notification
     cout<<"--------------------------------"<<endl;     
    } 
}

void searchDispStud(fstream& aFile, char filename2[])
{
     //here write code to search for student based on
     //course id (given from user) and display the
     //result. use 'studReport' function below to
     //display the result.
   
    Student s;
    string word;
    string line;
    cout<<"Enter Course code to search for student based on course id"<<endl;
     cin>>word;
    aFile.open(filename2,ios::in);
    if(!aFile)
   {
      cout<<"----------------Alert--------------------"<<endl;
      cout<<" Eroor while opening course data"<<endl;
      cout<<"program terminating"<<endl;
      cout<<"-----------------------------------------"<<endl;
      exit(0); 
   }
   else
   {
    cout<<"--------Here is the list of students with Course ID"<<'"'<<word<<'" '<<"--------"<<endl;

    string yesmessage="   ";
    string nomessage=" The word you entered is not found! \n please check your spelling...";
    string message= nomessage;
    while(!aFile.eof())
    {
			getline(aFile, line);
			size_t found = line.find(word);

			if (found != string::npos)
      {
			cout<< line<<endl; 
      message=yesmessage;
      cout<<"--------------------------------------------------------------------------------------"<<endl;
      }    
    }   
       cout << message<<endl;
       aFile.close();
   }
}
void readStudent(fstream& aFile, char filename[])
{     
  cout<<endl;
  cout<<"------All Students Informaton ---------"<<endl;

   aFile.open(filename,ios::in);
   if(!aFile)
   {
      cout<<"----------------Alert--------------------"<<endl;
      cout<<" Eroor while opening student data"<<endl;
      cout<<"program terminating"<<endl;
      cout<<"-----------------------------------------"<<endl;
      exit(0);
   }
   else
   {
        string line;
        while(getline(aFile,line))
        {
            cout<<line<<endl;
        }
           aFile.close();
   }
      cout<<"--------------------------------------------------------------------------------------"<<endl;
     //here write code to read and display all students data.
}
void readCourse(fstream& aFile, char filename2[])
{  cout<<endl;
 cout<<"------All courses info ---------"<<endl;
     //here write code to read and display all course data.
     aFile.open(filename2,ios::in);
   if(!aFile)
   {
      cout<<"----------------Alert--------------------"<<endl;
      cout<<" Eroor while opening course data"<<endl;
      cout<<"program terminating"<<endl;
      cout<<"-----------------------------------------"<<endl;
      exit(0);
   }
   else
   {
        string line;
        while(getline(aFile,line))
        {
            cout<<line<<endl;
        }
           aFile.close();
   }
      cout<<"--------------------------------------------------------------------------------------"<<endl;
   }

   void searchstudNameId(fstream& aFile, char filename2[])
{
    Student s;
    string word;
    string line;
    cout<<"Enter Name or ID to search for a student"<<endl;
    cout<<"Note: words are case sensetive! 'A' and 'a' are not the same."<<endl;

     cin>>word;
    aFile.open(filename2,ios::in);

    if(!aFile)
   {
      cout<<"----------------Alert--------------------"<<endl;
      cout<<" Eroor while opening student data"<<endl;
      cout<<"program terminating"<<endl;
      cout<<"-----------------------------------------"<<endl;
      exit(0);
   }
   else
   {  
    string yesmessage="   ";
    string nomessage=" The word you entered is not found! \n please check your spelling...";
    string message= nomessage;

    while(!aFile.eof())
    {    
			getline(aFile, line);
			size_t found = line.find(word);

			if (found != string::npos)
      {
			cout<< line<<endl; 
      message=yesmessage;
            cout<<"--------------------------------------------------------------------------------------"<<endl;
      }    
    } 
       cout << message<<endl;  
      aFile.close();
   }
}

void searchcourseNameId(fstream& aFile, char filename[])
{
    Course cr;
    string word;
    string line;
    cout<<"Enter Name or ID to search for a Course"<<endl;
    cout<<"Note: words are case sensetive! 'A' and 'a' are not the same."<<endl;
     cin>>word;
    aFile.open(filename,ios::in);
    
    if(!aFile)
   {
      cout<<"----------------Alert--------------------"<<endl;
      cout<<" Eroor while opening course data"<<endl;
      cout<<"program terminating"<<endl;
      cout<<"-----------------------------------------"<<endl;
      exit(0);
   }
   else
   {  
    string yesmessage="   ";
    string nomessage=" The word you entered is not found! \n please check your spelling...";
    string message= nomessage;

    while(!aFile.eof())
    {    
			getline(aFile, line);
			size_t found = line.find(word);

			if (found != string::npos)
      {
			cout<< line<<endl; 
      message=yesmessage;
            cout<<"--------------------------------------------------------------------------------------"<<endl;
      }  
    }  
       cout << message<<endl;
 
      aFile.close();
   }

}
