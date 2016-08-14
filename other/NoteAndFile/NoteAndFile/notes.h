#pragma once
#ifndef NOTES
#define NOTES

#include"list.h"

void print_note_list(list *p);
void load_one_note(list_iterator it); //Hint: it is the reverse action of the function
void write_one_note(list_iterator it);
void append_note_to_list(list_iterator it,char *str);
list_iterator find_list_tail();
list_iterator find_list_head();
void free_note_list();
void print_note_array();
list_iterator find_note_by_id(int id);
void delete_node(list_iterator it);
void print_notes_with_substring();

#endif // !NOTES
