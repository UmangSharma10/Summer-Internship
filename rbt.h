#ifndef _RB_TREE_H
#define _RB_TREE_H
#include<iostream>
#include<algorithm>
#include<vector>
template<typename T> class rb_analyser;
using namespace std;

template<typename T>
class rb_tree{
public:
	struct node{
		bool is_red;
		node*left,*right,*parent;
		T data;
	};
	node sentinal{.is_red=false};
	node *root{};
	friend class rb_analyser<T>;
	void insert(const T new_data);
	bool remove(const T &key);
	bool find(const T& key)const;
	void transplant(node*u,node*v);
private:
	void insert_fixup(node* n);
	void remove_fixup(node* n);
	void rotate_left(node* n);
	void rotate_right(node* n);
	node* find_node(const T& key)const;
};

template<typename T>
bool rb_tree<T>::remove(const T & key){
	node*x,*y,* z=find_node(key);
	if(!z)return false;
	y=z;
	bool y_orignal_color=y->is_red;
	if(z->left== &(sentinal)){
		x=z->right;
		transplant(z,z->right);
	}else if(z->right== &(sentinal)){
		x=z->left;
		transplant(z,z->left);
	}else{
		y=z->right;
		//finding minimum in y's subtree
		while(y->left != &(sentinal))y=y->left;
		y_orignal_color=y->is_red;
		x=y->right;
		if(y->parent==z){
			x->parent=y;
		}else{
			transplant(y,y->right);
			y->right=z->right;
			y->right->parent=y;
		}
		transplant(z,y);
		y->left=z->left;
		y->left->parent=y;
		y->is_red=z->is_red;
	}
	if(!y_orignal_color){
		remove_fixup(x);
	}
	return true;
}
template<typename T>
void rb_tree<T>::transplant(node*u,node*v){
	if(u->parent==&sentinal){
		root=v;
	}else if(u==u->parent->left){
		u->parent->left=v;
	}else{
		u->parent->right=v;
	}
	v->parent=u->parent;
}
template<typename T>
bool  rb_tree<T>::find(const T & key)const{
	return static_cast<bool>(find_node(key));
}
template<typename T>
typename rb_tree<T>::node* rb_tree<T>::find_node(const T & key)const{
	if(root){
		node *y,*x=root;
		while(x!=&sentinal && x->data != key){
			y=x;
			if(x->data > key){
				x=x->left;
			}else{
				x=x->right;
			}
		}
		if(x==&sentinal)return nullptr;
		return x;
	}else{
		return nullptr;
	}
}
template<typename T>
void rb_tree<T>::insert(const T new_data){
	//cout<<"inserting: "<<new_data<<endl;
	node* new_node=new node;
	new_node->data=new_data;
	new_node->left=new_node->right=&sentinal;
	new_node->is_red=true;
	if(root){
		node *y,*x=root;
		while(x!=&sentinal){
			y=x;
			//cout<<(y->data)<<endl;
			if(x->data > new_data){
				x=x->left;
			}else{
				x=x->right;
			}
		}
		if(y->data > new_data){
			y->left=new_node;
		}else{
			y->right=new_node;
		}
		new_node->parent=y;
	}else{
		root=new_node;
		new_node->parent=&sentinal;
	}
	insert_fixup(new_node);
}

template<typename T>
void rb_tree<T>::rotate_left(node* x){
	//cout<<"rotate_left\n";
	node*y=x->right;
	x->right=y->left;
	if(y->left != &sentinal)y->left->parent=x;
	y->parent=x->parent;
	if(x->parent == &sentinal){
		root=y;
	}else if(x==x->parent->left){
		x->parent->left=y;
	}else{
		x->parent->right=y;
	}
	y->left=x;
	x->parent=y;

}
template<typename T>
void rb_tree<T>::rotate_right(node* x){
	//cout<<"rotate_right\n";
	node*y=x->left;
	x->left=y->right;
	if(y->right != &sentinal)y->right->parent=x;
	y->parent=x->parent;
	if(x->parent == &sentinal){
		root=y;
	}else if(x==x->parent->right){
		x->parent->right=y;
	}else{
		x->parent->left=y;
	}
	y->right=x;
	x->parent=y;

}
template<typename T>
void rb_tree<T>::remove_fixup(node* x){
	node* w;
	while(x!=root && !x->is_red){
		if(x==x->parent->left){
			w=x->parent->right;		
			if(w->is_red){
				w->is_red=false;
				x->parent->is_red=true;
				rotate_left(x->parent);
				w=x->parent->right;
			}
			if(!w->left->is_red && !w->right->is_red){
				w->is_red=true;
				x=x->parent;
			}else{
				if(!w->right->is_red){
					w->left->is_red=false;
					w->is_red=true;
					rotate_right(w);
					w=x->parent->right;
				}
				w->is_red=x->parent->is_red;
				x->parent->is_red=false;
				w->right->is_red=false;
				rotate_left(x->parent);
				x=root;
			}
		}else{
			w=x->parent->left;		
			if(w->is_red){
				w->is_red=false;
				x->parent->is_red=true;
				rotate_right(x->parent);
				w=x->parent->left;
			}
			if(!w->right->is_red && !w->left->is_red){
				w->is_red=true;
				x=x->parent;
			}else{
				if(!w->left->is_red){
					w->right->is_red=false;
					w->is_red=true;
					rotate_left(w);
					w=x->parent->left;
				}
				w->is_red=x->parent->is_red;
				x->parent->is_red=false;
				w->left->is_red=false;
				rotate_right(x->parent);
				x=root;
			}
		}
	}
	x->is_red=false;
}
template<typename T>
void rb_tree<T>::insert_fixup(node* n){
	//cout<<"insert_fixup\n";
	while(n->parent->is_red){
		//cout<<"current: "<<(n->data)<<endl;
		if(n->parent->parent->left==n->parent){ //parent is the left child
			//cout<<"left child\n";
			if(n->parent->parent->right->is_red){
				//cout<<"ripple up\n";
				n->parent->parent->right->is_red=false;
				n->parent->is_red=false;
				n->parent->parent->is_red=true;
				n=n->parent->parent;
			}else{
				if(n->parent->right==n){
					n=n->parent;
					rotate_left(n);
				}
				n->parent->is_red=false;
				n->parent->parent->is_red=true;
				rotate_right(n->parent->parent);
			}
		}else{
			//cout<<"right child\n";
			if(n->parent->parent->left->is_red){
				//cout<<"ripple up\n";
				n->parent->parent->left->is_red=false;
				n->parent->is_red=false;
				n->parent->parent->is_red=true;
				n=n->parent->parent;
			}else{
				if(n->parent->left==n){
					n=n->parent;
					rotate_right(n);
				}
				n->parent->is_red=false;
				n->parent->parent->is_red=true;
				rotate_left(n->parent->parent);
			}
		}
	}
	root->is_red=false;
}
#endif
