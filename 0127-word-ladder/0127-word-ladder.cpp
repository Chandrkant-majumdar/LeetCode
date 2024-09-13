class Solution {
public:


        int ladderLength(string bw, string ew, vector<string>& wl){
                queue<pair<string,int>>q;
                q.push({bw,0});
                unordered_set<string>s(wl.begin(),wl.end());
                while(!q.empty()){
                    string word=q.front().first;
                    int step=q.front().second;
                    q.pop();
                    if(word==ew) return step+1;
                    for(int i=0;i<word.size();i++){
                        char c=word[i];
                        for(char t='a';t<='z';t++){
                            word[i]=t;
                            if(s.find(word)!=s.end()){
                                s.erase(word);
                                q.push({word,step+1});
                            }

                        }
                        word[i]=c;
                    }
                }
                return 0;
        }




    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //     queue<pair<string,int>>q;
    //     q.push({beginWord,1});
    //     unordered_set<string>s(wordList.begin(),wordList.end());
    //     s.erase(beginWord);
    //     while(!q.empty()){
    //         string word=q.front().first;
    //         int step=q.front().second;
    //         q.pop();
    //         if(word==endWord){
    //             return step;
    //         }
    //         for(int i=0;i<word.size();i++){
    //             char o=word[i];
    //             for(char ch='a';ch<='z';ch++){
    //                 word[i]=ch;
    //                 if(s.find(word)!=s.end()){
    //                     s.erase(word);
    //                     q.push({word,step+1});
    //                 }
    //             }
    //             word[i]=o;
    //         }
    //     }
    //     return 0;
    // }
};