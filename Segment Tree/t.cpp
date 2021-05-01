#define pii pair<int,int> 

class Task{
    public:
        int jid;
        int st; 
        int dur; 
        Task(int jid, int st, int dur) : jid(jid), st(st),dur(dur){} 
}; 
vector<Task> task; 

bool compStart(const Task &a, const Task &b){
    if(a.st == b.st) return a.jid < b.jid; 
    return a.st < b.st; 
}
class compDur{
    bool operator() (Task &a, Task &b){
        if(a.dur == b.dur) return a.jid > b.jid; 
        return a.dur > b.dur; // kam duration pehle, par pq ka hisaab ulta hota hai 
    }
};

vector<int> solve(vector<vector<int>>& tasks) {
    task.clear(); 
    int n = tasks.size(); 
    for(auto t : tasks) task.emplace_back(t[0],t[1],t[2]); 
    sort(task.begin(),task.end(),compStart); 

    priority_queue<Task,vector<Task>,compDur> pq; 
    vector<int> ans; 

    int mnTime = task[0].st; 

    int i = 0; 
    while(i < n && task[i].st <= mnTime){
        pq.emplace(task[i]); 
    }

    while(i < n){  /* or maybe something else */ 
        if(pq.empty()) break; 
        auto curr = pq.top(); 
        pq.pop(); 
        ans.emplace_back(curr.jid); 
        i++;
        int curr_end = curr.st + curr.dur;  
        while(i < n && task[i].st <= curr_end){
            pq.emplace(task[i]); 
            i++; 
        }
    }

    return ans; 
}   