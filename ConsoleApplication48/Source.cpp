#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
struct date
{
	int day ;
	int month;
	int year ;
};
struct task 
{
	string title ;
	string details ;
	date due_date ;
	int priority ;
	//bool notdone ;
	int done;
};
vector<task> vec; 
int menu() ;
void add(string t2, string d2 , date due2 , int p2 ) ;
void is_done() ;
void edit() ;
void Delete();
void display () ;
void display_done();
void display_overdue() ;
void done_today() ;
void search() ;
void save() ; 
void load(); 
void main()
{
	//ofstream showdata ;
	//ifstream takedata ;
	//takedata.open("tasks_file.txt") ;
	//showdata.open("tasks_file.txt") ;
	string title , details ;
	int priority ;
	date due_date ;
	load();
    bool working = true;
    cout << "Welcome to To-Do list program!\n" << endl;
    int choice;
    do {
 
         choice = menu();
 
        switch(choice) {
 
            case 1:
				system("cls") ;
				system ( "color 0B" );
				int amount;
                cout << "how many items do you want to add?? " ;
                cin >> amount;
				for(int i=0 ;i<amount ; i++)
				{
					cout <<"enter the title for task number " << i+1<< " : " ;
					cin >> title ;
		//			takedata >> title ;
	                cout <<"enter the details for task number " << i+1<< " : " ;
					cin >> details ;
			//		takedata >> details ;
	                cout << "enter the due date for task number " << i+1<< " (day month year): " ;
					cin >> due_date.day >> due_date.month >> due_date.year ;
				//	takedata >> due_date.day >> due_date.month >> due_date.year ;
	                cout <<"enter the priority for task number (1,2,3) " << i+1<< " : " ;
					cin >> priority ;	
					//takedata >> priority ;	
					add(title , details , due_date , priority) ;
					cout << "         *********************  " << endl ;
				}
                break;
            case 2:
				system("cls") ;
				system ( "color 09" );
				is_done();
                break;
			case 3:
				system("cls") ;
				system ( "color 03" );
				edit() ;
				break ;
            case 4:
				system("cls") ;
				system ( "color 04" );
				Delete();
                break;
			case 5:
				system("cls") ;
				system ( "color 05" );
				display() ;
				break ;
			case 6:
				system("cls") ;
				system ( "color 0D" );
				display_done() ;
				break ;
			case 7:
				system("cls") ;
				system ( "color 0C" );
				display_overdue() ;
				break ;
			case 8:
				system("cls") ;
				system ( "color 08" );
				done_today() ;
				break ;
			case 9:
				system("cls") ;
				system ( "color 09" );
				search() ;
				break ;
            case 10:
				system("cls") ;
				system ( "color 0A" );
                cout << "Have a nice day!" << endl << endl ;
                working = false;
                break;
            default:
                cout << "Input was not recognized. Try again or "
                     << "\nenter 10 to exit." << endl;
                     bool working = true;
					
 
 
        }
    } while (working == true);
	//takedata.close() ; 
	//showdata.close() ;
	save();
 
}
void load() { 
	ifstream f ;
	vec.clear(); 
	f.open("tasks_file.txt");
	string line ; 

	while(getline(f,line)  && line.size() > 0 ) { 
		task t ; 
		t.title = line;
		getline(f,line); 
		t.details = line; 
		getline(f,line) ; 
		int day = stoi(line); 
		t.due_date.day = day; 
		getline(f,line) ; 
		int month = stoi(line); 
		t.due_date.month = month; 
		getline(f,line) ; 
		int year = stoi(line); 
		t.due_date.year = year;
		getline(f,line) ; 
		int par = stoi(line); 
		t.priority = par;
		getline(f,line) ;
		int done1 = stoi(line); 
		t.done = done1;
		vec.push_back(t);
	}
}
void save() { 
	ofstream f ; 
	f.open("tasks_file.txt");
	for(unsigned int w = 0 ;w < vec.size() ; w++ ) { 
		f << vec[w].title << endl << vec[w].details << endl; 
		f << vec[w].due_date.day << endl << vec[w].due_date.month << endl << vec[w].due_date.year << endl ; 
		f << vec[w].priority << endl;
		f << vec[w].done << endl;

	}
}

