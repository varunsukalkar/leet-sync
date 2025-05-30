class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();



        vector<int> vec1(n,-1);
        vector<int>vec2(n,-1);
        vec1[node1]=0;
        vec2[node2]=0;
        int dist = 0;
        int i = node1;
        while(true){
            vec1[i]=dist++;
            i = edges[i];
            if(i==-1 || vec1[i]!=-1){
                break;
            }
        }
        int dist2 = 0 ;
        i = node2;
        while(true){

            vec2[i]= dist2++;
            i  = edges[i];
            if(i==-1 || vec2[i]!=-1){
                break;
            }
        }
        int mini = INT_MAX;
        int ans =-1;
        for(int i =0 ; i< n; i++){
            if(vec1[i]==-1 || vec2[i]==-1){
                continue;
            }
            if(mini> max(vec1[i],vec2[i])){
                mini = max(vec1[i],vec2[i]);
                ans = i;
            }

            
        }
        return ans;
    }
};