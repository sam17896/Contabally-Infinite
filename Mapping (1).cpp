#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
void EnumQ(int);//check positive rational enumeration
void EnumZ(int);//checks integer enumeration
void domainZ();//checks integer domain enumerations
int codomainZ();//checks integer co-domain enumerations
void domainQ();//checks positive rational domain enumerations
int codomainQ();//checks positive rational co-domain enumerations
bool isExist(vector<float>,float);//checks if value already exists
	
int main()
{
	int choice;
	
	cout<<"Which format you want to enter.\n\n1.Integer(Z)\n2.Positive Rational(Q+)\n\nEnter your choice: ";
	cin>>choice;

	switch(choice)//switch case choice for rational or integer input
	{
		case 1:
			cout<<"\nWhat do you want to enter\n\n1.Domain\n2.Co-domain\n\nEnter your choice: ";
			cin>>choice;
			EnumZ(choice);//functional call for integer enumeration
			break;
		
		case 2:	
			cout<<"\nWhat do you want to enter\n\n1.Domain\n2.Co-domain\n\nEnter your choice: ";
			cin>>choice;
			EnumQ(choice);//function call for rational enumeration
			break;
			
			default: cout<<"Invalid choice!"; break;//default case on invalid input
				
	}
}

void EnumZ(int choice)//function implementaion of integers enumeration
{
	switch(choice)
	{
		case 1: domainZ(); break;//function call for natural number domain enumeration
		case 2: cout<<"Co-domain has natural pre-image "<<codomainZ(); break;//for positive rational co-domain enumeration
		default: cout<<"Invalid choice!"; break;
	}
}

void EnumQ(int choice)//function implementaion of positive rational enumeration
{
	switch(choice)
	{
		case 1: domainQ(); break;//function call for natural number domain enumeration
		case 2: cout<<"Co-domain has natural pre-image "<<codomainQ(); break;//for integer co-domain enumeration
		default: cout<<"Invalid choice!"; break;
	}
}

void domainZ()//domain enumeration function for integers
{
	system("cls");//functiona call for clear the console screen
	int num;
	cout<<"Enter natural number domain value: ";
	cin>>num;//input the domain value

		cout<<"Natural\t    Integer"<<endl;
		for(int i=1;i<=num; i++)//loop will run unless it reaches the input value and loop will print the sequence till number
		{
			if(i%2 == 0) cout<<i<<"\t\t"<<i/2<<endl;//assign even natural numbers the co-domain of positive integers
			if(i%2 != 0) cout<<i<<"\t\t"<<(i-1)/(-2)<<endl;//assign odd natural numbers the co-domain of negative integers
		}
}

int codomainZ()//co-domain enumeration function for integers
{
	system("cls");//functiona call for clear the console screen
	int num;
	cout<<"Enter integer co-domain: ";
	cin>>num;
					
	if(num == 0) return 1;//map integer 0 to natural number 1
	else if(num > 0) return num*2;//map positive integers to even natural numbers
	else if(num < 0) return 1 - num*2;//map negative integers to odd natural numbers
}

void domainQ()//domain enumeration function for rational
{
    system("cls");//function call for clear the console screen
    vector<float>v;//declaring vector to store every value for comparing if it already exist
    int get;
	int p = 1,q = 1, a = 2;
	
	cout<<"Enter natural domain: ";
	cin>>get;//get the number untill a sequence will print	
	cout<<"Natural\t     Rational"<<endl;
	cout<<"   "<<1<<"\t\t"<<p<<"/"<<q<<endl;			
	
	v.push_back((float)p/q);//store initial rational value

	while(a <= get)//loop will run till it doesn't reach to number
	{
		if(p==1 && q==1) q++; //this condition will true in start only when there is 1/1 so it will generate number 1/2
						
		//this is going up condition when there is 2/1,3/1,4,1.... this will go up straight to 1/3,1,4,1/5....
		else if(q==1 && p!=1) 
		{
		  q = q + p;
		  p = 1;
	    }   
		
		//Below all conditions are going down conditions	
		else
		{
		p++;
		q--;
		}
								
		if(!isExist(v,(float)p/q))	//function checks whether new generated value exists or not in vector
		{
			//if value doesnt exist it will print it
		cout<<"   "<<a<<"\t\t"<<p<<"/"<<q<<endl;
		a++;
		}
		
		else
		{
			//if value exist then generate next value
			p++;
			q--;
			while(isExist(v,(float)p/q))//loop runs untill new generated values already exist
			{
			 p++;
			 q--;
			}
		
		cout<<"   "<<a<<"\t\t"<<p<<"/"<<q<<endl;
		a++;
		}
					
		v.push_back((float)p/q);//insert new unique value in vector
	}					
}

int codomainQ()//co-domain enumeration function for positive rational number
{
	system("cls");//functiona call for clear the console screen
	int num,den;//declare numerator and denominator

	cout<<"Enter numerator: ";
	cin>>num;//numerator
	cout<<"Enter denominator: ";
	cin>>den;//denominator
	
	float value = (float)num/den;//store decimal value by numerator/denominator

	if(value<0)//check if user gives negative rational number
	{
		cout<<"Only positive rational number as input";
		exit(0);
	}

	vector<float>s;
	int p = 1,q = 1,count = 1;

	s.push_back((float)p/q);//push initial rational number

	while((float)p/q != value)//loop will start from 1/1 rational numbers till it reaches to required rational number and increment in one after every single mapping and return the last mapped value
	 {
		if(p==1 && q==1) q++;
	
		//up condition						
		else if(q==1 && p!=1) 
		{
		  q = q + p;
		  p = 1;
	    }   
		
		//down condition
		else
		{
		p++;
		q--;
		}
												
		if(!isExist(s,(float)p/q))	count++;// map value will only increment if it is distinct value
			
		else
		{
		p++;
		q--;
		while(isExist(s,(float)p/q))//loop runs untill new generated values already exist
		{
			p++;
			q--;
		}
		count++;//increment in map value by one
	  	}			
		s.push_back((float)p/q);//insert new unique value to vector
	}	
	return count;//return mapped value
}		
	
bool isExist(vector<float>v, float value)//this function checks if new generated value already exists
{
	for(int i=0; i<v.size(); i++)//loop till size of vector
	  if(value==v[i]) return true;//if value found return yes
			return false;//if not then return no
}
