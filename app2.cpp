#include <bits/stdc++.h>
using namespace std;
  using item=pair<int, string>;
    unordered_map<string, set<item>> Rated;
    unordered_map<string, item> mp;
int FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
    {
     int size= foods.size();
        for(int i =0;i<size;i++){
             string food=foods[i], cuisine=cuisines[i];
            int rating=ratings[i];
            mp[food]={-rating, cuisine};//take minus
            Rated[cuisine].insert({-rating, food});
          
             }
        return 1;
    }
    
    void changeRating(string food, int newRating) {
       string cuisine = mp[food].second;
       int oldRating = mp[food].first;
       Rated[cuisine].erase({oldRating,food});
       Rated[cuisine].insert({-newRating,food});
       mp[food]={-newRating,cuisine};
    }
    
    string highestRated(string cuisine) {
        return Rated[cuisine].begin()->second;
    }

       vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
       
        int size = img.size();
        int size2= img[0].size();
        vector<vector<int>> result(size,vector<int>(size2,0)) ;
   
    for(int i= 0;i<size;i++){
        for(int j= 0;i<size2;j++){
            int count=0;
            int acc=0;
            int minUp=i-1;
            int minLeft=j-1;
            for(int k=minUp;k<=minUp+2;k++){
            for(int l=minLeft;l<=minLeft+2;l++){
                if(k>0 &&l>0 &&k<size &&l<size2){
                    count++;
                    acc+=img[k][l];
                }
            }
            }
         
        result[i][j]=acc/count;
        }
    }
        
        
        
        
        return result;
    }
   

 int main (){
  cout<<"hello";
  return 0;
 }
     int compareVersion(string version1, string version2) {
        int v1,v2;
        for(int i=0 ;i<version1.length()-1;i++){
            if(version1[i]=='.'){
               v1=  stoi(version1.substr(0,i-1))  ;
                         break;
                
            }
         
        }
         for(int i=0 ;i<version2.length()-1;i++){
             if(version2[i]=='.'){
               v2=  stoi(version2.substr(0,i-1))   ;
                           break;
                
            }
        }
        
        if (v1 < v2) return -1;
        if (v1 > v2) return 1;
     return 0;
    }
      int lengthOfLIS(vector<int>& nums) {
         std::vector<int> tails(nums.size(), 0);
        int size = 0;

        for (int x : nums) {
            int i = 0, j = size;
            while (i != j) {
                int m = (i + j) / 2;
                if (tails[m] < x)
                    i = m + 1;
                else
                    j = m;
            }
            tails[i] = x;
            if (i == size) ++size;
        }
        return size;
    }
    class Solution {
public:
    int dp[50001];
    int size=0;
    int maxVal(vector<vector<int>>&jobs,vector<int>&start,int index){
        if(index ==size)return 0;
        if(dp[index]!=-1)return dp[index];
        
        int newIndedx= lower_bound(start.begin(),start.end(),jobs[index][1])-start.begin();
        
    int val = max(maxVal(jobs,start,index+1),jobs[index][2]+maxVal(jobs,start,newIndedx));
        return dp[index]=val;   
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector <int>> jobs;
        memset(dp,-1,sizeof(dp));
        this->size= profit.size();
        for(int i=0;i<size;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        for(int i=0;i<size;i++){
            startTime[i]=jobs[i][0];
        }
        
        return maxVal(jobs,startTime,0);
    }
};

#define il long long int
class Solution {
public:
 
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
         vector<unordered_map<il ,int>> acc(n);
          int result=0;
        for(int i =1;i<n;i++){
              for(int j =0;j<i;j++){
                  il diff=(il) nums[i]-nums[j];
                  acc[i][diff]+=1+ acc[j][diff];
                  result+= 1+ acc[j][diff];
            
              }
            
        }
        return result-(n*(n-1)/2);
    }
};


class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return 0;
        if(root->val<low)return rangeSumBST(root->right,low,high);
         if(root->val>high)return rangeSumBST(root->left,low,high);
        return root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    }
};
class Solution {
public:
     void rangeSumBST(TreeNode* root,vector<int>&x) {
         if(root==nullptr) return;
        if(root->left==nullptr &&root->right==nullptr){
            x.push_back(root->val);
               
        } 
      rangeSumBST(root->left,x);
     rangeSumBST(root->right,x);

       
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
          vector<int>ro1;
          vector<int>ro2;
     
       rangeSumBST(root1,ro1);
       rangeSumBST(root2,ro2);
        return ro1==ro2;
        
    }
};

//graph bfs breadth first search

const int N= 1e4;
bool vis[N];

class Solution {
  public:
  vector <int> bfs(int pos, vector<int> adj[]){
      vis[pos]=true;
      vector<int> result;
      queue<int> q;
      q.push(pos);
   
      while(!q.empty()){
         int fronter= q.front();
            result.push_back(fronter);
         q.pop();
         for(int i =0;i<adj[fronter].size();i++){
             int acc=adj[fronter][i];
             if(!vis[acc]){
                 vis[acc]=true;
                 q.push(acc);
             }
         }
          
          
      }
      return result;
  }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
  
        memset(vis,0,sizeof(vis));
              
      
        
        
        
        return  bfs(0,adj);
    }
};