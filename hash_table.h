//Donald C Boles
//ID: 903512976
//CS_163 Spring 2017
//Program Assignment #3 

//hash_table.h file

#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>

#ifndef hash_table_h
#define hash_table_h

using namespace std;

const int SIZE = 100;
const int KEY_WORD_SIZE = 15;
const int HASH_SIZE = 89;

struct event_info
{
    char * event_name;         //name given to the event
    char * location;           //place where the event will take place
    char * date;               //starting date of the event as MM/DD/YYYY 
    char * time;               //time when the event starts
    char * description;        //description of the what to expect at event
    char * key_word;           //key words to pull the event
    char ** key_word_array;           //key words to pull the event
    int key_word_num;
    event_info();              //secondary constructor for each array element 
    ~event_info();             //secondary desturcor to de allocate each 
                               //array element
};

struct node
{
    event_info * data;
    node * next;
};

class grid
{
public:

    grid();                  //default constructor 
//    ~grid();
    ~grid();                 //default destructor
    int load();                                   //load the txt file with cal info
    //int display();                                //dispaly loaded cal info
    int insert(event_info & to_add);
    int retrieve(char * key_word_to_find, event_info match_array[], int & num_of_matches);
    int display(event_info match_array[], int num_of_matches);
    int display_all();
    int hash_key(char * key_word);   

private:
    node ** hash_table;
    int hash_table_size;
    event_info * cal_array;    //pointer to the cal_array caring the event info
    int cnt;
    int kw_array_size;
};

bool again();

#endif
