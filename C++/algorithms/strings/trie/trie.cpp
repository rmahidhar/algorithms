//
// Created by mahidhar.ramesh on 11/15/2017.
//

#include <map>
#include <iostream>
#include <vector>

class Trie {
private:

    struct Node;

    typedef std::map<char, Node*> TrieChildrenType;

    struct Node {
        Node(char c, bool is_leaf) : letter(c), leaf(is_leaf) {
        }

        char letter;
        bool leaf;
        TrieChildrenType children;
    };

    Node *m_root;

public:

    Trie() {
        m_root = new Node('\0', false);
    }

    void insert(const std::string& word) {
        Node* node = m_root;
        for (auto letter : word) {
            auto iter = node->children.find(letter);
            if (iter != node->children.end()) {
                node = iter->second;
            } else {
                Node* new_node = new Node(letter, false);
                node->children.insert(std::pair<char, Node*>(letter, new_node));
                node = new_node;
            }
        }
        node->leaf = true;
    }

    bool search(const std::string& word) {
        Node* node = m_root;
        for (auto letter : word) {
            auto iter = node->children.find(letter);
            if (iter != node->children.end()) {
                node = iter->second;
            } else {
                node = nullptr;
                break;
            }
        }
        return node != nullptr && node->leaf;
    }

    bool startsWith(const std::string& word) {
        Node* node = m_root;
        for (auto letter : word) {
            auto iter = node->children.find(letter);
            if (iter != node->children.end()) {
                node = iter->second;
            } else {
                node = nullptr;
                break;
            }
        }
        return node != nullptr;
    }

};


int main(int argc, char* argv[]) {
    std::vector<std::string> strings = {"MIT", "Harvard", "Stanford", "Princeton"};
    Trie trie;
    for (const std::string& word : strings) {
        trie.insert(word);
    }

    std::cout << "MIT: " << trie.search("MIT") << std::endl;
    std::cout << "Harvard: " << trie.search("Harvard") << std::endl;
    std::cout << "Stanford: " << trie.search("Stanford") << std::endl;
    std::cout << "Princeton: " << trie.search("Princeton") << std::endl;
    std::cout << "IIT: " << trie.search("IIT") << std::endl;
    std::cout << "Prince: " << trie.search("Prince") << std::endl;
    std::cout << "Princes: " << trie.search("Princes") << std::endl;
    std::cout << "Har:" << trie.startsWith("Har") << std::endl;
    std::cout << "Stan: " << trie.startsWith("Stan") << std::endl;
    std::cout << "Prince: " << trie.startsWith("Prince") << std::endl;

}