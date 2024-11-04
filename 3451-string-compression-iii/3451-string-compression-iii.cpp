class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int j = 0, count = 1;
        while(j < word.length()){

            while(word[j+1]  == word[j]){
                //expand window till repeating characters (max9)
                if( count == 9 ) break;
                count++;
                j++;
            }
            // append count + char for every iteration
            comp += to_string(count);
            comp += word[j];
            count = 1;
            j++;
        }
        return comp;
    }
};