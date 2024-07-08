class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;

        stringstream obj(path);
        string temp;

        while(getline(obj,temp,'/')){
            if(temp == "." || temp == "" ){
                continue;
            }
            else if(temp == ".."){
                if(dir.size()) dir.pop_back();
            }
            else dir.push_back(temp);
        }
        string ans = "";
        
        for(auto it : dir){
            ans = ans + "/" + it;
        }
        return ans.size() == 0 ? "/" : ans;
    }
};