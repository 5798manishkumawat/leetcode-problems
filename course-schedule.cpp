
Problem Link - https://leetcode.com/problems/course-schedule/

Solution------

class Solution {
public:
    
    vector<int>arr[100000];
    bool visit[100000];
    bool rec[100000];
    bool dfs(int v)
    {
        if(visit[v] == false) 
        { 
            visit[v] = true; 
            rec[v] = true; 

            for(auto i = arr[v].begin(); i != arr[v].end(); ++i) 
            { 
                if ( !visit[*i] && dfs(*i) ) 
                    return true; 
                else if (rec[*i]) 
                    return true; 
            } 

        } 
        rec[v] = false; 
        return false; 
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(int i=0;i<prerequisites.size();i++)
        {
            int x=prerequisites[i][0];
            int y=prerequisites[i][1];
            
            //arr[x].push_back(y);
            arr[y].push_back(x);
        }
        
        for(int i = 0; i <numCourses; i++)
        {
            memset(visit,false,sizeof(visit));
            memset(rec,false,sizeof(rec));
            if (dfs(i)) 
			return false;
        }
		 
        return true;
    }
};
