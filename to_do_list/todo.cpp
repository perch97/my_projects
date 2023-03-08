#include <iostream>
#include "to_do_list/Functions.h"
#include <cstdlib>
#include <string>

enum CHOICE{
    ADD_NOTE = 1,
    SEE_ALL_NOTES,
    FIND_ONE_NOTE,
    REMOVE_ONE_NOTE,
    REMOVE_ALL_NOTES
};

int main(){
     
    while(true){
        show_menu();
        std::cout<<"Choose option: ";
        int choice = 0;
        std::cin>>choice;

        if(choice == ADD_NOTE){
            std::cout<<"add_note()"<<std::endl;
            std::string new_note;
            std::getline(std::cin,new_note);
            std::cout<<"Note to add: ";
            std::getline(std::cin,new_note);
            add_note(new_note);
            std::cout<<"Press the enter to return"<<std::endl;
            std::cin.ignore();
        }
        else if(choice == SEE_ALL_NOTES){
            see_all_notes();
            std::cout<<"Press the enter to return"<<std::endl;
            std::cin.ignore();
        }
        else if(choice == FIND_ONE_NOTE){
            std::cout<<"see_all_notes()"<<std::endl;
            std::string note_to_find;
            std::getline(std::cin,note_to_find);
            std::cout<<"Note to find:";
            std::getline(std::cin,note_to_find);

            int n_found = 0;
            std::string* found_notes = find_one_note(note_to_find, n_found);

            if(found_notes){
                std::cout<<"Found notes: ";
                for(int i=0; i<n_found;i++)
                std::cout<<found_notes[i]<<std::endl;
                delete[] found_notes;
            }
            else{
                std::cout<<"no such note!"<<std::endl;
            }
            
        }

        else if(choice ==  REMOVE_ONE_NOTE){
            int count = 0;
            std::string* all_notes_arr = all_notes(count);
            std::cout<<"All_notes: "<<std::endl;
            for(int i = 0; i<count;i++)
                std::cout<<'['<<i+1<<"]"<<all_notes_arr[i]<<std::endl;
            
            std::cout<<"Number of note to remove: ";
            int choice =0;
            std::cin>>choice;
            // remove_one_note(choice);
            remove_one_note(all_notes_arr,count,choice);
            std::cout<<"Your note removed!"<<std::endl;
            delete[] all_notes_arr;
        }
        else if(choice == REMOVE_ALL_NOTES){
            remove_all_notes();
            std::cout<<"All notes removed!"<<std::endl;
        }
        else
            break;
        
        }
}
