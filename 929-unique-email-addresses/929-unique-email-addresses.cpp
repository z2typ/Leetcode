class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        unordered_set<string> uset;
        
        for(string email : emails){
            string em = "";
            for(int i=0; i<email.length();i++){
                if(email[i]=='.'){
                    continue;
                }else if(email[i]=='+' || email[i]=='@'){
                    break;
                }else{
                    em += email[i];
                }
            }
            em += email.substr(email.find('@'));
            uset.insert(em);
        }
        return uset.size();
    }
};