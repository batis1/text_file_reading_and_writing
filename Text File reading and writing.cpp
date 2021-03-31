#include "stdafx.h"
#include<fstream>
#include<iostream>
#include<stdlib.h>

using namespace std;

class Student 
{
	char *name;
	int num;
	int grade;
public:
	Student(char *nm,int n,int g) {name=new char[strlen(nm)+1];strcpy(name,nm); num=n;grade=g;}
	Student() { }
	~Student() { }

	friend void CreateStudent(Student *s1);//friend function to create student by computert 
	friend ostream & operator <<(ostream &out,Student *s);
	friend istream & operator >>(istream &in,Student  *s);
};

ostream & operator <<(ostream &out,Student *s)
{
	out<<s->name<<" "<<s->num<<"  "<<s->grade;
	return out;
	
}
istream & operator >>(istream &in,Student *s)
{
	char temp[50];

	in>>temp>>s->num>>s->grade;
	s->name = new char[strlen(temp)+1];
	strcpy(s->name,temp);
	return in;
	
}
void CreateStudent( Student * s)
{
	static int snum=0;
	snum++;
	char *str1;
	
	str1= new char[13];
	sprintf(str1,"Student%05d",snum);
	
	
	
	s->name =str1;
	s->num = 2015*100000+snum;
	s->grade= 500+rand()%251;
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	ofstream outFile;
	ifstream inFile;	
	int i;
	int snum=100;
	Student st;
	outFile.open("a1.txt",ios::out);
	if(outFile.fail())
	{
		return 1;
	}
	for(i=0;i<snum-1;i++)
	{
		CreateStudent(&st);
		outFile<<&st<<endl;	
	}
	CreateStudent(&st);
	outFile<<&st;	
	outFile.close();
	
	inFile.open("a1.txt",ios::in);
	if(inFile.fail())
	{
		return 1;
	}
	while(!inFile.eof())
	{
		inFile>>&st;
		cout<<&st<<endl;

	}
	return 0;
}
