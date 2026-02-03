class node{
  public:
    int data;
    int row;
    int col;
    
    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
  public:
    bool operator()(node a, node b){
        return a.data > b.data;
    }
};


class Solution {
  public:
    vector<int> smallestRange(vector<vector<int>>& mat) {
        vector<int> ans;
        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<node, vector<node>, compare> minHeap;
        
        int k = mat.size();
        
        for(int i=0; i<k; i++){
            int element = mat[i][0];
            maxi = max(maxi, element);
            minHeap.push(node(element, i, 0));
        }
        
        mini = minHeap.top().data;
        
        int start = mini, end = maxi;
        while(!minHeap.empty()){
            
            node top = minHeap.top();
            minHeap.pop();
            
            mini = top.data;
            
            if(maxi-mini < end-start){
                start = mini;
                end = maxi;
            }
            
            if(top.col + 1 < mat[top.row].size()) {
                int element = mat[top.row][top.col + 1];
                maxi = max(maxi, element);
                minHeap.push(node(element, top.row, top.col + 1));
            } else {
                break;
            }
        }
        
        ans.push_back(start);
        ans.push_back(end);
        
        return ans;
    }
};