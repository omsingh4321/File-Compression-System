#include <bits/stdc++.h>
using namespace std;
class Hufftree{
public:
int val; //For frequncy 
char letter;
Hufftree *left;
Hufftree *right;
Hufftree(int val, char c)
{
    this->val=val;
    this->letter=c;
    this->left=NULL;
    this->right=NULL;
}
};
vector<pair<int,char>> frequency(string s)
{
  map<char,int>M; //for finding the frequency of all characcters in string 
  for(int i=0;i<s.length();i++)
  {
    M[s[i]]++;
  }
  
  vector<pair<int,char>>V;
  for(auto map:M)
  {
    V.push_back({map.second,map.first});
  }
  sort(V.begin(),V.end());
return V;
}
void Display(vector<pair<int,char>>freq)
{
 for(int i=0;i<freq.size();i++)
   {
    cout<<freq[i].second<<" "<<freq[i].first<<endl;
   }
}
class compare
{
    public:
     bool operator() (Hufftree *a,Hufftree *b)
     {
        if(a->val>b->val) return true;
        else return false;
     }
     
};
void print(priority_queue<Hufftree*,vector<Hufftree*>,compare>Q)
{
    cout<<"Print"<<endl;
  while(!Q.empty())
  {
     cout<<Q.top()->letter<<" "<<Q.top()->val<<endl;
      Q.pop();
  }
}
Hufftree* makeTree(vector<pair<int,char>>freq)
{
  priority_queue<Hufftree*,vector<Hufftree*>,compare>Q;
  for(int i=0;i<freq.size();i++)
  {
    Q.push(new Hufftree(freq[i].first,freq[i].second));
  }
  //print(Q);
  while(Q.size()>1)
  {
      Hufftree *left=Q.top();
      Q.pop();
      Hufftree *right=Q.top();
      Q.pop();
      Hufftree *mix=new Hufftree(left->val+right->val,'#');
      mix->left=left;
      mix->right=right;
    Q.push(mix);
  }
 return Q.top();
}
void tellme(map<char,string>&M,string str,Hufftree *root)
{
   if(!root) return;
   if(root->letter!='#')
   {
     M[root->letter]=str;
     return;
   }
   else
   {
    tellme(M,str+"0",root->left);
    tellme(M,str+"1",root->right);
   }

}
void preorder(Hufftree *root)
{
    if(!root) return;
    cout<<root->val<<" "<<root->letter<<endl;
    preorder(root->left);
    preorder(root->right);
}
void decode(Hufftree *root,string res,int &index_res,string &ans,Hufftree *head)
{
   if(!root) return;
   if(index_res==res.length()) {
    ans+=root->letter;
    return;
   }
   if(root->letter!='#')
   {
    ans=ans+root->letter;
    return;
   }
   int num=res[index_res]-48;
   if(num==0)
   {
    index_res++;
    decode(root->left,res,index_res,ans,head);
       
   }
   else{
     index_res++;
    decode(root->right,res,index_res,ans,head);

   }
   while(index_res<res.length() && root==head)
   {
    decode(root,res,index_res,ans,head);
   }



}

int main()
{
    string input;
    cout<<"Enter the input string";
    cin>>input;
   vector<pair<int,char>>freq;
   freq=frequency(input);
   Hufftree *tree=makeTree(freq);
   map<char,string>M;
    tellme(M,"",tree);
    string res="";
for(int i=0;i<input.size();i++)
{
  res+=M[input[i]];
}
for(auto P:M)
{
    cout<<P.first<<" "<<P.second<<endl;
}
cout<<"**************************"<<endl;
cout<<input<<endl;
cout<<res<<endl;//this is encoded string
//Now for decoding
string decoded_input="";
int index=0;
decode(tree,res,index,decoded_input,tree);
cout<<decoded_input<<endl;

return 0;
}
