#include <bits/stdc++.h>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Node {
    public:
        char data;
        int cost;
        Node* left;
        Node* right;
        Node(char data, int cost) :
            data(data), cost(cost), left(nullptr), right(nullptr) {}
};

bool compare(const Node *a, const Node *b) {
    return a->cost > b->cost;
}

class HuffmanCoder {
    private:
        // e.g. 
        // a -> 101011
        map<char, string> *encoder;
        map<string, char> *decoder;

    public:
        HuffmanCoder(string feeder = "") {
            map<char, int>freq;
            for(auto ch : feeder) {
                if(freq.count(ch)) {
                    freq[ch] += 1;
                }
                else {
                    freq[ch] = 1;
                }
            }
            //creating the min heap;
            priority_queue<Node*, vector<Node*>, decltype(&compare)>heap(compare);
            for(auto el : freq){
                Node* newN = new Node(el.first, el.second);
                heap.push(newN);
            }

            // remove 2 nodes from the heap
            while(heap.size() != 1) {
                Node *first = heap.top();
                heap.pop();
                Node *second = heap.top();
                heap.pop();

                Node *newN = new Node('\0', first->cost + second->cost);
                newN->left = first;
                newN->right = second;

                heap.push(newN);
            }

            auto finalNode = heap.top();
            heap.pop();

            encoder = new map<char, string>;
            decoder = new map<string, char>;
            initEncoderDecoder(finalNode, "");

        }
        void initEncoderDecoder(Node* node, string outputSoFar) {
            if(!node) 
                return;
            if(!node->left && !node->right) {
                encoder->insert({node->data, outputSoFar});
                decoder->insert({outputSoFar, node->data});
            }
            initEncoderDecoder(node->left, outputSoFar + "0");
            initEncoderDecoder(node->right, outputSoFar + "1");
        }

        string encode(string str) {
            string ans;
            for(auto ch : str) {
                ans += encoder->find(ch)->second;
            }
            return ans;
        }
        
        string decode(string codedStr) {
            string ans;
            string key;
            for(auto ch : codedStr) {
                auto it = decoder->find(key);
                if(it != decoder->end()) {
                    ans += it->second;
                    key.clear();
                }
                else
                    key += ch;
            }
            return ans;
        }
};


int main (int argc, char *argv[]) {
    string str = "aaabbce";
    HuffmanCoder hfc(str);

    auto res = hfc.encode(str);
    cout << res << endl;
    cout << hfc.decode(res) << endl;

    return 0;
}
