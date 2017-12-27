//Donald C Boles
//ID - 903512975
//CS 163 - Data Structures (Spring 2017)
//Program Assignment #3

//this program will take an outfile of calender  
//infomraiton and will provide the user more flexability
//to access infomraiton based on key word a key word search
    
#include "hash_table.h"

int main()
{
    char entry[SIZE];
    event_info match_array[SIZE];
    int num_of_matches = 0;
    grid a_grid;
 
    a_grid.load();

    //catch a key word form the user to use to use to display relevent infomrlaiton
    //back to the user
    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
         << endl;
    cout << "\t\t\t\t\t\t| Welcome to cal info, enter a key word to view related informaiton   |\n\t\t\t\t\t\t| " 
         << "or enter \"D\" to display all of the events                           |" << endl;
    cout << "\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n\n\n\n\n\n\n"
         << endl;
    cout << "Key word search: " << endl; 
    cin.get(entry, 100, '\n');
    cin.ignore(100, '\n');

    //display contents of hash table if D is entered
    if(*entry == 'D')
    a_grid.display_all();
 
    else
    {
        //find match based entry
	if(!a_grid.retrieve(entry, match_array, num_of_matches))
	{
	   cerr << "no match was found" << endl; 
	}
      
        //dispaly the array contents found from match
        if(!a_grid.display(match_array, num_of_matches))
	{
	   cerr << "list not found" << endl;
	}
    }
 
    return 0;    
}
