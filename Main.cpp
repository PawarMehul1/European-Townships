#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include <fstream>
#include <string>

using namespace std;


int strtoint(string str)
{
    int ans=0;

    for(int i=0; i<str.length(); i++)
    {
        ans*=10;
        ans+=(int)(str[i])-48;
    }

    return ans;
}
vector<int> splitnumbers(string str)
{
    vector<int> ans;
    int n=str.length();

    int index=0;
    while(index<n)
    {
        string tmp="";
        while(index<n && str[index]!=',')
        {
           tmp+=str[index++]; 
        }
        index++;

        ans.push_back(strtoint(tmp));
    }
    return ans;
}
string inttostring(int n)
{
    if(n==0)
        return "0";
    string ans="";

    while(n>0)
    {
        ans=(char)(48+(n%10))+ans;
        n/=10;
    }

    return ans;
}
string dobletostr(double d)
{
    string ans="";

    int n=(int)(d);

    while(n>0)
    {
        ans=(char)(48+(n%10))+ans;
        n/=10;
    }

    
    d-=(double)((int)(d));
    if(d!=0)
        ans+='.';

    while(d!=0)
    {
        d*=10;
        n=(int)(d);

        ans+=(char)(48+n);
        d-=n;
    }
    return ans;

}
int main()
{
    fstream file;
    file.open("input.txt", ios::in);

    string str;
    getline(file,str);


    int T=strtoint(str);
    double ans[T][3];
    for(int i=0; i<T; i++)
    {
        getline(file,str);
        int N=strtoint(str);
        double sum=0;

        for(int j=0; j<N; j++)
        {
            double tmp=0;
            getline(file,str);
            vector<int> vals=splitnumbers(str);

            tmp+=vals[1]*3;

            tmp+=vals[2]*4;

            tmp+=vals[3]*6;
            
            if(tmp>sum)
                sum=tmp;
        }
        ans[i][0]=(sum/3)*(2.5)+(((sum*2)/3)*(3.25));
        ans[i][1]=(sum/3)*(1.5);
        ans[i][2]=((sum*2)/3)*(2.25);

    }

    file.close();

    ofstream OUTPUT("output.txt");
    
    for(int i=0; i<T; i++)
    {
        string line="Case #"+inttostring(i+1)+": ";

        line+=dobletostr(ans[i][0]);
        line+=" ";

        line+=dobletostr(ans[i][1]);
        line+=" ";

        line+=dobletostr(ans[i][2]);

        OUTPUT<<line<<endl;
    }
    OUTPUT.close();
    
    return 0;
}