void add(string t2, string d2 , date due2 , int p2 )
{
	task p  ;
	p.title=t2 ;
	p.details=d2 ;
	p.due_date=due2 ;
	p.priority=p2 ;
	vec.push_back(p); 
	
	
}
void display ()
{

	for(unsigned int w = 0 ;w <  (vec.size()) ; w++) 
	{ 
		cout << "   " << vec[w].title<< endl; 
		cout << "   " << vec[w].details << endl;
		cout << "   " << vec[w].due_date.day<<" / "<< vec[w].due_date.month<<" / "<< vec[w].due_date.year << endl ;
		cout << "   " << vec[w].priority << endl; 
		
	
	}

}
void Delete()
{
	int coun=0 ,del_task ;
	cout <<"How many tasks do you want to delete ??" ;
	cin>> coun ;
	for(int r=0 ; r<coun ; r++)
	{
		cout << "enter the number of task you want to delete :" ;
		cin >> del_task ;
		for(unsigned int i=0 ; i< ( vec.size()); i++)
		{
			if((i+1)==del_task)
				vec.erase(vec.begin() + i) ;
		
				
		}
	}
}
int menu() {
 
    int choice;
    cout << "\t The Menu\n" << endl;
    cout << "[1] - Add new task." << endl;
    cout << "[2] - Mark specific task as done." << endl;
    cout << "[3] - Edit specific task." << endl;
    cout << "[4] - Delete specific task." << endl;
    cout << "[5] - display the all tasks." << endl;
	cout << "[6] - display the all done tasks." << endl;
	cout << "[7] - display the all overdue tasks." << endl;
	cout << "[8] - display tasks which need to be done today." << endl;
    cout << "[9] - search for specific task." << endl;
    cout << "[10] - Exit the program." << endl;
	
    cin >> choice;
    cout << endl;
	
        return choice;
}

void is_done() 
{
	int done_task ;
	cout <<"Enter the number of the task which you have already done : " ;
	cin >> done_task ;
	for(unsigned int i =0 ; i <(vec.size()) ;i++)
	{
		if((i+1)==done_task)
			//vec[i].notdone=false ;
				vec[i].done='1';
	}
}

