#ifndef _RB_ANALYSER_H
#define _RB_ANALYSER_H
#include"rbt.h"
template<typename T>
class rb_analyser{
	rb_tree<T> &tree;
	void print_aux(typename rb_tree<T>::node* n,string prefix);
	bool check_depth(typename rb_tree<T>::node* n,int &max_depth,int depth) const; //max_depth==-1 means depth is not yet determined
public:
	rb_analyser(rb_tree<T>& t):tree(t){}
	void print(){print_aux(tree.root,"");cout<<endl;}
	bool is_valid() const;
};

template<typename T>
bool rb_analyser<T>::check_depth(typename rb_tree<T>::node* n,int &max_depth,int depth) const{
	if(!n->is_red)depth++;
	else if(n->parent->is_red)return false;
//	cout<<(n->data)<<" "<<depth<<endl;
	if(n->left==&(tree.sentinal)&&n->right==&(tree.sentinal)){ //leaf
		if(max_depth==-1){ //black height is not yet determined
			max_depth=depth;
			return true;
		}else{
			return max_depth==depth;
		}
	}else{
		bool ret=true;
		if(n->right!=&(tree.sentinal)){
			ret&=check_depth(n->right,max_depth,depth);
		}
		if(n->left!=&(tree.sentinal)){
			ret&=check_depth(n->left,max_depth,depth);
		}
		return ret;
	}
}
template<typename T>
bool rb_analyser<T>::is_valid()const {
	if(tree.root==nullptr)return true;
	if(tree.root->is_red)return false;
	int max_depth=-1;
	return check_depth(tree.root,max_depth,0);
}
template<typename T>
void rb_analyser<T>::print_aux(typename rb_tree<T>::node* n,string prefix){
	static const int rowspace=1,colspace=10;
	int len=to_string(n->data).size();
	for(int i=colspace;i>len;i--)cout<<'_';
	if(n->is_red)cout<<"\e[41m"<<(n->data)<<"\e[0m";
	else cout<<(n->data);
	string new_prefix(colspace,' ');
	prefix+=new_prefix;
	if(n->left!=&(tree.sentinal))prefix[prefix.size()-1]='|';
	if(n->right!=&(tree.sentinal)){
		print_aux(n->right,prefix);
	}
	if(n->left!=&(tree.sentinal)){
		for(int i=0;i<=rowspace;i++)cout<<endl<<prefix;
		prefix[prefix.size()-1]=' ';
		print_aux(n->left,prefix);
	}
}
#endif
