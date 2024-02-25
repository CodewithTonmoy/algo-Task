briefing: Let's say we have the text "hello world".
We count the frequency of each character: h: 1, e: 1, l: 3, o: 2, w: 1, r: 1, d: 1.
We construct the Huffman tree with characters and their frequencies.
We assign Huffman codes to each character based on the tree.
We replace each character in the original text with its corresponding Huffman code.
The compressed text might look something like "0101101101000111000110100011011"

#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

// A Huffman tree node
struct MinHeapNode {
    char data;
    unsigned frequency;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned frequency) {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// Comparison function for priority queue
struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->frequency > r->frequency);
    }
};

// Traverse Huffman tree and store codes in a map
void encodeHuffman(MinHeapNode* root, string str, map<char, string>& codes) {
    if (!root)
        return;

    // If the node is a leaf node
    if (!root->left && !root->right) {
        codes[root->data] = str;
    }

    // Traverse left
    encodeHuffman(root->left, str + "0", codes);
    // Traverse right
    encodeHuffman(root->right, str + "1", codes);
}

// Build Huffman tree and encode
map<char, string> buildHuffmanTree(string text) {
    map<char, unsigned> freq;
    // Calculate frequency of each character
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a priority queue to store nodes
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> pq;

    // Create a node for each character and add it to the priority queue
    for (auto pair : freq) {
        pq.push(new MinHeapNode(pair.first, pair.second));
    }

    // Build Huffman tree
    while (pq.size() != 1) {
        MinHeapNode *left = pq.top();
        pq.pop();

        MinHeapNode *right = pq.top();
        pq.pop();

        unsigned sum = left->frequency + right->frequency;
        pq.push(new MinHeapNode('$', sum));
    }

    MinHeapNode* root = pq.top();

    // Traverse the Huffman tree and store codes
    map<char, string> codes;
    encodeHuffman(root, "", codes);

    return codes;
}

int main() {
    string text = "hello world";
    
    // Build Huffman tree and get codes
    map<char, string> codes = buildHuffmanTree(text);

    // Print the Huffman codes
    cout << "Huffman Codes:\n";
    for (auto pair : codes) {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}
