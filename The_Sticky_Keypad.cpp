    #include <bits/stdc++.h>
    using namespace std;
    
    string helper(string temp, int b){
        int sz = temp.size();
        char d = char('0' + b);
        int pos = -1;
        for(int i = 0; i<sz; i++){
            if(temp[i] == d){
                pos = i;
                break;
            }
        }
        if(pos==-1) return temp;
        for(int j = pos + 1; j<sz; j++){
            if(b==0) temp[j] = '1';
            else temp[j] = '0';
        }
        while(pos>=0){
            int digit = temp[pos] - '0' + 1;

            while (digit <= 9 && digit == b)
                digit++;
        
            if (digit <= 9) {
                temp[pos] = char('0' + digit);
                return temp;
            }
            else {
                temp[pos] = '0';
                pos--;
            }
        }
        if(pos==-1 && temp[0]=='0') return "1"+temp;
        return temp;
        
    }
    
    int main() {
    	// your code goes here
        int t;
        cin>>t;
        while(t--){
            int a, b;
            cin>>a>>b;
            string temp = to_string(a);
            cout<<helper(temp, b)<<endl;
            
        }
    }
