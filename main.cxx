#include <iostream>
#include <cstdlib>

using namespace std;

namespace{

struct node_t{
  int value;
  node_t * left;
  node_t * right;
}Node;

} // namespace
 
bool isBalanced(node_t *root, int curDepth, int &anyDepth){

  ++curDepth;

  if(!root){
    // hasnt been set yet
    if(anyDepth == -1){ 
      anyDepth = curDepth;
    }
    if( curDepth > anyDepth+1 || curDepth < anyDepth-1 ){
      return false;
    }
    return true;
  }

  if( !isBalanced(root->left, curDepth, anyDepth) ){
    return false;
  }
  

  if( !isBalanced(root->right, curDepth, anyDepth) ){
    return false;
  } 

  

  return true;
}

int main(){

  node_t root;
  root.value = 0;
  node_t a, b, c, d, e, f, g, h, i;
  root.left = &a;
  root.right = &b;
  a.left = &c;
  a.right = &d;
  b.left = &e;
  b.right = &f;
  c.left = &g;
  c.right = &h;
  d.left = &i;
  d.right = NULL;
  e.left = NULL;
  e.right = NULL;
  f.left = NULL;
  f.right = NULL;
  g.left = NULL;
  g.right = NULL;
  h.left = NULL;
  h.right = NULL;
  i.left = NULL;
  i.right = NULL;

  node_t bad_node;
  bad_node.left = NULL;
  bad_node.right = NULL;

  // to have a good height, comment out the next line
  g.left = &bad_node;

  int anyDepth = -1;

  if( isBalanced(&root, 0, anyDepth) ){
    cout <<"this tree is balanced with +/- " << anyDepth << " height."  << endl;
  }else{
    cout <<"this tree is not balanced with +/- " << anyDepth << " height."  << endl;
  }
  
  return EXIT_SUCCESS;
}

