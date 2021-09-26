class Solution {
public:
    struct Node1{
        int w,id,tm;//w为权置
        bool operator< (const Node1& t) const{
            if(tm != t.tm){
                return tm > t.tm;
            }
            if(w != t.w){
                return w > t.w;
            }
            return id > t.id;
        }
    };//用来保存忙碌状态的服务器，按照完成时间早、权值小、服务器序号小的顺序排

    struct Node2{
        int w,id,tm;
        bool operator< (const Node2& t) const{
            if( w != t.w){
                return w>t.w;
            }
            return id > t.id;
        }
    };//用来保存空现状态的服务器，按照权值小、服务器序号小排

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
            priority_queue<Node1> heap1;//忙碌的
            priority_queue<Node2> heap2;//空闲的

            for(int i = 0; i < servers.size(); i++){
                heap2.push({servers[i],i,0});
            }//先把所有的服务器放到空闲堆里
            vector<int> res;
            for(int i = 0; i < tasks.size(); i++){//i时刻第i个任务到来,i = 0,1,2....
                while(heap1.size() && heap1.top().tm <= i){//忙碌堆里已经有任务做完了
                                                           //可以转到空闲堆里
                    auto t = heap1.top();
                    heap2.push({t.w,t.id,t.tm});
                    heap1.pop();
                }
                if(heap2.size()){
                    auto t = heap2.top();
                    heap2.pop();
                    res.push_back(t.id);
                    heap1.push({t.w,t.id,i+tasks[i]});
                }else{
                    auto t = heap1.top();
                    heap1.pop();
                    res.push_back(t.id);
                    heap1.push({t.w,t.id,t.tm+tasks[i]});
                }
            }

            return res;
    }
};