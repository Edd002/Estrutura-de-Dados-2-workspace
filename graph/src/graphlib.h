/*
 * graphlib.h
 *
 *  Created on: 19 de nov de 2018
 *      Author: Eduardo Augusto Lima Pereira
 */

#ifndef GRAPHLIB_H_
#define GRAPHLIB_H_

void print_err(char*);
void scan_str(char**);
void replacefirstoccurrence_str(char*, char*, char*);
char* remove_spaces(char*);
char* replaceall_words(char*, char*, char*);
char* read_str(char*);
char read_char(char*);
int read_int(char*);
int count_words(char*);

void init();
void show_strgraph(char*);
void convertto_incmatr(char*, int**, int);
void print_incmatr(int**, int, int);
void convertto_adjmatr(char*, int**, int);
void print_adjmatr(int**, int, int);
void compute_degree(int**, int);
void print_graphsetrepresentation(int**, int);

#endif /* GRAPHLIB_H_ */
