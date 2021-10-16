#include<bits/stdc++.h>
using namespace std;



int pre[10000];
void computeLPSArray(int m,string s){
    memset(pre,0,sizeof(pre));
    int temp = 0;
    int j = 0;
    for(int i =0;i<m;i++){
        if(i == temp){
            pre[i] = i;
            continue;
        }
        if(s[i] == '*'){
            temp = i+1;
            j = temp;
            continue; 
        }
        if(s[i] == s[j]){
            j++;
            pre[i] = j;
        }else{
            if(j == temp) pre[i] = temp;
            else {j = pre[j-1];i--;}
        }
    }
}

void KMPSearch(int n,int m,string s,string t){
    computeLPSArray(m,s);
    int i = 0, j = 0, temp = 0;
    int ans = -1;
    temp = 0;
    bool res = false;
    while(i < n){
        if(s[j] == t[i]){
            i++;
            j++;
        }else{
            if(s[j] == '*'){
                if(ans == -1) ans = i-j+temp;
                j++;
                temp = j;
            }
            else if(j == temp) i++;
            else j = pre[j-1];
        }
        if(j == m){
            if(!res){
                cout << "YES\n";
                res = true;
            }
            if(ans == -1) ans = i - m;
            cout << "LOC : " << ans << "\n";
            ans = -1;
            temp = 0;
            j = 0;
        }
    }
    if(!res) cout << "NO\n";
}

int main(){
    string t,s;
    cout << "Enter Text: ";
    getline(cin,t);
    cout << "Enter Pattern: ";
    cin  >> s;
    int n = t.length(), m = s.length();
    KMPSearch(n,m,s,t);    
}