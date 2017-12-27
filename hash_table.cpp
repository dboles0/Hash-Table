#include"hash_table.h"
/*
grid::~grid()
{
    if(head)
    delete head;
    ~hash_table(head->next); 
}
*/
//Insert a new value into the head of the chain, using 
//the hash_function
int grid::insert(event_info & to_add)
{
        //for loop to house three different entries based on the first three
        //keys passed into the function
        for(int i=0; i<to_add.key_word_num; ++i) 
        {
            //check if the array element is null
            if(to_add.key_word_array[i])
            {
                
                //create key form the key word entered
                int key = hash_key(to_add.key_word_array[i]);
         
		//initialize a head pointer based on the indexed hash table entry
		node * head = hash_table[key]; 

		//check to see if the key identified list is empty, if so add the address
		//of the data that you are trying to add. 
		if(!head) 
		{
		    head = new node;
		    head->data = & to_add;
		}                        //end if
    
		//if one entry already exists than create a new node and place the 
		//address if the data of the node and set node to the head of the 
		//list
		else
		{
		    node * temp = new node;
		    temp->data =  & to_add;
		    temp->next = head;
		    head = temp;
		}                         //end else
       
                //set the the element address back into the hash table
		hash_table[key] = head;
	    }                             //end if
        }                                 //end for loop
        return 1;
}                                         //end function
 
//using a key word form main, this will match up with LLL and return
//if match found
int grid::retrieve(char * key_word_to_find, event_info match_array[], int & num_of_matches)
{

    //use the hash functioin to generate the same index
    //as the word we are looking for
    int key = hash_key(key_word_to_find);

    //initialize verable to return if match is found
    int found_name = 0;
    
    //create a pointer starting at the key created index 
    node * current = hash_table[key];
    
    //look throught the list until we find a match setting
    //found name to true
    while(current)
    {
        for(int i=0; i<cal_array->key_word_num; ++i)
        {
	    if(current->data->key_word_array[i] == key_word_to_find)
	    {
		found_name = 1;
		match_array[num_of_matches] = *(current->data);
		++num_of_matches;
		current = current->next;
	    }
        }
        current = current->next;
    }

    return found_name;
}

//display the event_names of all the retrieved matches fount from the 
//retrieve function
int grid::display(event_info match_array[], int num_of_matches)
{
  for(int i=0; i<num_of_matches; ++i)
  {
  cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~\n"; 
  cout << match_array[i].event_name << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~\n"; 
  }
  return 1;
}

//display all the elements found in the hash table
int grid::display_all()
{
    for(int i =0; i<hash_table_size; ++i) 
    { 
        node * current = hash_table[i]; 
        while(current) 
        {
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~\n"; 
            cout << current->data->event_name << endl;
            cout << current->data->location << endl;
            cout << current->data->date << endl;
            cout << current->data->time << endl;
            cout << current->data->description << endl;
            for(int i=0; i<current->data->key_word_num; ++i)
            {
            cout << "key word " << i+1 << ": " << current->data->key_word_array[i] << endl;
            }
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~"; 
            cout << "\n";
            current = current->next;
        }
    } 
    return 1;
}

//generates a key to be used as an index for a hash table entry
int grid::hash_key(char * key_word)
{
    int size = strlen(key_word);
    int sum = 0;
    for(int i=0; i<size; ++i)
    {
        sum += key_word[i];
    }
    return sum%hash_table_size;
}

