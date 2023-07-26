
//INTUTION-
/* Store parent of each node and backtrack untill k becomes 0 to get the kth ancestors
*/



unordered_map<int,int>parent; /* store parent of each node */

//function to update the parent of each node
void assign_parent(Node *root,int val){
    if(!root){
        return;
    }
    parent[root->data]=val;
    assign_parent(root->left,root->data);
    assign_parent(root->right,root->data);
}


int kthAncestor(Node *root, int k, int node)
{
    //handling corner cases
    if(k==node and k==1){
        return -1;
    }
    assign_parent(root,root->data);
    int x=node; // x will be the final answer 
    int c=0; 
    while(k--){ /*loop untill k becomes 0 to get the kth ancestors*/
       x=parent[node];  // each time updating x with parent node
       node=x;
       
       if(x==1){ /* this if is to avoid recurring for root node */
          c++;  
      }
    
    }
    if(c>1){
        return -1;
    }
    return x;
}
