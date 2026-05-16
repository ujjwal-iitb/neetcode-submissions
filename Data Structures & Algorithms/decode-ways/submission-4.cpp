class Solution {
public:
    int getInt(int start, int end, string s){
        return stoi(s.substr(start, end - start +1));
    }

    int numDecodings(string s) {
        int n = s.length();
        if(s[0]=='0' || (n>1 && s[1]=='0' && getInt(0, 1, s)>26)){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            if(s[1]=='0' || getInt(0, 1, s)>26){
                return 1;
            }
            else return 2;
        }

        int a = 1, b, c;

        if(s[1]=='0' || getInt(0, 1, s)>26){
            b = 1;
        }
        else{
            b = 2;
        }

        for(int i = 2; i<n; i++ ){
            int n_1 = 0; 
            if(s[i]=='0'){
                n_1 = 0;
            }
            else{
                n_1 = b;
            }

            int n_2 = 0;
            if(s[i-1]=='0' || getInt(i-1, i, s) > 26){
                n_2 = 0;
            }
            else{
                n_2 = a;
            }

            c = n_1 + n_2;
            a = b;
            b = c;
        }

        return c;
    }
};
