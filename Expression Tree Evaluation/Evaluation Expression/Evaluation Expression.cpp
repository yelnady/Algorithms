// Evaluation Expression.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "all.h"
#include "Tree.h"
using namespace std;


int main()
{
	string a("+3*4/82");
	Tree *t=new Tree ;
	t->construct(a);
	t->printINorder();
	cout << endl;
	cout << t->evaluate();
	system("pause");
	return 0;
}

