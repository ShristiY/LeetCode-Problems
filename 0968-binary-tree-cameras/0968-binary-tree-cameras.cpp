/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
       int dfs(TreeNode * root, int& sum){
           //return 1 because we don't need any camera agar 0 return krenge toh wo 33 line me jaake sum++ kr dega which we don't want
        if(root == NULL) return 1; //base case
        int l=dfs(root->left,sum);
           int r=dfs(root->right,sum);
        if(l==0||r==0){// if at least 1 child is not monitored, we need to place a camera at current node 
            sum++;
            return 2;
        }else if(l==2||r==2){// if at least 1 child has camera, the current node is monitored. Thus, we don't need to place a camera here 
            return 1;
        }else{// if both children are monitored but have no camera, we don't need to place a camera here. We place the camera at its parent node at the higher level. 
            return 0;
        }
           //we'll never reach here
        return -1;// this return statement won't be triggered
    }

    int minCameraCover(TreeNode* root) {
        int sum=0;
        if(dfs(root,sum)==0) // just checking if the top most root is monitored. if it return 0 that means it sis not and it needs a camera , thereofre we'll do sum++;
            sum++; 
        return sum;
    }
};