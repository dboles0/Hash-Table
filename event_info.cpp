#include "hash_table.h"

//default constructor which initializes the structure to hold the txt file info
//and hash table 
grid::grid() :cnt(0) 
{
      //allocate the array to hold the information from the txt file 
      cal_array = new event_info[SIZE];

      //allocate hash table and initialize each
      //element and chain
      hash_table = new node * [HASH_SIZE];
      for(int i=0; i<HASH_SIZE; ++i)
      {
          hash_table[i] = NULL;
      }
      hash_table_size = HASH_SIZE;
}	

//default destructor which deallocates the txt array along with the hash table
//elements
grid::~grid()
{
    if(cal_array)
      delete [] cal_array; 
}

//secondary constructore to initialize all 
//the infile verables 
event_info::event_info()
{
    event_name = NULL;
    location = NULL;
    date = NULL;
    time = NULL;
    description = NULL;
    key_word = NULL;
    key_word_array = new char * [KEY_WORD_SIZE]; 
    for(int i=0; i<KEY_WORD_SIZE; ++i)
    key_word_array[i] = NULL; 
    key_word_num = 0;
     
}

//second destructor to delete all arrays 
//stored in within each element
event_info::~event_info()
{
   if(event_name) 
	delete [] event_name; 
   if(location) 
	delete [] location;       
   if(date) 
	delete [] date;       
   if(time) 
	delete [] time;   
   if(description)
	delete [] description;  
   if(key_word) 
	delete [] key_word;   
}

//check if there is a connection to the file, if connection
//is found deep copy the struct data memebers to cal_array
//then send the address to the hash table chain

int grid::load()
{  
    int DESCRIPTION = 300;
    char l_event_name[SIZE];
    char l_location[SIZE];
    char l_date[SIZE];
    char l_time[SIZE];
    char l_description[DESCRIPTION];
    char l_key_word[SIZE];
    char key_word[SIZE];
    char * key_word_ptr;

    ifstream in_file;                              //create object 
    in_file.open("Events.txt");                    //open txt file
    if (in_file)
    {
        //prime the pump
        in_file.get(l_event_name, SIZE, '|');
	in_file.ignore(SIZE, '|');
        cal_array[cnt].event_name = new char[strlen(l_event_name) + 1];
        strcpy(cal_array[cnt].event_name, l_event_name); 

	while (in_file && !in_file.eof() && cnt < SIZE) 
	{
            in_file.get(l_location, SIZE, '|');
	    in_file.ignore(SIZE, '|');
            cal_array[cnt].location = new char[strlen(l_location) + 1];
            strcpy(cal_array[cnt].location, l_location); 
	   
            in_file.get(l_date, SIZE, '|');
	    in_file.ignore(SIZE, '|');
            cal_array[cnt].date = new char[strlen(l_date) + 1];
            strcpy(cal_array[cnt].date, l_date); 
            
            in_file.get(l_time, SIZE, '|');
	    in_file.ignore(SIZE, '|');
            cal_array[cnt].time = new char[strlen(l_time) + 1];
            strcpy(cal_array[cnt].time, l_time); 

            in_file.get(l_description, DESCRIPTION, '|');
	    in_file.ignore(SIZE, '|');
            cal_array[cnt].description = new char[strlen(l_description) + 1];
            strcpy(cal_array[cnt].description, l_description); 
 
            //read in until we find the end of the line             
	    in_file.get(l_key_word, SIZE, '\n');
	    in_file.ignore(SIZE, '\n');
            
            //use strtok to split the read in information  
	    key_word_ptr = strtok(l_key_word, ",");
            
            //loop throught all of the words that are seperated by a "," untill
            //we reach the end of the variable and store them in seperate arrays
            int i = 0;
            while(key_word_ptr != NULL) 
            {
		cal_array[cnt].key_word_array[i] = new char[strlen(key_word_ptr) + 1];
		strcpy(cal_array[cnt].key_word_array[i], key_word_ptr);
                ++i;
		key_word_ptr = strtok(NULL, ",");
            }
            //save the number of key words that we saved
            cal_array[cnt].key_word_num = i;  
                
            //use the insert() from hash_table.cpp to send array holding the 
            //elements so it the insert function can add the address of the 
            //array to the appropriate hash index. 
            insert(cal_array[cnt]);

	    ++cnt; //increase index
	    //Prime the pump
	    in_file.get(l_event_name, SIZE, '|');
	    in_file.ignore(SIZE, '|');
            if(strlen(l_event_name) > 0) 
            {            
            cal_array[cnt].event_name = new char[strlen(l_event_name) + 1];
            strcpy(cal_array[cnt].event_name, l_event_name); 
            }

	}                                         //end while
        //close the connectoin to the out file
	in_file.close();
	in_file.clear();
   }                                              //end if
}                                                 //end load
/*
//loop display the content for testing
int grid::display()
{
    for(int i=0; i < cnt; ++i)
        {
	cout << cal_array[i].event_name << endl; 
	cout << cal_array[i].location << endl; 
	cout << cal_array[i].date << endl; 
	cout << cal_array[i].time << endl; 
	cout << cal_array[i].description << endl; 
	cout << cal_array[i].key_word << "\n" << endl; 
        }
}
*/
