// strings in c++: 1 dimensional char array

// NULL character: '\0' store at the end of STRING and CHAR arrays (to know where string ends), ASCII Value:0

// cin execution stops: When we give SPACE:' ', TAB:'\t' & new line character (ENTER):'\n'

// cout prints the string when it gets first null character

// Key differences between string and char array


// cin.getline(): To read line 

// custom delimeter

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

// Length of a string

int getLenth(char c[]){
    int count=0;
    for(int i=0;c[i]!='\0';i++){
        count++;
    }

    return count;
}

// Reverse the string

void reverseString(string& s){
    int start=0,end=s.length()-1;

    while(start<end){
        char c=s[start];
        s[start]=s[end];
        s[end]=c;
        start++;
        end--;
    }
}

// Check if a string is palindrome

bool checkPalindrome(string s){
    int start=0,end=s.size()-1;
    while(start<end){
        if(s[start++]!=s[end--])
        return false;
    }

    return true;
}

// consider alphabets & numbers only. Ignore white spaces and symbols. NOT Case Sensitive

string removeExtraSymbols(string s){
    
    string temp="";
    for(int i=0;i<s.length();i++){
        if((s[i]>='A' && s[i]<='Z')|| (s[i]>='a' && s[i]<='z')|| (s[i]>='0' && s[i]<='9')){
            temp.push_back(s[i]);
        }     
    }

    return temp;
}

char toLowerCase(char ch){

    if((ch>='a' && ch <='z')||(ch>='0' && ch<='9')) // number form: ch-'0'
    return ch;
    else
    return ch-'A'+'a';
}

bool checkSpecialPalindrome(string s){
    string temp=removeExtraSymbols(s);

    cout<<temp<<endl;
    int start=0,end=temp.size()-1;
    while(start<end){
        if(toLowerCase(temp[start])!=toLowerCase(temp[end]))
        return false;

        start++;
        end--;
    }

    return true;
}


// Reverse Words in String 2, Solve it in place and words is separated by single space in s

// Input: s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
// Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]

void reverseWords(vector<char>& s){
    reverse(s.begin(),s.end());

    int start=0,n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            reverse(s.begin()+start,s.begin()+i);
            start=i+1;
        }

    }
    reverse(s.begin()+start,s.end());
}

// Return maximum occuring character in a string

char getMaxOccurCharacter(string s){
    int arr[26]={0};

    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z'){
            arr[s[i]-'a']++;
        }else if(s[i]>='A' && s[i]<='Z'){
            arr[s[i]-'A']++;
        }
    }

    int maxi,index;

    for(int i=0;i<26;i++){
        if(maxi<arr[i]){
            index=i;
            maxi=arr[i];
        }
    }

    return 'a'+index;

}


// Replace spaces with @40
// can be done in place as well by counting number of spaces and initialize new length and iterate from backwards

string replaceSpaces(string &str){
    string temp="";

    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');

        }else{
            temp.push_back(str[i]);
        }
    }

    return temp;
}


// Remove all occurences of a substring
// Find the leftmost occurrence of the substring part and remove it from s.

// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"

string removeOccurencies(string s, string part){

    while(s.length()!=0 && s.find(part)<s.length()){
        s.erase(s.find(part),part.length());
    }

    return s;

}

// Permutation in a String

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

bool checkEqual(int a[], int b[]){

    for(int i=0;i<26;i++){
        if(a[i]!=b[i])
        return false;
    }

    return true;
}

bool checkInclusion(string s1,string s2){
    int arr[26]={0};
    
    // character count array
    for(int i=0;i<s1.length();i++){
        arr[s1[i]-'a']++;
    }

    // traverse s2 string in window of size s1 length & compare
    int j=0,b[26]={0};
    int windowSize=s1.length();

    while(j<windowSize && j<s2.length()){
        b[s2[j]-'a']++;
        j++;
    }
   
        
    
    if(checkEqual(arr,b))
    return true;
    else{
        int start=0;
        while(j<s2.length()){
            b[s2[j]-'a']++;
            b[s2[start]-'a']--;
            
            if(checkEqual(arr,b))
            return true;

            j++;
            start++;

        }

    }

    return true;
}

// Remove all adjacent duplicates in a string. A duplicate removal consists of choosing two adjacent and equal letters and removing them.We repeatedly make duplicate removals on s until we no longer can.

// Input: s = "abbaca"
// Output: "ca"

string removeDuplicates(string s){

    int i=0;

    while(i<s.length()-1){
        if(s[i]==s[i+1]){
            s.erase(s.begin()+i,s.begin()+i+2);
            // cout<<"Hi:  "<<s<<endl;
            i=0;
            
        }else{
            i++;
        }

    }

    return s;
}


// Use STACK data dtructure to use an output stack to keep track of only non duplicate characters

string removeDuplicates1(string s){
    stack<char> st;
    st.push(s[0]);
    int i=0;
    while(i<s.length()){
        cout<<i<<endl;
        if(st.top()==s[i]){
            st.pop();
            s.erase(s.begin()+i-1,s.begin()+i+1);
            // i--;
             cout<<s<<"  "<<i<<endl;
        }
        else{
            cout<<"ff"<<i<<endl;
            st.push(s[i]);
            i++;
        }
    }
return s;

}

// String Compression: Store answer inplace
int compress(vector<char> &chars){

    int i=0;
    int count=0,ansIndex=0;

    while(i<chars.size()-1){
        if(chars[i]==chars[i+1]){
            count++;
            i++;
        }else{
            if(count==1){
                ans+=1;
            }
            else{
                int digit=0;
                while(count>0){
                    digit++;
                    count=count/10;
                }
                ans+=digit+1;
                count=1;
            }
            i++;
        }
    }

    return ans;

}

int main(){
    // char name[20];
    // cin>>name;
   
    string s="azxxzy";
    
    // cin>>s;
    // cout<<s<<endl;
    // vector<char> v(s.begin(),s.end());

    // reverseWords(v);

    // for(int i=0;i<v.size();i++)
    // cout<<v[i];

    cout<<removeDuplicates1(s)<<endl;

    return 0;
}