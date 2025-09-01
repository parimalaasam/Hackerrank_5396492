#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <type_traits>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'componentsInGraph' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY gb as parameter.
 */
void dfs(int node,vector<vector<int>>& adj, vector<bool>&visited, int & component_size){
    visited[node]=true;
    component_size++;
    for(int nei:adj[node]){
        if(!visited[nei]){
            dfs(nei, adj, visited, component_size);
        }
    }
}
vector<int> componentsInGraph(vector<vector<int>> gb,int n) {
    vector<vector<int>> adj(2*n+1);
    for(const auto& edge:gb){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(2*n+1,false);
    vector<int> component_sizes;
    for(int i=1;i<=2*n;i++){
        if(!visited[i]){
            int component_size=0;
            dfs(i,adj,visited,component_size);
            if(component_size>1){
                component_sizes.push_back(component_size);
            }
        }
    }
    if(component_sizes.empty()){
        return {0,0};
    }
    int smallest = *min_element(component_sizes.begin(),component_sizes.end());
    int largest = *max_element(component_sizes.begin(),component_sizes.end());
    return {smallest,largest};

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> gb(n);

    for (int i = 0; i < n; i++) {
        gb[i].resize(2);

        string gb_row_temp_temp;
        getline(cin, gb_row_temp_temp);

        vector<string> gb_row_temp = split(rtrim(gb_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int gb_row_item = stoi(gb_row_temp[j]);

            gb[i][j] = gb_row_item;
        }
    }

    vector<int> result = componentsInGraph(gb,n);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
