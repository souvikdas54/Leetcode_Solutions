//Find all anagrams in a string given a pattern

#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

vector<int> anagrams(string s,string p){
    vector<int> sv(26,0),pv(26,0),res;
    if(p.size()>s.size())     //base case
        return res;
    for(int i =0;i<p.size();i++){
        ++sv[s[i]-'a'];
        ++pv[p[i]-'a'];
    }
    if(pv==sv)
        res.push_back(0);
    for(int i=p.size();i<s.size();i++){
        ++sv[s[i]-'a'];
        --sv[s[i-p.size()]-'a'];
        if(sv==pv)            //This comparison happens in O(1) time
            res.push_back(i-p.size()+1);
    }
    return res;
}

int main()
{
    string s = "abcaskwqwmdoqdmqowdjqowdjqwjdoqwdjoas";
    string p = "owd";
    vector<int> result = anagrams(s,p);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
