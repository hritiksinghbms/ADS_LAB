#include <bits/stdc++.h>
using namespace std;
struct Trie {
	bool isEndOfWord;
	unordered_map<char, Trie*> map;
	string meaning;
};
Trie* getNewTrieNode()
{
	Trie* node = new Trie;
	node->isEndOfWord = false;
	return node;
}
void insert(Trie* &root, const string &str,const string &meaning)
{
	if (root == NULL)
		root = getNewTrieNode();
	Trie* temp = root;
	for (int i=0;i<str.length();i++){
		char x = str[i];
		if (temp->map.find(x) == temp->map.end())
			temp->map[x] = getNewTrieNode();
		temp = temp->map[x];
	}
	temp->isEndOfWord = true;
	temp->meaning = meaning;
}
string getMeaning(Trie* root, const string& word)
{
	if (root == NULL)
		return "";
	Trie* temp = root;
	for (int i=0;i<word.length();i++){
		temp = temp->map[word[i]];
		if (temp == NULL)
			return "";
	}
	if (temp->isEndOfWord)
		return temp->meaning;
	return "";
}
int main()
{
	Trie* root = NULL;
    string str, meaning;
    int ch;
	for(;;){
	    cout<<"\n1.Input\n2.Search\n3.Exit..\n";
	    cin >> ch;
	    switch(ch){
	        case 1: cin >> str;
	            cin >> meaning;
	            insert(root,str,meaning);
	            break;
	        case 2: cin >> str;
	            cout << getMeaning(root, str);
	            break;
	        case 3:exit(0);
	        default:cout<<"Enter proper instructions\n";
	    }
	}
	return 0;
}
