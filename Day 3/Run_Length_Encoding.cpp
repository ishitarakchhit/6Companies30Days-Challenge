//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */
void itos(string &temp, int count){
    while(count){
        int rem = count%10;
        temp += rem+'0';
        count/=10;
    }
    sort(temp.begin(), temp.end());
}
string encode(string src)
{     
  int i=0;
  int j=0;
  int count = 0;
  
  while(i<src.length() ){
      char org = src[i];
      count = 0;
      for(j=i; j<src.length() && src[j]==org; j++){
          count ++;
      }
     
          string temp = "";
          itos(temp, count);
          src = src.substr(0, i+1) + temp + src.substr(j, src.length()-j);
      
      
      i= i + temp.length() + 1;
      
  }
  
  return src;
}     
 
