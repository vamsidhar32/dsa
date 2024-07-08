class Solution {
public:
    string simplifyPath(string path) {
        //vector<string> dir;
        
        string ans = "";

        stringstream obj(path);
        string temp;

        while(getline(obj,temp,'/')){
            if(temp == "." || temp == "" ){
                continue;
            }
            else if(temp == ".."){
                if(ans.size()){
                    for(int i = ans.size()-1; i >=0; i--){
                        if(ans[i] == '/'){
                            ans.pop_back();
                            break;
                        }
                        ans.pop_back();
                    }
                }
            }
            else{
                ans = ans+"/"+ temp;
            }
        }
        
        
        
        return ans.size() == 0 ? "/" : ans;
    }
};