class Solution {
public:

    void reverse(int i , int j ,string &word){
        while(i < j){
            char temp = word[i];
            word[i] = word[j];
            word[j]= temp;
            i++;
            j--;
        }

    }
    string reversePrefix(string word, char ch) {
        for(int i = 0 ; i <word.size();i++){
            if(word[i] == ch){
                reverse(0,i,word);
                break;
            }
        }

        return word;
    }
};