void display_done()
{
	for(unsigned int w = 0 ;w <  (vec.size()) ; w++) 
	{ 
		if(vec[w].done=='1')
		{
		    cout << vec[w].title<< endl; 
		    cout << vec[w].details << endl;
		    cout << vec[w].due_date.day<<" / "<< vec[w].due_date.month<<" / "<< vec[w].due_date.year << endl ;
		    cout << vec[w].priority << endl;
		}
		
	}
}
void display_overdue() 
{
	date today ;
	bool over=false ;
	cout << "please enter today's date : " ;
	cin >> today.day >> today.month >> today.year ;
		for(unsigned int w = 0 ;w <  (vec.size()) ; w++) 
	{ 
		if(today.year<vec[w].due_date.year)
			over=false ;
		else if(today.year>vec[w].due_date.year)
			over=true ;
		else
		{
			if(today.month<vec[w].due_date.month)
			    over=false ;
			else if(today.month>vec[w].due_date.month)
			    over=true ;
			else 
			{
				if(today.day<vec[w].due_date.day)
			        over=false ;
				else if(today.day>vec[w].due_date.day)
			        over=true ;
				else
					over=false ;
			}
		}
		if(over)//if(over==true)
		{
		cout << vec[w].title<< endl; 
		cout << vec[w].details << endl;
		cout << vec[w].due_date.day<<" / "<< vec[w].due_date.month<<" / "<< vec[w].due_date.year << endl ;
		cout << vec[w].priority << endl; 
		}
	
	}
}
void done_today() 
{
	date today ;
	bool must_today=false ;
	cout << "please enter today's date : " ;
	cin >> today.day >> today.month >> today.year ;
	for(unsigned int w = 0 ;w <  (vec.size()) ; w++) 
	{ 
		if(today.day==vec[w].due_date.day &&today.month==vec[w].due_date.month &&today.year==vec[w].due_date.year )
		{
		    cout << vec[w].title<< endl; 
		    cout << vec[w].details << endl;
		    cout << vec[w].due_date.day<<" / "<< vec[w].due_date.month<<" / "<< vec[w].due_date.year << endl ;
		    cout << vec[w].priority << endl;
			must_today=true ;
		}
		
	}
	if(!must_today)
		cout <<"there is no tasks have to be done today ^_^" << endl ;
}
void search()
{
	int search_by , number ;
	string title ;
	date date ;
	cout <<"what do you want to search by ?? " << endl ;
    cout << "[1] - search by title." << endl;
    cout << "[2] - search by number." << endl;
    cout << "[3] - search by timing." << endl;
	cin >> search_by ;
	switch (search_by)
	{
	case 1:
		cout <<"Enter the title of the task you search for : " ;
		cin >> title ;
		for(unsigned int w = 0 ;w <  (vec.size()) ; w++) 
	    { 
			if(vec[w].title==title)
			{
		    cout << vec[w].title<< endl; 
		    cout << vec[w].details << endl;
		    cout << vec[w].due_date.day<<" / "<< vec[w].due_date.month<<" / "<< vec[w].due_date.year << endl ;
		    cout << vec[w].priority << endl; 
			}
	    }
		break ;
	case 2:
		cout <<"Enter the number of the task you search for : " ;
		cin >> number ;
		for(unsigned int w = 0 ;w <  (vec.size()) ; w++) 
	    { 
			if((w+1)==number)
			{
		    cout << vec[w].title<< endl; 
		    cout << vec[w].details << endl;
		    cout << vec[w].due_date.day<<"/"<< vec[w].due_date.month<<"/"<< vec[w].due_date.year << endl ;
		    cout << vec[w].priority << endl; 
			}
	    }
		break ;
	case 3:
		cout <<"Enter the timing of the task you search for : " ;
		cin >> date.day >> date.month >> date.year ;
		for(unsigned int w = 0 ;w <  (vec.size()) ; w++) 
	    { 
			if(vec[w].due_date.day==date.day &&vec[w].due_date.month==date.month &&vec[w].due_date.year==date.year )
			{
		    cout << vec[w].title<< endl; 
		    cout << vec[w].details << endl;
		    cout << vec[w].due_date.day<<"/"<< vec[w].due_date.month<<"/"<< vec[w].due_date.year << endl ;
		    cout << vec[w].priority << endl; 
			}
	    }
		break ;
	default:
	    cout << "Input was not recognized. ";
		break;
	}
}
void edit() 
{
	int editing_one , editing ;
	cout << "Enter the number of the task you want to edit in :" ; 
	cin >> editing_one ;
	for(unsigned int w = 0 ;w <  (vec.size()) ; w++) 
	{
		if(w==(editing_one-1))
		{
	        cout << "what do you want to edit in the task??" << endl  ;
            cout << "[1] - to edit the title." << endl;
            cout << "[2] - to edit the details." << endl;
            cout << "[3] - to edit the due date." << endl;
            cout << "[4] - to edit the priority." << endl;
	        cin >> editing ;
	        switch (editing)
	        {
	        case 1:
				cout << "Enter your new title :" ;
				cin >> vec[w].title ;
				break ;
			case 2:
				cout << "Enter your new details :" ;
				cin >> vec[w].details ;
				break ;
			case 3:
				cout << "Enter your new due date :" ;
				cin >> vec[w].due_date.day >> vec[w].due_date.month >> vec[w].due_date.year ;
				break ;
			case 4:
				cout << "Enter your new priority :" ;
				cin >> vec[w].priority ;
				break ;
	        default:
		        cout << "Input was not recognized. ";
		        break;
	        }
        }
	}
}

