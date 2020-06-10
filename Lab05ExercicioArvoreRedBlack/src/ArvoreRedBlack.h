/*
 * ArvoreRedBlack.h
 *
 *  Created on: 12 de nov de 2018
 *      Author: n226804875
 */

#ifndef ARVOREREDBLACK_H_
#define ARVOREREDBLACK_H_

typedef enum rbcolor {
	BLACK = 0,
	RED = 1
} t_rbcolor;

typedef unsigned int t_key;
typedef unsigned int t_value;

typedef struct s_rbnode {
	t_key key;
	t_value value;
	t_rbcolor color;
	struct s_rbnode *left;
	struct s_rbnode *right;
} t_rbnode;

t_rbnode *erase_tree(t_rbnode *node);
t_rbnode *remove_key(t_rbnode *node, t_key key);
unsigned int get_size(t_rbnode *node, t_key key);
t_value	get_key(t_rbnode *node, t_key key);
void insert(t_key key, t_value value);

#endif /* ARVOREREDBLACK_H_ */
