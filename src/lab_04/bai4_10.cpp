/***Xây dựng một máy tìm kiếm (search engine) đơn giản.
Cho  𝑁  văn bản và  𝑄  truy vấn. Với mỗi truy vấn, cần trả về văn bản khớp với truy vấn đó nhất.
Sử dụng phương pháp tính điểm TF-IDF:
𝑓(𝑡,𝑑)  là số lần xuất hiện của từ  𝑡  trong văn bản  𝑑 
𝑚𝑎𝑥𝑓(𝑑)  là giá trị lớn nhất của  𝑓(𝑡,𝑑)  với mọi  𝑡 
𝑑𝑓(𝑡)  là số văn bản chứa từ  𝑡 
𝑇𝐹(𝑡,𝑑)=0.5+0.5⋅𝑓(𝑡,𝑑)𝑚𝑎𝑥𝑓(𝑡,𝑑) 
𝐼𝐷𝐹(𝑡)=𝑙𝑜𝑔2(𝑁𝑑𝑓(𝑡)) 
Điểm số của từ  𝑡  trong văn bản  𝑑  là  𝑠𝑐𝑜𝑟𝑒(𝑡,𝑑)=𝑇𝐹(𝑡,𝑑)⋅𝐼𝐷𝐹(𝑡) , nếu từ  𝑡  không xuất hiện trong văn bản  𝑑  thì  𝑠𝑐𝑜𝑟𝑒(𝑡,𝑑)=0 .
Điểm số của văn bản  𝑑  đối với truy vấn gồm các từ (có thể trùng nhau)  𝑡1,𝑡2,...,𝑡𝑞  là  ∑𝑞𝑖=1𝑠𝑐𝑜𝑟𝑒(𝑡𝑖,𝑑) 
Ta coi văn bản có điểm số càng cao thì càng khớp với truy vấn.
Input:
Dòng đầu tiên chứa số  𝑁 
Dòng thứ  𝑖  trong  𝑁  dòng tiếp theo thể hiện văn bản  𝑖 , mỗi dòng là một dãy các từ ngăn cách nhau bởi dấu phẩy
Dòng tiếp theo chứa số  𝑄 
Dòng thứ  𝑖  trong  𝑄  dòng tiếp theo thể hiện truy vấn thứ  𝑖 , mỗi dòng là một dãy các từ ngăn cách nhau bởi dấu phẩy
Output: Gồm  𝑄  dòng, dòng thứ  𝑖  là chỉ số của văn bản khớp với truy vấn thứ  𝑖  nhất. Nếu có nhiều văn bản có điểm số bằng nhau, in ra văn bản có chỉ số nhỏ nhất.
Ví dụ:
Input:
5
k,k,ow
bb,ar,h
qs,qs,qs
d,bb,q,d,rj
ow
5
h,d,d,qs,q,q,ar
qs,qs
hc,d,ow,d,qs
ow,wl,hc,k
q,hc,q,d,hc,q
Output:
4
3
4
1
4
Giới hạn:
𝑁≤1000 
𝑄≤1000 
Số từ trong mỗi văn bản không quá  1000 
Số từ trong mỗi truy vấn không quá  10 
Độ dài mỗi từ không quá  10 
 */

#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int n, q;
vector<vector<string>> texts; 
vector<vector<string>> queries; 
map<pair<string, int>, int> word_frequency; 
vector<int> max_frequency; 
map<string, int> document_frequency; 

// split string by ','
inline vector<string> splitByComma(const string &s) {
    vector<string> result; // result
    string current_word;
    for (char ch : s) {
        if (ch != ',') {
            current_word.push_back(ch); // add to current_word or current_word += ch
        } else {
            result.push_back(current_word); // add current_word to vector result
            current_word.clear(); // reset current_word
        }
    }
    result.push_back(current_word); // add last word
    return result; // return result
}

inline void readInput() {
    cin >> n; // input n
    for (int i = 0; i < n; ++i) {
        string text; // allocate
        cin >> text; // get text string
        texts.push_back(splitByComma(text)); // split and add to texts
    }
    cin >> q; // input q
    for (int i = 0; i < q; ++i) {
        string query; // allocate
        cin >> query; // get query string
        queries.push_back(splitByComma(query)); // split and add to queries
    }
}

inline void calculateWordFrequency() {
    for (int i = 0; i < n; ++i) {
        int max_word_count = 0; // max frequency for text[i]
        for (auto &word : texts[i]) {
            pair<string, int> key = make_pair(word, i); // key : word @word in text[i]
            if (word_frequency.find(key) != word_frequency.end()) { // check if key exists
                ++word_frequency[key]; // increase frequency
            } else {
                word_frequency[key] = 1; // set initial frequency
            }
            max_word_count = max(max_word_count, word_frequency[key]); // update maximum frequency
        }
        max_frequency.push_back(max_word_count); // store maximum frequency for text[i]
    }
}

inline int calculateDocumentFrequency(const string& word) {
    if (document_frequency.find(word) != document_frequency.end()) { // check if word exists
        return document_frequency[word]; // return cached result
    }

    int count = 0; // result for document frequency
    for (int i = 0; i < n; ++i) {
        for (string &s : texts[i]) {
            if (word == s) {
                ++count; // increase count
                break;
            }
        }
    }
    document_frequency[word] = count; // cache the result
    return count; // return result
}

inline double computeScore(const string& word, int text_index) {
    if (word_frequency[{word, text_index}] == 0) return 0; // no occurrence, score is 0
    return (0.5 + 0.5 * word_frequency[{word, text_index}] / max_frequency[text_index]) * log2(n / calculateDocumentFrequency(word));
}

inline int findBestMatchingText(const vector<string>& query_words) {
    int best_index = -1; // result
    double highest_score = -1; // maximum score
    for (int i = 0; i < n; ++i) {
        double current_score = 0; // current score for text[i]
        for (auto &word : query_words) {
            current_score += computeScore(word, i); // calculate and accumulate score for text[i]
        }

        if (current_score > highest_score) { // check if new maximum score
            highest_score = current_score; // update highest score
            best_index = i; // update best index
        }
    }
    return best_index + 1; // return the 1-based index
}

int main() {
    readInput(); // read input data
    calculateWordFrequency(); // pre-calculate word frequencies
    for (auto &query : queries) {
        cout << findBestMatchingText(query) << endl; // print best matching text index for each query
    }

    return 0;
}
