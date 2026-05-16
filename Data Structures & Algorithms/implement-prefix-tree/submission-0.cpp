struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char c){
        return links[c - 'a'] != NULL;
    }

    void put(char c, Node *node){
        links[c-'a'] = node;
    }

    Node* get(char c){
        return links[c - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};


class PrefixTree {

    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(int i = 0; i<word.length(); i++){
            if(!temp->containsKey(word[i])){
                Node* newNode = new Node();
                temp->put(word[i], newNode);
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }
    
    bool search(string word) {
        Node* temp = root;

        for(int i = 0; i<word.length(); i++){
            if(!temp->containsKey(word[i])){
                return false;
            }
            temp = temp->get(word[i]);
        }
        return temp->isEnd();

    }
    
    bool startsWith(string prefix) {
        Node* temp = root;

        for(int i = 0; i<prefix.length(); i++){
            if(!temp->containsKey(prefix[i])){
                return false;
            }
            temp = temp->get(prefix[i]);
        }
        return true;
    }
};
