#include <string> 
#include <vector> 
#include <queue> 

using namespace std; 

int solution(string begin, string target, vector<string> words) { 
    int N = words.size(); 
    int M = begin.size(); 
    vector<int> visit(N, 0); 
    queue<pair<string, int>> q; 
    q.push({begin, 0}); 
    
    int answer = 0; 
    while (!q.empty()) { 
        string start = q.front().first; 
        int count = q.front().second; 
        q.pop(); 
        
        for (int i = 0; i < N; i++) { 
            int diff = 0; 
            if (visit[i] != 0) continue; 
            for (int j = 0; j < M; j++) { 
                if (start[j] != words[i][j]) diff++; 
            } 
            if (diff == 1) { 
                if (words[i] == target) return count + 1; 
                visit[i] = 1; 
                q.push({words[i], count + 1}); 
            } 
        } 
    } 
    return answer; 
}
