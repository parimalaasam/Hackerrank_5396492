#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
       unordered_map<char, int> charmap;

    for (char c : s) {
        ++charmap[c];
    }

    unordered_map<int, int> freqmap;

        for (const auto& pair : charmap) {
        ++freqmap[pair.second];
    }

    if (freqmap.size() == 1) {
        return "YES";
    } else if (freqmap.size() == 2) {
        vector<pair<int, int>> freqPairs(freqmap.begin(), freqmap.end());

        int freq1 = freqPairs[0].first, count1 = freqPairs[0].second;
        int freq2 = freqPairs[1].first, count2 = freqPairs[1].second;

        int keyOfMoreFrequentLetter = (count1 > count2) ? freq1 : freq2;
        int keyOfLessFrequentLetter = (count1 > count2) ? freq2 : freq1;
        int countOfLessFrequent = (count1 > count2) ? count2 : count1;

        if (countOfLessFrequent == 1 && (keyOfLessFrequentLetter - 1 == keyOfMoreFrequentLetter || keyOfLessFrequentLetter - 1 == 0)) {
            return "YES";
        } else {
            return "NO";
        }
    } else {
        return "NO";
    }
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
