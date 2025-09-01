#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */
struct TrieNode {
    TrieNode* children[10] = {nullptr};
    bool isEnd = false;
};
void noPrefix(vector<string> words) {
      TrieNode* root = new TrieNode();
    for (auto &word : words) {
        TrieNode* curr = root;
        for (int i = 0; i < (int)word.size(); i++) {
            int idx = word[i] - 'a';
            if (!curr->children[idx]) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
            if (curr->isEnd) {
                cout << "BAD SET\n" << word << "\n";
                return;
            }
        }
        for (int j = 0; j < 10; j++) {
            if (curr->children[j]) {
                cout << "BAD SET\n" << word << "\n";
                return;
            }
        }
        curr->isEnd = true;
    }
    cout << "GOOD SET\n";

}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
