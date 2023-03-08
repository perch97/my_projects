#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include<string>
//show_menu function

void show_menu();

//add_note function

void add_note(const std::string& new_note);

//see_all_notes

void see_all_notes();

//find_one_note
std::string* find_one_note(const std::string& note_to_find, int &n_count);

//return the pointer to array of all notes
std::string* all_notes(int& n_count);

//remove one note with index choice

void remove_one_note(std::string* all_notes_arr,int count,int choice);

//remove all notes

void remove_all_notes();
#endif
